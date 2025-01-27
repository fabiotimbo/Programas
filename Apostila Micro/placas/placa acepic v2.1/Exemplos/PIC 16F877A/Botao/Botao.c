/*******************************************************************************
*                     Kit de desenvolvimento ACEPIC PRO V2.0                   *
*                      ACEPIC Tecnologia e Treinamento LTDA                    *
*                               www.acepic.com.br                              * 
*                                                                              *
*Objetivo: Acionamento dos bot�es A,B,C e D do teclado matricial               *
*Obs.:     Ligar chave 2 do DIP DP2                                            *
********************************************************************************/
#include<16F877A.h> 
#use delay (clock=8000000)        
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP 

void main()
{
PORT_B_PULLUPS(true);      //Habilita resistores de Pull-Up
SET_TRIS_B(0X0F);         /*Configura os 4 bits menos significativos como entrada
                     ... e os 4 bits mais significativos como sa�da para a porta B*/

OUTPUT_B(0X0F);         //Limpa Porta B         


while (true)               //Loop principal
      {
   if (!input(PIN_B0)) OUTPUT_HIGH(PIN_D0);    /*Se bot�o pino B0 pressionado
                                    ...acende led no pino D0*/
   if (!input(PIN_B1)) OUTPUT_HIGH(PIN_D1);   /*Se bot�o pino B1 pressionado
                                    ...acende led no pino D1*/
   if (!input(PIN_B2)) OUTPUT_HIGH(PIN_D2);   /*Se bot�o pino B2 pressionado
                                    ...acende led no pino D2*/
   if (!input(PIN_B3)) OUTPUT_HIGH(PIN_D3);   /*Se bot�o pino B3 pressionado
                                    ...acende led no pino D3*/
      }   
}  
