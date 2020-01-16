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
using Excel = Microsoft.Office.Interop.Excel;

namespace Client
{
    public partial class Client : Form
    
{
        public string cl,fs;
        public char sm, sc, sd, su;
        public string[]  leitor;
        public Int32 num,x=0;
        public Client()
        {
            InitializeComponent();
        }

        SimpleTcpClient client;

        private void btnConnect_Click(object sender, EventArgs e)
        {
            btnConnect.Enabled = false;
            //Connect to server
            client.Connect(txtHost.Text, Convert.ToInt32(txtPort.Text));
        }

        private void Client_Load(object sender, EventArgs e)
        {
            client = new SimpleTcpClient();
            client.StringEncoder = Encoding.UTF8;
            client.DataReceived += Client_DataReceived;
        }

        private void Client_DataReceived(object sender, SimpleTCP.Message e)
        {
            //Update message to txtStatus
            txtStatus.Invoke((MethodInvoker)delegate()
            {
                
                txtStatus.Text += e.MessageString;
                //sm += e.MessageString[0].ToString();
                //sc = e.MessageString[1].ToString();
                //sd = e.MessageString[2].ToString();
                //su = e.MessageString[3].ToString();
                cl += e.MessageString;
                SetText(cl);
                                });
            
            cl = "";

        }

        private void btnSend_Click(object sender, EventArgs e)
        {
         //   client.WriteLineAndGetReply(txtMessage.Text, TimeSpan.FromSeconds(3));
          
            client.WriteLine(txtMessage.Text);
        }

        private void txtStatus_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void SetText(string text)
        {
            leitor = txtStatus.Lines;
            if ((leitor.Length > 2)&&(leitor[leitor.Length - 2].Length>4)) 
            { 
                fs = leitor[leitor.Length - 2]; sm = fs[1]; sc = fs[2]; sd = fs[3]; su = fs[4];
                label3.Text = sm.ToString() + sc.ToString() + sd.ToString() + su.ToString();
                cht1.Series[0].Points.AddXY(x++, ((Convert.ToInt32(label3.Text))));
            }
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (cht1.Series[0].Points.Count > 1)
            {
                Excel.Application xlApp;
                Excel.Workbook xlWorkBook;
                Excel.Worksheet xlWorkSheet;
                object misValue = System.Reflection.Missing.Value;

                xlApp = new Excel.Application();
                xlWorkBook = xlApp.Workbooks.Add(misValue);
                xlWorkSheet = (Excel.Worksheet)xlWorkBook.Worksheets.get_Item(1);

                for (int i = 0; i < cht1.Series.Count; i++)
                {
                    xlWorkSheet.Cells[1, 1] = "";
                    xlWorkSheet.Cells[1, 2] = "DateTime";//put your column heading here
                    xlWorkSheet.Cells[1, 3] = "Data";// put your column heading here

                    for (int j = 0; j < cht1.Series[i].Points.Count; j++)
                    {
                        xlWorkSheet.Cells[j + 2, 2] = cht1.Series[i].Points[j].XValue;
                        xlWorkSheet.Cells[j + 2, 3] = cht1.Series[i].Points[j].YValues[0];
                    }
                }

                Excel.Range chartRange;
                Excel.ChartObjects xlCharts = (Excel.ChartObjects)xlWorkSheet.ChartObjects(Type.Missing);
                Excel.ChartObject myChart = (Excel.ChartObject)xlCharts.Add(150, 10, 800, 300);
                Excel.Chart chartPage = myChart.Chart;

                chartRange = xlWorkSheet.get_Range("c2", "c100");//update the range here
                chartPage.SetSourceData(chartRange, misValue);
                chartPage.ChartType = Excel.XlChartType.xlColumnClustered;

                xlWorkBook.SaveAs("grafico.xls", Excel.XlFileFormat.xlWorkbookNormal, misValue, misValue, misValue, misValue, Excel.XlSaveAsAccessMode.xlExclusive, misValue, misValue, misValue, misValue, misValue);
                xlWorkBook.Close(true, misValue, misValue);
                xlApp.Quit();

                releaseObject(xlWorkSheet);
                releaseObject(xlWorkBook);
                releaseObject(xlApp);

                MessageBox.Show("Arquivo excel grafico.xls criado na pasta documentos");
            }
        }
        private void releaseObject(object obj)
        {
            try
            {
                System.Runtime.InteropServices.Marshal.ReleaseComObject(obj);
                obj = null;
            }
            catch (Exception ex)
            {
                obj = null;
                MessageBox.Show("Exception Occured while releasing object " + ex.ToString());
            }
            finally
            {
                GC.Collect();
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true) { this.Height = 501; this.Width = 889; button1.Visible = true; label3.Visible = true; }
            else
            { this.Height = 501; this.Width = 294; button1.Visible = false; label3.Visible = false; }                
        }
    }
}
