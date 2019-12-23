#include <18F4550.h>
#fuses HS,CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use standard_io(B) //comentar linha caso a biblioteca do LCD seja diferente
#define use_portB_lcd TRUE //comentar linha caso a biblioteca do LCD seja diferente
#define LCD_TYPE 2
#include <LCD.c>
float ad1,lux;
void main()
{lcd_init();
lcd_gotoxy(1,1);
printf(lcd_putc," Leitura ");
lcd_gotoxy(1,2);
printf(lcd_putc," Luminosidade ");
delay_ms(1000);
setup_adc_ports(an0);
SETUP_ADC(ADC_CLOCK_INTERNAL); //Seta a origem do clock
SET_ADC_CHANNEL(0);
while(true)
{ad1=read_adc();
  ad1=ad1*0.0048875;
  if (ad1>2 && ad1<2.8)   {      lux=(3936.4-(1249*ad1))/0.8;   }
  if (ad1>=2.8 && ad1<=3.8)   {  lux=2057.2-494*ad1;   }
  if (ad1>3.8)   {      lux=(900-180*ad1)/1.2;   }
delay_ms(10);
lcd_gotoxy(1,1);
printf(lcd_putc,"\f    Luminosidade ");
lcd_gotoxy(1,2);
printf(lcd_putc,"     %.1f lux ",lux);
delay_ms(1000);
printf("\r\nLuminosidade=%.1f  \r\n",lux);
}}

