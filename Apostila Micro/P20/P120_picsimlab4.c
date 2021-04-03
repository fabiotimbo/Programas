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
#include <flex_lcd.c>
//Fim das definições para lcd

int opcao = 0;
float ad1;
int value;


void executarModo(int op) {
      
   switch(op) {
      
      case 0://
         output_bit(PIN_C5, 1); // aquecedor por resistor 
         output_bit(PIN_C1, 1); // buzzer: jumper para ouvir
         output_bit(PIN_C2, 0); // ventoinha
         printf(lcd_putc, "\f1:AQUECE");
         delay_ms(2000);
         break;
      
      case 1:
         output_bit(PIN_C5, 0); //aquecedor por resistor
         output_bit(PIN_C1, 0); // buzzer
         output_bit(PIN_C2, 0); // ventoinha   
         printf(lcd_putc, "\f2:ESFRIA AMB.");
         delay_ms(2000);
         break;
      
      case 2:
         output_bit(PIN_C5, 0); //aquecedor por resistor 
         output_bit(PIN_C1, 0);// buzzer
         output_bit(PIN_C2, 1); // ventoinha
         printf(lcd_putc, "\f3:ESFRIA VENT.");
         delay_ms(2000);
         break;
   }
   
}


float32 lm;
unsigned int32 ad0;


void main()
{
enable_interrupts(GLOBAL);
lcd_init();
lcd_gotoxy(1,1);
printf(lcd_putc,"\f Sensor \r\n");
printf(lcd_putc," LM35");
delay_ms(2000);
setup_adc_ports(an0_to_an2);
setup_adc(adc_clock_internal);

while(true)
{

//Altera  modo de operação

      if ( input(PIN_B0) == 0 ) {
         if (opcao > 0) {
            opcao--;
         }
         executarModo(opcao);
         while ( input(PIN_B0) == 0 );
      }
      if ( input(PIN_B1) == 0 ) {
         if (opcao < 2) {
            opcao++;
         }
         executarModo(opcao);
         while ( input(PIN_B1) == 0 );
      }
//Lê temperatura
set_adc_channel(2);// canal 2 lm35
lm=read_adc();
delay_ms(10);
ad0=lm*0.488758;//igual a (5/1023)*100
lcd_gotoxy(1,1);
printf(lcd_putc,"\f   Temperatura \r\n" );
printf(lcd_putc,"      %lu %cC",ad0,0xdf);

delay_ms(500);}


}

