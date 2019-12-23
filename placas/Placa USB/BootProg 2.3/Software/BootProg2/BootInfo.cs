using System;

namespace BootProgUsb
{
	public class BootInfo
	{
		public enum McuType
		{ 
			PIC16 = 1,
			PIC18,
			PIC18FJ,
			PIC24,
			DSPIC = 10,
			PIC32 = 20
		};

		
		byte[] Data = new byte[65];
		public McuType mcuType;
		public ulong FlashSize;
		public uint EraseBlock;
		public uint WriteBlock;
		public ulong BootStart;
		public uint EepromSize;
		public string Device = "Desconhecido";
		
		public byte[] Buffer
		{
			set
			{
				Data = value;
				
				mcuType = (McuType)Data[3];
				FlashSize = BitConverter.ToUInt32( Data, 4 );
				EraseBlock = BitConverter.ToUInt16( Data, 8 );
				WriteBlock = BitConverter.ToUInt16( Data, 10 );
				BootStart = BitConverter.ToUInt32( Data, 12 );
				EepromSize = BitConverter.ToUInt16( Data, 16 );
				//Device = System.Text.Encoding.GetString( Data, 18, 19 );
				this.Device = GetString( Data, 18, 19 );
			}
		}
		
		public void Clear()
		{
			FlashSize = 0;
			EraseBlock = 0;
			WriteBlock = 0;
			BootStart = 0;
			EepromSize = 0;
			Device = "Desconhecido";
		}
		
		private string GetString( byte[] bytes, int index, int count )
		{
			string myString = "";
			for (int i = index; i < index+count; i++)
			{
				if( bytes[i] == '\0' )
					break;
				myString += (char)bytes[i];
			}
			return myString;
		}
	}
}
