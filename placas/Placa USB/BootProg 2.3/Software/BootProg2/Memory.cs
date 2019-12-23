using System;

namespace BootProgUsb
{
	public class Memory
	{
		byte[] mem = new byte[32768];
		public ulong CurrentPos = 0;
		
		public Memory()
		{
		}
		
		public Memory( ulong size )
		{
			mem = new byte[size];
		}
		
		public ulong Size
		{
			get
			{
				return (ulong)mem.Length;
			}
			set
			{
				mem = new byte[value];
			}
		}
		
		public byte[] Buffer
		{
			get
			{
				return mem;
			}
			set
			{
				mem = value;
			}
		}
		
		public byte Fill
		{
			set
			{
				for (int i = 0; i < mem.Length; i++) 
				{
					mem[i] = value;
				}
			}
		}
		
		public byte GetByte
		{
			get
			{
				return mem[CurrentPos++];
			}
		}
		
		public void Reset()
		{
			this.CurrentPos = 0;
			this.Fill = 0xFF;
		}
		
	}
}
