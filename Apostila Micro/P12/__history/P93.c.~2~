#define led pin_d0 
#include <18F4550.h>
#fuses HS,CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
void main()
{
while(true)
   {
char selection;
printf("\r\nSelecione:\r\n");
printf(" 1) L - ligar led \r\n");
printf(" 2) D - desligar led \r\n");
do    {
      selection=getc();
      } while (!((selection=='L')||(selection=='D')));
if (selection=='L')
      {output_high(led);}
else
      {output_low(led);}
   }
}

