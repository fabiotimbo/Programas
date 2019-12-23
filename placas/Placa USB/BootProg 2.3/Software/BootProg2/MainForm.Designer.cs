
namespace BootProgUsb
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
			this.statusStrip1 = new System.Windows.Forms.StatusStrip();
			this.MainForm_Status = new System.Windows.Forms.ToolStripStatusLabel();
			this.MainForm_Open_File = new System.Windows.Forms.Button();
			this.MainForm_Disconnect = new System.Windows.Forms.Button();
			this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
			this.MainForm_Upload = new System.Windows.Forms.Button();
			this.MainForm_Progress = new System.Windows.Forms.ProgressBar();
			this.MainForm_USB_Status = new System.Windows.Forms.PictureBox();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.toolStrip1 = new System.Windows.Forms.ToolStrip();
			this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
			this.MainForm_MCU_Device = new System.Windows.Forms.ToolStripLabel();
			this.PortaUSB = new UsbLibrary.UsbHidPort(this.components);
			this.statusStrip1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.MainForm_USB_Status)).BeginInit();
			this.toolStrip1.SuspendLayout();
			this.SuspendLayout();
			// 
			// statusStrip1
			// 
			this.statusStrip1.BackColor = System.Drawing.Color.Red;
			this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
									this.MainForm_Status});
			this.statusStrip1.Location = new System.Drawing.Point(0, 207);
			this.statusStrip1.Name = "statusStrip1";
			this.statusStrip1.Size = new System.Drawing.Size(242, 22);
			this.statusStrip1.SizingGrip = false;
			this.statusStrip1.TabIndex = 10;
			this.statusStrip1.Text = "statusStrip1";
			// 
			// MainForm_Status
			// 
			this.MainForm_Status.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
			this.MainForm_Status.ForeColor = System.Drawing.Color.White;
			this.MainForm_Status.Name = "MainForm_Status";
			this.MainForm_Status.Size = new System.Drawing.Size(227, 17);
			this.MainForm_Status.Spring = true;
			this.MainForm_Status.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			this.MainForm_Status.TextImageRelation = System.Windows.Forms.TextImageRelation.Overlay;
			// 
			// MainForm_Open_File
			// 
			this.MainForm_Open_File.Cursor = System.Windows.Forms.Cursors.Hand;
			this.MainForm_Open_File.Enabled = false;
			this.MainForm_Open_File.Font = new System.Drawing.Font("Arial Black", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.MainForm_Open_File.ForeColor = System.Drawing.Color.Red;
			this.MainForm_Open_File.Image = ((System.Drawing.Image)(resources.GetObject("MainForm_Open_File.Image")));
			this.MainForm_Open_File.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
			this.MainForm_Open_File.Location = new System.Drawing.Point(6, 96);
			this.MainForm_Open_File.Name = "MainForm_Open_File";
			this.MainForm_Open_File.Size = new System.Drawing.Size(115, 39);
			this.MainForm_Open_File.TabIndex = 2;
			this.MainForm_Open_File.TabStop = false;
			this.MainForm_Open_File.Text = "ABRIR";
			this.MainForm_Open_File.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
			this.MainForm_Open_File.UseVisualStyleBackColor = true;
			this.MainForm_Open_File.Click += new System.EventHandler(this.MainForm_Open_FileClick);
			// 
			// MainForm_Disconnect
			// 
			this.MainForm_Disconnect.Cursor = System.Windows.Forms.Cursors.Hand;
			this.MainForm_Disconnect.Enabled = false;
			this.MainForm_Disconnect.Font = new System.Drawing.Font("Arial Black", 6.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.MainForm_Disconnect.ForeColor = System.Drawing.Color.Red;
			this.MainForm_Disconnect.Image = ((System.Drawing.Image)(resources.GetObject("MainForm_Disconnect.Image")));
			this.MainForm_Disconnect.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
			this.MainForm_Disconnect.Location = new System.Drawing.Point(7, 53);
			this.MainForm_Disconnect.Name = "MainForm_Disconnect";
			this.MainForm_Disconnect.Size = new System.Drawing.Size(115, 39);
			this.MainForm_Disconnect.TabIndex = 1;
			this.MainForm_Disconnect.TabStop = false;
			this.MainForm_Disconnect.Text = "CONECTAR";
			this.MainForm_Disconnect.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
			this.MainForm_Disconnect.UseVisualStyleBackColor = true;
			this.MainForm_Disconnect.Click += new System.EventHandler(this.MainForm_DisconnectClick);
			// 
			// openFileDialog1
			// 
			this.openFileDialog1.FileName = "openFileDialog1";
			this.openFileDialog1.Filter = "Hex Files|*.hex";
			this.openFileDialog1.RestoreDirectory = true;
			// 
			// MainForm_Upload
			// 
			this.MainForm_Upload.Cursor = System.Windows.Forms.Cursors.Hand;
			this.MainForm_Upload.Enabled = false;
			this.MainForm_Upload.Font = new System.Drawing.Font("Arial Black", 7.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.MainForm_Upload.ForeColor = System.Drawing.Color.Red;
			this.MainForm_Upload.Image = ((System.Drawing.Image)(resources.GetObject("MainForm_Upload.Image")));
			this.MainForm_Upload.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
			this.MainForm_Upload.Location = new System.Drawing.Point(6, 141);
			this.MainForm_Upload.Name = "MainForm_Upload";
			this.MainForm_Upload.Size = new System.Drawing.Size(115, 39);
			this.MainForm_Upload.TabIndex = 3;
			this.MainForm_Upload.TabStop = false;
			this.MainForm_Upload.Text = "UPLOAD";
			this.MainForm_Upload.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
			this.MainForm_Upload.UseVisualStyleBackColor = true;
			this.MainForm_Upload.Click += new System.EventHandler(this.MainForm_UploadClick);
			// 
			// MainForm_Progress
			// 
			this.MainForm_Progress.ForeColor = System.Drawing.Color.DeepSkyBlue;
			this.MainForm_Progress.Location = new System.Drawing.Point(0, 193);
			this.MainForm_Progress.Name = "MainForm_Progress";
			this.MainForm_Progress.Size = new System.Drawing.Size(242, 14);
			this.MainForm_Progress.Step = 1;
			this.MainForm_Progress.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
			this.MainForm_Progress.TabIndex = 8;
			// 
			// MainForm_USB_Status
			// 
			this.MainForm_USB_Status.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
			this.MainForm_USB_Status.Enabled = false;
			this.MainForm_USB_Status.Location = new System.Drawing.Point(128, 59);
			this.MainForm_USB_Status.Name = "MainForm_USB_Status";
			this.MainForm_USB_Status.Size = new System.Drawing.Size(103, 114);
			this.MainForm_USB_Status.TabIndex = 11;
			this.MainForm_USB_Status.TabStop = false;
			// 
			// timer1
			// 
			this.timer1.Enabled = true;
			this.timer1.Interval = 3500;
			this.timer1.Tick += new System.EventHandler(this.Timer1Tick);
			// 
			// toolStrip1
			// 
			this.toolStrip1.BackColor = System.Drawing.Color.MediumSeaGreen;
			this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
									this.toolStripButton1,
									this.MainForm_MCU_Device});
			this.toolStrip1.Location = new System.Drawing.Point(0, 0);
			this.toolStrip1.Name = "toolStrip1";
			this.toolStrip1.Size = new System.Drawing.Size(242, 25);
			this.toolStrip1.TabIndex = 13;
			this.toolStrip1.Text = "toolStrip1";
			// 
			// toolStripButton1
			// 
			this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
			this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.toolStripButton1.Name = "toolStripButton1";
			this.toolStripButton1.Size = new System.Drawing.Size(23, 22);
			this.toolStripButton1.ToolTipText = "Chip Info";
			this.toolStripButton1.Click += new System.EventHandler(this.BtnInfoClick);
			// 
			// MainForm_MCU_Device
			// 
			this.MainForm_MCU_Device.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
			this.MainForm_MCU_Device.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
			this.MainForm_MCU_Device.ForeColor = System.Drawing.Color.White;
			this.MainForm_MCU_Device.Name = "MainForm_MCU_Device";
			this.MainForm_MCU_Device.Size = new System.Drawing.Size(102, 22);
			this.MainForm_MCU_Device.Text = "Desconhecido";
			this.MainForm_MCU_Device.TextImageRelation = System.Windows.Forms.TextImageRelation.Overlay;
			// 
			// PortaUSB
			// 
			this.PortaUSB.ProductId = 1;
			this.PortaUSB.VendorId = 1;
			this.PortaUSB.OnSpecifiedDeviceArrived += new System.EventHandler(this.PortaUSBOnSpecifiedDeviceArrived);
			this.PortaUSB.OnSpecifiedDeviceRemoved += new System.EventHandler(this.PortaUSBOnSpecifiedDeviceRemoved);
			this.PortaUSB.OnDataRecieved += new UsbLibrary.DataRecievedEventHandler(this.DadosRecebidosDoPIC);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
			this.BackColor = System.Drawing.Color.Navy;
			this.ClientSize = new System.Drawing.Size(242, 229);
			this.Controls.Add(this.toolStrip1);
			this.Controls.Add(this.MainForm_USB_Status);
			this.Controls.Add(this.MainForm_Progress);
			this.Controls.Add(this.MainForm_Upload);
			this.Controls.Add(this.MainForm_Disconnect);
			this.Controls.Add(this.MainForm_Open_File);
			this.Controls.Add(this.statusStrip1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MaximizeBox = false;
			this.Name = "MainForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "BootProg 2.3";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainFormFormClosing);
			this.statusStrip1.ResumeLayout(false);
			this.statusStrip1.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.MainForm_USB_Status)).EndInit();
			this.toolStrip1.ResumeLayout(false);
			this.toolStrip1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.ToolStripButton toolStripButton1;
		private UsbLibrary.UsbHidPort PortaUSB;
		private System.Windows.Forms.ToolStrip toolStrip1;
		private System.Windows.Forms.Timer timer1;
		private System.Windows.Forms.PictureBox MainForm_USB_Status;
		private System.Windows.Forms.ProgressBar MainForm_Progress;
		private System.Windows.Forms.Button MainForm_Upload;
		private System.Windows.Forms.ToolStripLabel MainForm_MCU_Device;
		private System.Windows.Forms.OpenFileDialog openFileDialog1;
		private System.Windows.Forms.Button MainForm_Disconnect;
		private System.Windows.Forms.Button MainForm_Open_File;
		private System.Windows.Forms.ToolStripStatusLabel MainForm_Status;
		private System.Windows.Forms.StatusStrip statusStrip1;
	}
}
