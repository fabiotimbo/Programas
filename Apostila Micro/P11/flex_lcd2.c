/*
   Este código é uma adaptação do flex_lcd.c original obtido no link a seguir:
   https://www.ccsinfo.com/forum/viewtopic.php?t=24661

   Atulização: 
      * Agora é possível utilizar o display 16x4. Cada \n funciona normalmente
        levando para a linha seguinte.

   A pinagem padrão é a mesma da biblioteca lcd.c 
   que vem com o CCS com os pinos definidos como segue.
   Caso queira utilizar utilizar outros pinos basta definir 
   cada um antes de importar esta biblioteca.
*/

#ifndef LCD_DB4
   #define LCD_DB4   PIN_D4
#endif
#ifndef LCD_DB5
   #define LCD_DB5   PIN_D5
#endif
#ifndef LCD_DB6
   #define LCD_DB6   PIN_D6
#endif
#ifndef LCD_DB7
   #define LCD_DB7   PIN_D7
#endif

#ifndef LCD_DB4
   #define LCD_DB4   PIN_D4
#endif

#ifndef LCD_E
   #define LCD_E   PIN_D0
#endif
#ifndef LCD_RS
   #define LCD_RS   PIN_D1
#endif

/*
   Se queser utilizar apenas 6 pinos com seu LCD,
   basta não declarar a constante LCD_RW.
*/
#ifdef LCD_RW
   #define LCD_RW   PIN_D2
   #define USE_LCD_RW   1
#endif
     

//======================================== 

#define lcd_type 2        // 0=5x7, 1=5x10, 2=2 lines 
#define lcd_line_two 0x40 // LCD RAM address for the 2nd line 

int8 lines[] = {0, 0x40, 0x10, 0x50};
int8 curr_line = 0;

int8 const LCD_INIT_STRING[4] = 
{ 
 0x20 | (lcd_type << 2), // Func set: 4-bit, 2 lines, 5x8 dots 
 0xc,                    // Display on 
 1,                      // Clear display 
 6                       // Increment cursor 
 }; 
                              

//------------------------------------- 
void lcd_send_nibble(int8 nibble) 
{ 
// Note:  !! converts an integer expression 
// to a boolean (1 or 0). 
 output_bit(LCD_DB4, !!(nibble & 1)); 
 output_bit(LCD_DB5, !!(nibble & 2));  
 output_bit(LCD_DB6, !!(nibble & 4));    
 output_bit(LCD_DB7, !!(nibble & 8));    

 delay_cycles(1); 
 output_high(LCD_E); 
 delay_us(2); 
 output_low(LCD_E); 
} 

//----------------------------------- 
// This sub-routine is only called by lcd_read_byte(). 
// It's not a stand-alone routine.  For example, the 
// R/W signal is set high by lcd_read_byte() before 
// this routine is called.      

#ifdef USE_LCD_RW 
int8 lcd_read_nibble(void) 
{ 
int8 retval; 
// Create bit variables so that we can easily set 
// individual bits in the retval variable. 
#bit retval_0 = retval.0 
#bit retval_1 = retval.1 
#bit retval_2 = retval.2 
#bit retval_3 = retval.3 

retval = 0; 
    
output_high(LCD_E); 
delay_cycles(1); 

retval_0 = input(LCD_DB4); 
retval_1 = input(LCD_DB5); 
retval_2 = input(LCD_DB6); 
retval_3 = input(LCD_DB7); 
  
output_low(LCD_E); 
    
return(retval);    
}    
#endif 

//--------------------------------------- 
// Read a byte from the LCD and return it. 

#ifdef USE_LCD_RW 
int8 lcd_read_byte(void) 
{ 
int8 low; 
int8 high; 

output_high(LCD_RW); 
delay_cycles(1); 

high = lcd_read_nibble(); 

low = lcd_read_nibble(); 

return( (high<<4) | low); 
} 
#endif 

//---------------------------------------- 
// Send a byte to the LCD. 
void lcd_send_byte(int8 address, int8 n) 
{ 
output_low(LCD_RS); 

#ifdef USE_LCD_RW 
while(bit_test(lcd_read_byte(),7)) ; 
#else 
delay_us(60);  
#endif 

if(address) 
   output_high(LCD_RS); 
else 
   output_low(LCD_RS); 
      
 delay_cycles(1); 

#ifdef USE_LCD_RW 
output_low(LCD_RW); 
delay_cycles(1); 
#endif 

output_low(LCD_E); 

lcd_send_nibble(n >> 4); 
lcd_send_nibble(n & 0xf); 
} 

//---------------------------- 
void lcd_init(void) 
{ 
int8 i; 

output_low(LCD_RS); 

#ifdef USE_LCD_RW 
output_low(LCD_RW); 
#endif 

output_low(LCD_E); 

delay_ms(15); 

for(i=0 ;i < 3; i++) 
   { 
    lcd_send_nibble(0x03); 
    delay_ms(5); 
   } 

lcd_send_nibble(0x02); 

for(i=0; i < sizeof(LCD_INIT_STRING); i++) 
   { 
    lcd_send_byte(0, LCD_INIT_STRING[i]); 
    
    // If the R/W signal is not used, then 
    // the busy bit can't be polled.  One of 
    // the init commands takes longer than 
    // the hard-coded delay of 60 us, so in 
    // that case, lets just do a 5 ms delay 
    // after all four of them. 
    #ifndef USE_LCD_RW 
    delay_ms(5); 
    #endif 
   } 

} 

//---------------------------- 

void lcd_gotoxy(int8 x, int8 y) 
{ 
   int8 address; 
   //curr_line = y - 1;
   /*
   if(y != 1) 
      address = lcd_line_two;
   else
      address=0; 
   */
   address = lines[curr_line];
   
   address += x-1; 
   lcd_send_byte(0, 0x80 | address); 
} 

//----------------------------- 
void lcd_putc(char c) 
{ 
 switch(c) 
   { 
    case '\f': 
      lcd_send_byte(0,1); 
      curr_line = 0;
      delay_ms(2); 
      break; 
    
    case '\n': 
       curr_line++;
       lcd_gotoxy(1,curr_line); 
       break; 
    
    case '\b': 
       lcd_send_byte(0,0x10); 
       break; 
    
    default: 
       lcd_send_byte(1,c); 
       break; 
   } 
} 

//------------------------------ 
#ifdef USE_LCD_RW 
char lcd_getc(int8 x, int8 y) 
{ 
char value; 

lcd_gotoxy(x,y); 

// Wait until busy flag is low. 
while(bit_test(lcd_read_byte(),7));  

output_high(LCD_RS); 
value = lcd_read_byte(); 
output_low(lcd_RS); 

return(value); 
} 
#endif

// Não está funcionando
void lcd_set_cgram_char(unsigned int8 which, unsigned int8 *ptr)
{
   unsigned int i;

   which <<= 3;
   which &= 0x38;

   lcd_send_byte(0, 0x40 | which);  //set cgram address

   for(i=0; i<8; i++)
   {
      lcd_send_byte(1, *ptr++);
   }
  
   #if defined(LCD_EXTENDED_NEWLINE)
    lcd_gotoxy(g_LcdX+1, g_LcdY+1);  //set ddram address
   #endif
}

