#include <18F4550.h>
#fuses HS, CPUDIV1,PLL5,USBDIV
#device adc=10
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
//Define os pinos do LCD e biblioteca para placa PICSIMLAB4
#define LCD_DB0 PIN_D0
#define LCD_DB1 PIN_D1
#define LCD_DB2 PIN_D2
#define LCD_DB3 PIN_D3
#define LCD_DB4 PIN_D4
#define LCD_DB5 PIN_D5
#define LCD_DB6 PIN_D6
#define LCD_DB7 PIN_D7
#define LCD_E PIN_E1
#define LCD_RS PIN_E2
#include <flex_lcd2.c>
//Fim das definições para lcd
unsigned int32 n=0;
void main()
{
enable_interrupts(GLOBAL);
lcd_init();
lcd_gotoxy(1,1);
printf(lcd_putc,"\f Teste\r\n");
printf(lcd_putc," Display lcd16x2");
delay_ms(2000);
while(true)
{
lcd_gotoxy(1,1);
printf(lcd_putc,"\f Temporizador \r\n", );
printf(lcd_putc," %lu ",n);delay_ms(1000);
n=n+1;}}
