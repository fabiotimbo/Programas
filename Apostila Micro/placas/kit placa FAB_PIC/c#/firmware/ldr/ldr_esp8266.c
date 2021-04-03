#define led1 pin_d1
#include <18F4550.h>
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP, CPUDIV1, PLL5,USBDIV 
#device adc=10
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
float32 lm,lux;
unsigned int32 ad0,lux2;
int m,c,d,u;
void protocolo()
{
lm=read_adc();
delay_ms(10);
lm=lm*0.0048875;
if (lm>2 && lm<2.8) { lux=(3936.4-(1249*lm))/0.8; }
if (lm>=2.8 && lm<=3.8) { lux=2057.2-494*lm; }
if (lm>3.8) { lux=(900-180*lm)/1.2; }
delay_ms(10);
lux2=lux;
m= lux2/1000;
c=((lux2%1000)/100);
d=((lux2%1000)%100)/10;
u=(((lux2%1000)%100)%10)/1;
delay_ms(10);
//printf(" %f ",lux);
printf("&");
delay_ms(10);
printf("%d",m);
delay_ms(10);
printf("%d",c);
delay_ms(10);
printf("%d",d);
delay_ms(10);
printf("%d",u);
delay_ms(10);
printf("f");
delay_ms(10);
printf("f");
delay_ms(10);
printf("\r\n");
delay_ms(10);
}

#int_timer0
void funcao_tempo()
{
static boolean flag;
static unsigned int32 n;
set_timer0(131+get_timer0());
n++;
if (n==625)
{
n=0;
flag=!flag;
output_bit(led1,flag);
protocolo();
}
}

void main()
{
setup_timer_0 (RTCC_DIV_64|RTCC_INTERNAL | RTCC_8_BIT ); //8 bits
set_timer0(131);                                             
enable_interrupts(GLOBAL);
enable_interrupts(INT_TIMER0);
setup_adc_ports(an0);
setup_adc(adc_clock_internal);
set_adc_channel(0);
while(true)
{ } }

