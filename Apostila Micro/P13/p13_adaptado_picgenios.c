#include <18F4550.h>
#fuses HS, CPUDIV1,PLL5,USBDIV
#device adc=10
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

//Define os pinos do LCD e biblioteca para placa PICSIMLAB4
#define LCD_DB0   PIN_D0
#define LCD_DB1   PIN_D1
#define LCD_DB2   PIN_D2
#define LCD_DB3   PIN_D3
#define LCD_DB4   PIN_D4
#define LCD_DB5   PIN_D5
#define LCD_DB6   PIN_D6
#define LCD_DB7   PIN_D7
#define LCD_E     PIN_E1
#define LCD_RS    PIN_E2
#include <flex_lcd2.c>
//Fim das definições para lcd
int32 u,d,c,null;
unsigned int32 selection;
unsigned int32 n=0;


void main()
{
lcd_init();
while(1){
lcd_gotoxy(1,1);
printf(lcd_putc," Envio de valor\r\n ");
printf(lcd_putc," pela serial ");
delay_ms(200);
do
{
printf("\r\nEnvie um valor entre 000 e 100:(3 algarismos)\r\n");
c=getc()-48; //48 corresponde ao valor do caractere 0 da tabela ASCII.
d=getc()-48;//48 corresponde ao valor do caractere 0 da tabela ASCII.
u=getc()-48;//48 corresponde ao valor do caractere 0 da tabela ASCII.\
//null=getc()-48;//descarta caractere nulo/indevido caso seja enviado pela serial
selection=(100*c)+(10*d)+u;
printf("\r\nnumero=%lu\r\n",selection);
if (selection>100||selection<0) {printf("\r\nValor incorreto!!\r\n");}// faixa de valores aceitáveis
} while(selection>100||selection<0);
//lcd_gotoxy(1,1);
{printf("\r\nValor ok\r\n");}
printf(lcd_putc,"\fsetpoint %lu",selection);
delay_ms(2000);
c=0;d=0;u=0;
}}

