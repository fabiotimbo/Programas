 #define led0 pin_d0 
#define led1 pin_d1 
#define mpasso pin_d2
#define dir pin_d3
#include <16F877A.h>
#device adc=10
#fuses nowdt,put,brownout, nolvp,hs
#use delay(clock=20000000)
int32 tm=60536;
boolean estado_anterior=0;
#int_timer1
void funcao_tempo()
{
float ad1;
float ad_1;
ad1=read_adc();
//65036/1023
ad_1=(((ad1*63.5738025))+4);
tm=ad_1;
static boolean led=1,led2=1;
static unsigned int32 n;
set_timer1(tm+get_timer1());
n++;
if (n==5)
{
n=0;
if ((input(pin_b0)==0)) 
{
led=!led;//divide a frequência por 2 poque passa só meio período ligado
output_bit(led1,led);
output_bit(mpasso,led);
}}

if (input(pin_b1)==1)
{
led2=1;
output_bit(dir,led2);
output_bit(led0,led2);

}

else
{
led2=0;
output_bit(dir,led2);
output_bit(led0,led2);
}}
void main()
{port_b_pullups(TRUE);
output_d(0);
enable_interrupts(GLOBAL);
enable_interrupts(INT_timer1);
setup_timer_1(T1_INTERNAL|T1_DIV_BY_2);
set_timer1(tm); 

setup_adc_ports( RA0_RA1_RA3_ANALOG );
setup_adc(ADC_CLOCK_INTERNAL); //Seta a origem do clock
set_adc_channel(0);
while(true)
{}}
