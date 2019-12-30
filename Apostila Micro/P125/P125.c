#define led_verde pin_d0
#define led_vermelho pin_d1
#include <18F4550.h>
#fuses HS,CPUDIV1,PLL5,USBDIV
#device adc=10
#use delay(clock=20000000)
float ad1,lux;
void main()
{setup_adc_ports(an0);
SETUP_ADC(ADC_CLOCK_INTERNAL); //Seta a origem do clock
SET_ADC_CHANNEL(0);
while(true)
{ad1=read_adc();
delay_ms(10);
  ad1=ad1*0.0048875;
  if (ad1>2 && ad1<2.8)   {      lux=(3936.4-(1249*ad1))/0.8;   }
  if (ad1>=2.8 && ad1<=3.8)   {  lux=2057.2-494*ad1;   }
  if (ad1>3.8)   {      lux=(900-180*ad1)/1.2;   }
      if (lux>=20) 
       {       output_high(led_vermelho);
       }
    else
       {       output_low(led_vermelho);
       }
    if (lux<20) 
       {       output_high(led_verde);
       }
    else
       {       output_low(led_verde);
       }}}

