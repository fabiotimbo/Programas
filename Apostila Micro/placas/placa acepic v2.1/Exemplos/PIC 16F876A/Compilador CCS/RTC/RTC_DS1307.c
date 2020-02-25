/*******************************************************************************
*                     Kit de desenvolvimento ACEPIC PRO V2.0                   *
*                      ACEPIC Tecnologia e Treinamento LTDA                    *
*                               www.acepic.com.br                              * 
*                                                                              *
*Objetivo: Teste interrupção Timer 0 - clock interno                           *
*Obs.:     Ligar as chaves 2, 4 e 6 do DIP DP3 e chave 4 do DIP DP4            *
*          Para acertar o relógio:                                             *
*          DIA:  Botão INT_TMR1                                                *
*          MÊS:  Botão BT_CCP                                                  *
*          HORA: Botão 7,8,9 ou C do teclado matricial                         *
*          MINUTOS: Botão *,0,# ou D do tecla matricial                        *
********************************************************************************/
#include<16F877A.h>                  //Aqui é incluso o header (*.h)  para o microcontrolador utilizado.
#use delay (clock=8000000)        //Aqui definimos a frequência do cristal para cálculo dos delays
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP //Configuração dos fusíveis
#include "ds1307.c"
#include "LCD_4B.c"

int ajuste=0;
char msg[5][5] = {"Dia", "Mes", "Ano", "Hor", "Min" };					 

void main()
{
  BYTE sec;
  BYTE min;
  BYTE hrs;
  BYTE day;
  BYTE month;
  BYTE yr;
  BYTE dow;

  ds1307_init();
 
  // Set date for -> 10 de janeiro de 2011 - Segunda
  // Set time for -> 13:11:00
  ds1307_set_date_time(10,1,11,2,13,11,00);
  LCD_Ini();

   printf(lcd_escreve,"\f");
 
  while(true)
  {
    ds1307_get_date(day,month,yr,dow);
    ds1307_get_time(hrs,min,sec);

    lcd_pos_xy(1,1);

   if (ajuste != 0) 
      printf(lcd_escreve,"\%02d/\%02d/\%02d Set:%s",day,month,yr,msg[ajuste - 1]);  
    else
      printf(lcd_escreve,"\%02d/\%02d/\%02d        ",day,month,yr);
    lcd_pos_xy(1,2);
    printf(lcd_escreve,"\%02d:\%02d:\%02d", hrs,min,sec);
    
     if (input(PIN_C2))
      {
      ajuste++;
      if (ajuste > 5) ajuste = 0;
      delay_ms(300);
      } 
    
     
   if (input(PIN_A4))
      {
      if (ajuste == 1)  {
                              day++;
                              if (day>31) day = 1;
      } 
      if (ajuste == 2)  {
                              month++;
                              if (month>12) month = 1; 
      } 
      if (ajuste == 3)   { 
                              yr++;
                              if (yr>20) yr = 11;
      } 
      if (ajuste == 4)   { 
                               hrs++;
     					   if (hrs>23) hrs = 0;
      }    
       if (ajuste == 5)   { 
                                min++;
                                if (min>59) min = 0;
      }                                                                           
      ds1307_set_date_time(day,month,yr,dow,hrs,min,sec);
      delay_ms(300);
      }
    
  }
} 
