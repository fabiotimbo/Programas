using System;

namespace BootProgUsb
{
	public static class Device
	{
		public enum DEVICE
		{
			None = 0,
			P18F2550 = 1,
			P18F4550 = 2
		}
		
		public static string GetDeviceName( int i )
		{
			string name =  Enum.GetName( typeof(DEVICE), i );
			return ( name == null ) ? "DESCONHECIDO" : name;
		}
		
		public static int GetDeviceNumber( string name )
		{
			string[] names = Enum.GetNames( typeof(DEVICE) );
			for (int i = 0; i < names.Length; i++)
			{
				if( names[i] == name )
					return i;
			}
			return -1;
		}
	}
}
