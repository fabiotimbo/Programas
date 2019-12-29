#define led1 pin_d1
#include <18F4550.h>
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP, CPUDIV1, PLL5,USBDIV //Configuração dos fusíveis
#use delay(clock=20000000)
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
}
}
void main()
 {
 setup_timer_0 (RTCC_DIV_64|RTCC_INTERNAL | RTCC_8_BIT ); //8 bits
 set_timer0(131);                                             
 enable_interrupts(GLOBAL);
 enable_interrupts(INT_TIMER0);
 while(true)
 { } }

