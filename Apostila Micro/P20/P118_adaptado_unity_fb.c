#define led0 pin_d0 
#define led1 pin_d1 
#define mpasso pin_d2
#define dir pin_d3
#include <18F4550.h>
#device adc=10
#fuses HS,PLL5,CPUDIV1,nowdt ,USBDIV//Configuração dos fusíveis 48Mhz
#use delay(clock=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)
const int32 tm=60536;
boolean estado_anterior=0;
int32 valor;
int32 a[10],temp;
static int pos=-1;

#int_rda
void serial ()
{
temp=getc();
if (temp!='\n')
{
pos++;
a[pos]=temp;
}
else
{
pos=-1;
//printf("%c%c%c%c\r\n",a[0],a[1],a[2],a[3]);
valor=(a[0]-48)*1000+(a[1]-48)*100+(a[2]-48)*10+(a[3]-48);
printf("%lu\r\n",valor);//utilizar a variável valor como o feedback da altura
}}


#int_timer1
void funcao_tempo()
{
static boolean led=1,led2=1;
static unsigned int32 n;
set_timer1(tm+get_timer1());
n++;
if (n==20)
{
n=0;
if ((input(pin_b0)==0)) 
{
led=!led;//divide a frequência por 2 poque passa só meio período ligado
output_bit(led1,led);
output_bit(mpasso,led);
if (led2==0) {printf("s\r\n");}
if (led2==1) {printf("d\r\n");}


}}
if (input(pin_b1)==0)
{
estado_anterior=1;
}
if((input(pin_b1)==1)&&(estado_anterior==1))
{
estado_anterior=0;
led2=!led2;
output_bit(dir,led2);
output_bit(led0,led2);
}


}
void main()
{
port_b_pullups(TRUE);
output_d(0);
enable_interrupts(GLOBAL);
enable_interrupts (global);
enable_interrupts (int_rda);
enable_interrupts(INT_timer1);
setup_timer_1(T1_INTERNAL|T1_DIV_BY_2);
set_timer1(tm);                                             
while(true)
{ 

}
}

