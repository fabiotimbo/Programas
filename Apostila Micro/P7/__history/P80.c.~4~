//luz vermelha ligada no pino d2
//luz amarela ligada no pino d1
//luz verde ligada no pin_d0
#include <18F4550.h> 
#byte port_d = 0xF83 
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000) 
unsigned int var[] = {0b1,0b10,0b100};
unsigned int16 tempos[] = {1250,3000,4000};
unsigned int *lampadas=var;
#int_timer0 
void funcao_tempo() 
{ 
static unsigned int32 n;
set_timer0(131+get_timer0());
n++; 
if (n==tempos[0])
{
port_d=*lampadas;
} 
if (n==tempos[1])
{
lampadas++;
port_d=*lampadas;
} 
if (n==tempos[2])
{
n=0;
lampadas++;
port_d=*lampadas;
lampadas=lampadas-2;
}} 
void main() 
{setup_timer_0 (RTCC_DIV_64|RTCC_INTERNAL | RTCC_8_BIT ); 
set_timer0(131); 
enable_interrupts(GLOBAL); 
enable_interrupts(INT_TIMER0); 
set_tris_d(0b00000000);
port_d=0;
while(true) 
{}}

