#include <18F4550.h>
#fuses HS, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use standard_io(B) //comentar linha caso a biblioteca do LCD seja diferente
#define use_portB_lcd TRUE //comentar linha caso a biblioteca do LCD seja diferente
#define LCD_TYPE 2
#include <LCD.c>
unsigned int32 n=0;
void main()
{lcd_init();
while(true)
{lcd_gotoxy(1,1);
printf(lcd_putc,"\f Temporizador ", );
lcd_gotoxy(1,2);
printf(lcd_putc,"       %lu ",n);
delay_ms(1000);
n=n+1;
}}

