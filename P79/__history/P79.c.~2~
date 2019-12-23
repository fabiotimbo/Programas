#define led1 pin_d1
#include <18F4550.h>
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP, CPUDIV1,PLL5,USBDIV  //Configuração dos fusíveis
#use delay(clock=20000000)
#int_timer1
void funcao_tempo()
{
static boolean flag;
static unsigned int32 n;
set_timer1(3036+get_timer1());
n++;
if (n==10)
{n=0;
flag=!flag;
output_bit(led1,flag);
}}
void main()
 {
 setup_timer_1 (T1_INTERNAL|T1_DIV_BY_8); 
 set_timer1(3036);                                                
 enable_interrupts(GLOBAL);
 enable_interrupts(INT_TIMER1);
 while(true)
 { } }

