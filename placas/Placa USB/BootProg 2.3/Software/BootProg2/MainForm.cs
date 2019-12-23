using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.IO;
using System.Text;

using UsbLibrary;

namespace BootProgUsb
{
	public partial class MainForm : Form
	{
		public enum Comandos
		{
 			NONE = 0,
 			INFO = 1,
 			REBOOT = 2,
 			WRITE = 3,
 			ERASE = 4 
		}
		
		//variaveis
		static byte[] HidWriteBuff = new byte[65];
		static byte[] StartProgramFunc = new byte[4];
		static bool StartProgramConfig = false;
		
		//Constantes
		const byte STX = 0x0F;
		const int CMD = 0x02;
		const int MCU_TYPE = 0x03;
		const int DEVICE_TYPE = 0x04;
		
		static HexFileReader ArquivoHexadecimal = new HexFileReader();
		public static Memory Flash = new Memory();
		public static Memory Eeprom = new Memory( 1024 );
		public static BootInfo bootInfo = new BootInfo();
		
		public MainForm()
		{
			InitializeComponent();
			
			this.UsbStatus = false;
		}
		
		#region Código obrigatório
		
		protected override void OnHandleCreated(EventArgs e)
      	{
         		base.OnHandleCreated(e);
         		PortaUSB.RegisterHandle(Handle);
     	}
      	protected override void WndProc(ref Message m)
      	{
         		PortaUSB.ParseMessages(ref m);
         		base.WndProc(ref m);
      	}
      	#endregion
      	
      	//Propriedades
      	public bool UsbStatus
      	{
      		get
      		{
      			return MainForm_USB_Status.Enabled;
      		}
      		set
      		{
      			MainForm_USB_Status.Enabled = value;
      			MainForm_Disconnect.Enabled = value;
      			
      			if( value )
      			{
      				this.MainForm_USB_Status.BackgroundImage = new Bitmap(
					System.Reflection.Assembly.GetEntryAssembly().GetManifestResourceStream(
					"BootProgUsb.Resources.usb-connect.png"));
      			}
      			else
      			{
      				MainForm_Disconnect.Text = "CONECTAR";
      				MainForm_Open_File.Enabled = false;
      				MainForm_Upload.Enabled = false;
      				this.MCUDevice = "";
      				Flash.Reset();
      				Eeprom.Reset();
      				this.Reset();
      				
      				this.MainForm_USB_Status.BackgroundImage = new Bitmap(
					System.Reflection.Assembly.GetEntryAssembly().GetManifestResourceStream(
					"BootProgUsb.Resources.usb-disconnect.png"));
      			}
      		}
      	}
      	
      	public string ProgramStatus
      	{
      		get
      		{
      			return MainForm_Status.Text;
      		}
      		set
      		{
      			MainForm_Status.Text = value.ToUpper();
      		}
      	}
      	
      	public string MCUDevice
      	{
      		set
      		{
      			MainForm_MCU_Device.Text = value;
      		}
      		get
      		{
      			return MainForm_MCU_Device.Text;
      		}
      	}
      	
      	public static uint BytesCount
      	{
      		get
      		{
      			return ArquivoHexadecimal.Bytes;
      		}
      	}
      	
      	public static byte Buffer
      	{
      		set
      		{
      			for (int i = 0; i < HidWriteBuff.Length; i++) 
      			{
      				HidWriteBuff[i] = value;
      			}
      		}
      	}
      	
      	//Metodos
      	
      	public void Reset()
      	{
      		StartProgramConfig = false;
      		ArquivoHexadecimal.Bytes = 0;
      		MainForm_Progress.Value = 0;
      		bootInfo.Clear();
      		Buffer = 0xFF;
      	}
      	
      	private bool Send( Comandos Cmd, ulong Address, int offset, byte[] Dados )
		{
			if( this.UsbStatus == false )
				return false;
			
			Buffer = 0xFF;
			
			HidWriteBuff[1] = STX;
			HidWriteBuff[2] = (byte)Cmd;
			HidWriteBuff[3] = (byte)( Address >> 8 );
			HidWriteBuff[4] = (byte)( Address & 0xFF );
						
			if(Dados != null )
			{
				for (int i = 5; i < (5+Dados.Length); i++)
				{
					HidWriteBuff[i+offset] = Dados[i-5];
				}
			}
			
			try
			{
				PortaUSB.SpecifiedDevice.SendData( HidWriteBuff );
			}
			catch
			{
				MessageBox.Show( "Houve uma falha ao enviar os dados" );
				return false;
			}
			
			Buffer = 0xFF;
			return true;
		}
      	
      	//Eventos
      	
      	public void DadosRecebidosDoPIC( object sender, DataRecievedEventArgs e )
      	{
      		if( e.data[1] == STX )
      		{
      			switch( e.data[CMD] )
      			{
      				case (byte)Comandos.INFO:
      					//atualiza o texto do botao desconectar
      					MainForm_Disconnect.Invoke( (MethodInvoker) delegate { MainForm_Disconnect.Text = "DESCONECTAR"; } );
      					//habilita o botao abrir
      					MainForm_Open_File.Invoke( (MethodInvoker) delegate { MainForm_Open_File.Enabled = true; } );
      					
      					//Recupera as informações
      					bootInfo.Buffer = e.data;
      					
      					this.MCUDevice = bootInfo.Device;
      					Flash.Size = bootInfo.FlashSize;
      					Eeprom.Size = bootInfo.EepromSize;
      					
      					break;
      					
      				case (byte)Comandos.WRITE:
      					//recupera o endereço de gravaçao atual
      					ulong pos = Flash.CurrentPos;
      					
      					byte[] dados = new byte[32];
      					
      					//Pega 32 bytes do buffer
      					for (int i = 0; i < 32; i++) 
      					{
      						dados[i] = Flash.GetByte;
      					}
      					
      					if( !StartProgramConfig && (pos < ArquivoHexadecimal.Bytes) && Send( Comandos.WRITE, (uint)pos, 0, dados ) )
      					{
      						MainForm_Progress.PerformStep();
      						this.ProgramStatus = "Gravando..." + (MainForm_Progress.Value * 100 / MainForm_Progress.Maximum).ToString() + "%";
      					}
      					else if( !StartProgramConfig )
      					{
      						if( Send( Comandos.WRITE, (bootInfo.BootStart-32), 28, StartProgramFunc ) )
      						{
      							StartProgramConfig = true;
      							MainForm_Progress.PerformStep();
      						}
      					}
      					else
      					{
      						this.ProgramStatus = "Gravação...100%";
      						Send( Comandos.REBOOT, 0, 0, null );
      					}
      					break;
      				
      				case (byte)Comandos.ERASE:
      					this.ProgramStatus = "Memória Flash apagada";
      					Flash.CurrentPos = 0;
      					if( Send( Comandos.WRITE, 0, 0, null ) )
      					{
      						this.ProgramStatus = "Iniciando gravação...";
      						this.ProgramStatus = "Gravando...0%";
      					}
      					break;
      				
      				case (byte)Comandos.REBOOT:
      					this.ProgramStatus = "Reset...";
      					MainForm_Progress.Value = 0;
      					this.ProgramStatus = "";
      					break;
      			}
      		}
      	}
      
		void MainForm_Open_FileClick(object sender, EventArgs e)
		{
			if( openFileDialog1.ShowDialog() == DialogResult.OK )
			{
				ArquivoHexadecimal = new HexFileReader();
				
				//Faz a leitura do arquivo
				if( ArquivoHexadecimal.Read( openFileDialog1.FileName, ref Flash, ref Eeprom ) )
				{
					//Atualiza o status
					this.ProgramStatus = "Arquivo Carregado: " + ArquivoHexadecimal.Bytes.ToString() + "B";
					
					//Salva o endereço do programa do usuário ( CALL StartProgram() )
					StartProgramFunc[0] = Flash.Buffer[0];
					StartProgramFunc[1] = Flash.Buffer[1];
					StartProgramFunc[2] = Flash.Buffer[2];
					StartProgramFunc[3] = Flash.Buffer[3];
					
					//Grava no buffer o endereço do inicio do bootloader( GOTO bootInfo.BootStart )
					//ver datashhet para mais detalhes sobre a instrução GOTO
					Flash.Buffer[0] = (byte)( (bootInfo.BootStart>>1) & 0xFF );
					Flash.Buffer[1] = 0xEF;
					Flash.Buffer[2] = (byte)( (bootInfo.BootStart >> 9) & 0xFF );
					Flash.Buffer[3] = (byte)( 0xF0 | ( (bootInfo.BootStart >> 17) & 0x0F ) );
					
					//Habilita botao upload
					MainForm_Upload.Enabled = true;
					//define o valor maximo da barra de progresso
					MainForm_Progress.Maximum = (int)ArquivoHexadecimal.Bytes / 32 + 1;
      			}
				else
				{
					MessageBox.Show( "Erro ao carregar o arquivo", "Erro" );
					this.ProgramStatus = "";
					MainForm_Upload.Enabled = false;
				}
			}
		}
		
		void MainForm_DisconnectClick(object sender, EventArgs e)
		{
			if( this.UsbStatus == true )
			{
				if( MainForm_Disconnect.Text == "CONECTAR" )
				{
					Send( Comandos.INFO, 0, 0, null );
				}
				else
				{
					Send( Comandos.REBOOT, 0, 0, null );
				}
			}
		}
		
		void MainForm_UploadClick(object sender, EventArgs e)
		{
			if( this.UsbStatus == false )
				return;
			
			if( ArquivoHexadecimal.Bytes == 0 )
			{
				MessageBox.Show( "Carrege o arquivo hexadecimal!!" );
			}
			else
			{
				Send( Comandos.ERASE, (uint)(bootInfo.FlashSize / bootInfo.EraseBlock), 0, null );
			}
		}
		
		void PortaUSBOnSpecifiedDeviceArrived(object sender, EventArgs e)
		{
			this.UsbStatus = true;
			this.ProgramStatus = "Dispositivo conectado";
		}
		
		void PortaUSBOnSpecifiedDeviceRemoved(object sender, EventArgs e)
		{
			this.UsbStatus = false;
			this.ProgramStatus = "Dispositivo desconectado";
		}
		
		void Timer1Tick(object sender, EventArgs e)
		{
			PortaUSB.CheckDevicePresent();
		}
		
		void BtnInfoClick(object sender, EventArgs e)
		{
			string msg =   "FLASH: \t\t\t" + bootInfo.FlashSize + "B\r" + 
						"EEPROM: \t\t\t" + bootInfo.EepromSize + "B\r" +
						"BOOTLOADER ADDRESS: \t" + bootInfo.BootStart + "\n" + 
						"ERASE BLOCKS: \t\t" + bootInfo.EraseBlock;
			
			MessageBox.Show( msg, bootInfo.Device );
		}
		
		void MainFormFormClosing(object sender, FormClosingEventArgs e)
		{
			if( this.UsbStatus == true )
			{
				try
				{
					Send( Comandos.REBOOT, 0, 0, null );
				}
				catch
				{
					
				}
			}
		}
	}
}
