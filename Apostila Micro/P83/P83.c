#define led0 pin_d0
#define led1 pin_d1
#include <18F4550.h>
#device adc=10
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#int_timer1
void funcao_tempo()
{float ad1;static boolean led=1;static unsigned int32 n;
set_timer1(3036+get_timer1());
n++;
if (n==5)
{n=0;
led=!led;
output_bit(led1,led);
}
 if ((input(pin_b0)==0)&&(input(pin_b1)==0)) 
{output_high(led0);}
ad1=read_adc();
delay_us(100);
 if (ad1<200)  { output_low(led0);  }}
void main()
{float ad1;
char selection;
port_b_pullups(TRUE);
enable_interrupts(GLOBAL);
enable_interrupts(INT_timer1);
setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
set_timer1(3036);                                             
setup_adc_ports(AN0);
SETUP_ADC(ADC_CLOCK_INTERNAL);
SET_ADC_CHANNEL(0);
while(true)
{ }}


