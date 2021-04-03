#define led1 pin_d1
#include <18F4550.h>
#fuses HS,CPUDIV1,PLL5,USBDIV  //Configuração dos fusíveis
#device adc=10
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
float ad1,pos_min=500,pos_max=2400,pos_servo2;
unsigned int32 pos_servo;
const int32 tm=3036;
#int_timer1
void funcao_tempo()
{
static boolean led;
static unsigned int32 n;
set_timer1(tm+get_timer1());
n++;
if (n==5)
{n=0;led=!led;output_bit(led1,led);}
}
void main()
{
setup_adc_ports(AN0_TO_AN2);
SETUP_ADC(ADC_CLOCK_INTERNAL); //Seta a origem do clock
SET_ADC_CHANNEL(0);
enable_interrupts(GLOBAL);
enable_interrupts(INT_timer1);
setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
set_timer1(tm);  
while(true)
{ad1=read_adc();
delay_ms(10);
pos_servo=((pos_max-pos_min)/1023)*ad1+pos_min;
pos_servo2=((180*ad1)/1023);        
         output_high(pin_d7);
         delay_us(pos_servo);
         output_low (pin_d7);
         delay_ms(20);}}

