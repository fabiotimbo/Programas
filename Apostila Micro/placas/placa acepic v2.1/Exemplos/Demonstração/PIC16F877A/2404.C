///////////////////////////////////////////////////////////////////////////
////   Library for a MicroChip 24LC04B                                 ////
////                                                                   ////
////   init_ext_eeprom();    Call before the other functions are used  ////
////                                                                   ////
////   write_ext_eeprom(a, d);  Write the byte d to the address a      ////
////                                                                   ////
////   d = read_ext_eeprom(a);  Read the byte d from the address a     ////
////                                                                   ////
////   b = ext_eeprom_ready();  Returns TRUE if the eeprom is ready    ////
////                            to receive opcodes                     ////
////                                                                   ////
////   The main program may define EEPROM_SDA                          ////
////   and EEPROM_SCL to override the defaults below.                  ////
////                                                                   ////
////                            Pin Layout                             ////
////   -----------------------------------------------------------     ////
////   |                                                         |     ////
////   | 1: NC   Not Connected | 8: VCC   +5V                    |     ////
////   |                       |                                 |     ////
////   | 2: NC   Not Connected | 7: WP    GND                    |     ////
////   |                       |                                 |     ////
////   | 3: NC   Not Connected | 6: SCL   EEPROM_SCL and Pull-Up |     ////
////   |                       |                                 |     ////
////   | 4: VSS  GND           | 5: SDA   EEPROM_SDA and Pull-Up |     ////
////   -----------------------------------------------------------     ////
////                                                                   ////
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996, 2003 Custom Computer Services          ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////


#ifndef EEPROM_SDA

#define EEPROM_SDA  PIN_C4
#define EEPROM_SCL  PIN_C3

#endif


#use i2c(master, sda=EEPROM_SDA, scl=EEPROM_SCL)

#define EEPROM_ADDRESS long int
#define EEPROM_SIZE    512

void init_ext_eeprom() {
   output_float(EEPROM_SCL);
   output_float(EEPROM_SDA);
}

BOOLEAN ext_eeprom_ready() {
   int1 ack;
   i2c_start();            // If the write command is acknowledged,
   ack = i2c_write(0xa0);  // then the device is ready.
   i2c_stop();
   return !ack;
}

void write_ext_eeprom(long int address, BYTE data) {
   while(!ext_eeprom_ready());
   i2c_start();
   i2c_write((0xa0|(BYTE)(address>>7))&0xfe);
   i2c_write(address);
   i2c_write(data);
   i2c_stop();
}


BYTE read_ext_eeprom(long int address) {
   BYTE data;

   while(!ext_eeprom_ready());
   i2c_start();
   i2c_write((0xa0|(BYTE)(address>>7))&0xfe);
   i2c_write(address);
   i2c_start();
   i2c_write((0xa0|(BYTE)(address>>7))|1);
   data=i2c_read(0);
   i2c_stop();
   return(data);
}
