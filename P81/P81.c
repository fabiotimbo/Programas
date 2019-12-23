#define led1 pin_d1
#include <18F4550.h>
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP, CPUDIV1,PLL5,USBDIV  //Configuração dos fusíveis
#use delay(clock=20000000)
#int_timer2
void funcao_tempo()
{
static boolean flag;
static unsigned int32 n;
n++;
if (n==1250)
{n=0;
flag=!flag;
output_bit(led1,flag);
}}
void main()
 { setup_timer_2(T2_DIV_BY_16, 249, 1);
 enable_interrupts(GLOBAL);
 enable_interrupts(INT_TIMER2);
 while(true)
 { } }

