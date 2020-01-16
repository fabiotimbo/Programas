#INCLUDE <18F4550.h>
#fuses HS,CPUDIV1,USBDIV,PLL5
#device adc=10
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
//#use standard_io(B) //comentar linha caso a biblioteca do LCD seja diferente
//#define use_portB_lcd TRUE //comentar linha caso a biblioteca do LCD seja diferente
//#define LCD_TYPE 2
//#include <LCD.c> 
float32 lm;
unsigned int32 ad0;
int m,c,d,u;
void main()
{
//lcd_init();
//lcd_gotoxy(1,1);
//printf(lcd_putc," Grafico ");
//lcd_gotoxy(1,2);
//printf(lcd_putc," Serial ");
delay_ms(100);
setup_adc_ports(an0);
setup_adc(adc_clock_internal);
set_adc_channel(0);
while(true)
{
lm=read_adc();
delay_ms(10);
lm=lm*0.488758;
ad0=lm;
delay_ms(10);
m= ad0/1000;
c=((ad0%1000)/100);
d=((ad0%1000)%100)/10;
u=(((ad0%1000)%100)%10)/1;
delay_ms(300);
//printf(" %f ",lux);
printf("&");
delay_ms(100);
printf("%d",m);
delay_ms(100);
printf("%d",c);
delay_ms(100);
printf("%d",d);
delay_ms(100);
printf("%d",u);
delay_ms(100);
printf("f");
delay_ms(100);
printf("f");
delay_ms(100);
printf("\r\n");
//lcd_gotoxy(1,1);
//printf(lcd_putc,"\f   Temperatura ");
//lcd_gotoxy(1,2);
//printf(lcd_putc,"      %.1f %cC",lm,0xdf);
delay_ms(100);
}}

