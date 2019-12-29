#include <18F4550.h>
#fuses HS, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use standard_io(B) //comentar linha caso a biblioteca do LCD seja diferente
#define use_portB_lcd TRUE //comentar linha caso a biblioteca do LCD seja diferente
#define LCD_TYPE 2
#include <LCD.c>
void main()
{lcd_init();
while(true)
{
   char selection;
   int value;
   unsigned int32 vel;
   printf("\r\nSelecione a rotacao:\r\n");
   printf("    1) 0 \r\n");
   printf("    2) 20 \r\n");
   printf("    3) 50 \r\n");
   printf("    4) 80 \r\n");
   printf("    5) 100 \r\n");
  setup_timer_2(T2_DIV_BY_4, 249, 1);
  set_pwm1_duty(value);
  lcd_gotoxy(1,1);
  printf(lcd_putc,"\f Motor CC ");
  lcd_gotoxy(1,2);
  printf(lcd_putc," Velocidade=%lu ",vel);
   do {
   selection=getc();
  } while((selection<'1')||(selection>'6'));
   setup_ccp1(CCP_PWM);
   switch(selection) {
     case '1' : value=0;
                vel=0;  
                break;
     case '2' : value=50;
                vel=20;
                break;
     case '3' : value=125;
                vel=50;
                break;
     case '4' : value=200;
                vel=80;
                break;
     case '5' : value=250;
                vel=100;
                break;
   }}}

