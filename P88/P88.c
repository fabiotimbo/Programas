#define sensor_baixo pin_e0
#define sensor_alto pin_e1
#define bomba pin_d0
#include <18F4550.h>
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
int aciona_bomba (int alto, int baixo) {
if ((alto==0)&&(baixo==0)) {return 0;}
if ((alto==1)&&(baixo==1)) {return 1;}
}
void main()
{
int estado;
int x,y;
while(true)
{
if (input(sensor_alto)==1) {x=1;} else {x=0;}
if (input(sensor_baixo)==1) {y=1;} else {y=0;}
estado = aciona_bomba(x,y);
output_bit(bomba,estado);
}}

