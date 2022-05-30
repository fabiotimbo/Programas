#include <18F4550.h>
#fuses HS, CPUDIV1 ,PLL5 ,USBDIV
#use delay (clock=20000000)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)
#use standard_io(B) //comentar linha caso a biblioteca do LCD seja diferente
#define use_portB_lcd TRUE //comentar linha caso a biblioteca do LCD seja diferente
#define LCD_TYPE 2
#include <LCD.c>
int32 u,d,c,null;
unsigned int32 selection;
void main()
{
lcd_init();
while(1){
lcd_gotoxy(1,1);
printf(lcd_putc," Envio de valor ");
lcd_gotoxy(1,2);
printf(lcd_putc," pela serial ");
delay_ms(200);
do
{
printf("\r\nEnvie um valor entre 000 e 100:(3 algarismos)\r\n");
c=getc()-48; //48 corresponde ao valor do caractere 0 da tabela ASCII.
d=getc()-48;//48 corresponde ao valor do caractere 0 da tabela ASCII.
u=getc()-48;//48 corresponde ao valor do caractere 0 da tabela ASCII.\
//=getc()-48;//descarta caractere nulo/indevido caso seja enviado pela serial
selection=(100*c)+(10*d)+u;
printf("\r\nnumero=%lu\r\n",selection);
if (selection>100||selection<0) {printf("\r\nValor incorreto!!\r\n");}// faixa de valores aceitáveis
} while(selection>100||selection<0);
lcd_gotoxy(1,1);
{printf("\r\nValor ok\r\n");}
printf(lcd_putc,"\fsetpoint %lu",selection);
delay_ms(2000);
c=0;d=0;u=0;
}}


