#include <18F4550.h>
#fuses HS,CPUDIV1,PLL5,USBDIV
#device adc=10
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#define LCD_DB0   PIN_D0
#define LCD_DB1   PIN_D1
#define LCD_DB2   PIN_D2
#define LCD_DB3   PIN_D3
#define LCD_DB4   PIN_D4
#define LCD_DB5   PIN_D5
#define LCD_DB6   PIN_D6
#define LCD_DB7   PIN_D7
#define LCD_E     PIN_E1
#define LCD_RS    PIN_E2
#include <flex_lcd.c>
float32 lm;
unsigned int32 ad0;
void main()
{lcd_init();
lcd_gotoxy(1,1);
printf(lcd_putc," Sensor ");
lcd_gotoxy(1,2);
printf(lcd_putc," LM35");
delay_ms(100);
setup_adc_ports(an0);
setup_adc(adc_clock_internal);
set_adc_channel(0);
while(true)
{lm=read_adc();
delay_ms(10);
ad0=lm*0.488758;//igual a (5/1023)*100
lcd_gotoxy(1,1);
printf(lcd_putc,"\f   Temperatura  ", );
lcd_gotoxy(1,2);
printf(lcd_putc,"        %lu %cC",ad0,0xdf);
delay_ms(1000);}}

