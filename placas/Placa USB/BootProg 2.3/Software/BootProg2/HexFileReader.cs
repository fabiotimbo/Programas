using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using Microcontrolandos.SRecord;

namespace BootProgUsb
{
	public class HexFileReader
	{
		IntelHex hex = new IntelHex();
		uint nBytes = 0;
				
		//Propriedades
		
		public uint Bytes
		{
			get
			{
				return nBytes;
			}
			set
			{
				nBytes = value;
			}
		}
		
		
		//Metodos
		
		public bool Read( string path, ref Memory _flash, ref Memory _eeprom )
		{
			nBytes = 0;
			_flash.Fill = 0xFF;
			
			int CodeType = 0; // 0 - Flash, 1 - Eeprom
			uint mAddr = 0;
			
			StreamReader reader = new StreamReader( path );
			
			while( reader.EndOfStream == false )
			{
				string line = String.Empty;
				IntelHexStructure iHex = hex.Read( reader, ref line );
				
				if( hex.Status == 0 )
				{
					if( line == ":020000040000FA" ) //Code 0KB
						continue;
					
					if( line == ":020000040001F9" ) //code 64KB
						continue;
					
					if( line == ":020000040001F8" ) //code 128KB
						continue;
					
					if( line == ":020000040030CA" ) //Fuses
					{
						IntelHexStructure nIHex = hex.Read( reader, ref line );
						continue;
					}
					
					if( line == ":020000040020DA" ) //User ID
					{
						IntelHexStructure nIHex = hex.Read( reader, ref line );
						continue;
					}
					
					if( line == ":0200000400F00A" ) //Eeprom
					{
						CodeType = 1;
						continue;
					}
					
					if( CodeType == 0 )
					{
						try
						{
							int pos = 0;
							for (int i = iHex.address; i < iHex.address+iHex.dataLen; i++)
							{
								_flash.Buffer[i] = iHex.data[pos++];
							}
						
							if( iHex.address >= mAddr )
							{
								mAddr = iHex.address;
								nBytes = mAddr + (uint)iHex.dataLen;
							}
						}
						catch
						{
						
						}
					}
					else
					{
						try
						{
							int pos = 0;
							for (int i = iHex.address; i < iHex.address+iHex.dataLen; i++)
							{
								_eeprom.Buffer[i] = iHex.data[pos++];
							}
						}
						catch
						{
						
						}
					}
				}
			}
			
			reader.Close();
			return (nBytes > 0);
		}
		
		public string ToString( Memory _flash )
		{
			StringBuilder myString = new StringBuilder();
			
			for (int i = 0; i < this.Bytes; i++)
			{
				myString.Append( _flash.Buffer[i].ToString("X2") + " " );
				if( i % 16 == 0 )
					myString.AppendLine();
			}
			
			return myString.ToString();
		}
	}
}
