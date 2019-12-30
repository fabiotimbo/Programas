#define led_verde pin_d0
#define led_vermelho pin_d1
#include <18F4550.h>
#fuses HS,CPUDIV1,PLL5,USBDIV  //Configuração dos fusíveis
#use delay(clock=20000000)

void main()
{
while(true)
{
    if (input(pin_e0)==0) 
       {
       output_high(64);
       }
    else
       {
       output_low(pin_d0);
       }
      if (input(pin_e1)==0)
       {
       output_high (65);
       }
    else
       {
       output_low(pin_d1);
       }}}

