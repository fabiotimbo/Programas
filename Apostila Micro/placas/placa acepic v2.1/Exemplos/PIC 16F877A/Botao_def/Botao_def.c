/*******************************************************************************
*                     Kit de desenvolvimento ACEPIC PRO V2.0                   *
*                      ACEPIC Tecnologia e Treinamento LTDA                    *
*                               www.acepic.com.br                              * 
*                                                                              *
*Objetivo: Acionamento dos botões A,B,C e D do teclado matricial               *
*Obs.:     Ligar chave 2 do DIP DP2                                            *
********************************************************************************/
#include<16F877A.h> 
#use delay (clock=8000000)        
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP 

#define BOT1 PIN_B0
#define BOT2 PIN_B1
#define BOT3 PIN_B2
#define BOT4 PIN_B3
#define LED1 PIN_D0
#define LED2 PIN_D1
#define LED3 PIN_D2
#define LED4 PIN_D3

void main()
{
PORT_B_PULLUPS(true);      //Habilita resistores de Pull-Up
SET_TRIS_B(0X0F);         /*Configura os 4 bits menos significativos como entrada
                     ... e os 4 bits mais significativos como saída para a porta B*/

OUTPUT_B(0X0F);         //Limpa Porta B         


while (true)               //Loop principal
      {
   if (!input(BOT1)) OUTPUT_HIGH(LED1);    /*Se botão pino B0 pressionado
                                 ...acende led no pino D0*/
   if (!input(BOT2)) OUTPUT_HIGH(LED2);   /*Se botão pino B1 pressionado
                                 ...acende led no pino D1*/
   if (!input(BOT3)) OUTPUT_HIGH(LED3);   /*Se botão pino B2 pressionado
                                 ...acende led no pino D2*/
   if (!input(BOT4)) OUTPUT_HIGH(LED4);   /*Se botão pino B3 pressionado
                                 ...acende led no pino D3*/
      }   
}  
