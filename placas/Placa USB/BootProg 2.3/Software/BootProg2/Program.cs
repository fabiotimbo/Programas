/*
 * SharpDevelop
 * Usuário: Tiago
 * Data: 08/01/2014
 * Hora: 18:08
 */
using System;
using System.Windows.Forms;

namespace BootProgUsb
{
	/// <summary>
	/// Class with program entry point.
	/// </summary>
	internal sealed class Program
	{
		/// <summary>
		/// Program entry point.
		/// </summary>
		[STAThread]
		private static void Main(string[] args)
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(new MainForm());
		}
		
	}
}
