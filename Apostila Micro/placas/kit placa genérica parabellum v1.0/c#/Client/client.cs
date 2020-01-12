using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using SimpleTCP;

namespace Client
{
    public partial class Client : Form
        
    {    

        public Client()
        {
            InitializeComponent();
        }
        SimpleTcpClient client;

        private void btnConnect_Click(object sender, EventArgs e)
        {
            btnConnect.Enabled = false;
            client.Connect(txtHost.Text, Convert.ToInt32(txtPort.Text));
        }

        private void Client_Load(object sender, EventArgs e)
        {
            client = new SimpleTcpClient();
            client.StringEncoder = Encoding.UTF8;
            client.DataReceived += client_DataReceived;
        }

        void client_DataReceived(object sender, SimpleTCP.Message e)
        {
            txtStatus.Invoke((MethodInvoker)delegate()
            {
                txtStatus.Text += e.MessageString;
                
            });
        }

        private void btnSend_Click(object sender, EventArgs e)
        {
            //client.WriteLineAndGetReply(txtMessage.Text, TimeSpan.FromSeconds(1));
            client.WriteLine(txtMessage.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            txtStatus.Text="";
        }
    }
}
