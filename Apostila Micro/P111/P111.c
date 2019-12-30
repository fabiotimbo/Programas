#define led1 pin_d1
#include <18F4550.h>
#fuses HS,CPUDIV1,PLL5,USBDIV  //Configuração dos fusíveis
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
const int32 tm=3036;
const int16 pos_min=500, pos_max=2400 ;  //Valores de ajuste do servo
long int  angulo=0,tempo2;
int n2;
float tempo;
#int_timer1
void funcao_tempo()
{static boolean led;
static unsigned int32 n;
set_timer1(tm+get_timer1());
n++;
if (n==5)
{n=0;led=!led;output_bit(led1,led);}
}
void servo( int angulo)
{         do{
         output_high(pin_d2);
         tempo=(angulo* 0.00555555555);//converte para % em float
         tempo2=(tempo*(pos_max-pos_min)) + pos_min; //converte para tempo
         delay_us(tempo2);
         output_low (pin_d2);
         delay_ms(20);
         n2--;
         }while (n2>0);
         n2=20;
 }
void main()
{port_b_pullups(TRUE);
enable_interrupts(GLOBAL);
enable_interrupts(INT_timer1);
setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
set_timer1(tm);  
while(true)
{  char selecao;
   int  value, n2=20;
   unsigned int32 posicao;
   printf("\r\nSelecione a posicão:\r\n");
   printf("    1) 0° \r\n");
   printf("    2) 45° \r\n");
   printf("    3) 90° \r\n");
   printf("    4) 135° \r\n");
   printf("    5) 180° \r\n");
  do {
   selecao=getc();
  } while((selecao<'1')||(selecao>'5'));  
  if (selecao=='1')       { printf(" Posicao 1  "); servo(0); }
  if (selecao=='2')       { printf(" Posicao 2  "); servo(45); }
  if (selecao=='3')       { printf(" Posicao 3  "); servo(90); }
  if (selecao=='4')       { printf(" Posicao 4  "); servo(135);}                  
  if (selecao=='5')       { printf(" Posicao 5  "); servo(180);}

