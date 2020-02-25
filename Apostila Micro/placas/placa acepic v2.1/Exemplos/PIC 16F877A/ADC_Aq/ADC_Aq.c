/*******************************************************************************
*                     Kit de desenvolvimento ACEPIC PRO V2.0                   *
*                      ACEPIC Tecnologia e Treinamento LTDA                    *
*                               www.acepic.com.br                              * 
*                                                                              *
*Objetivo: Controle de temperatura e conversores AD AN0, AN1 e AN3             *
*Obs.:     Ligar chaves 1, 2, 3 e 7 do DIP DP1 e chave 4 do DIP DP2            *
********************************************************************************/
#include<16F877A.h> 
#device ADC = 10
#use delay (clock=8000000)        
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP 
 
#include "LCD8B.c"     //Diretiva de inclusão do arquivo LCD8B.c ao projeto
long int ad0,ad1,ad3; //Variáves para armazenamento da conversão
 
void main()           //Função principal 
{                                  
lcd_ini();          //Chama a função para inicialização do LCD     
               
SETUP_ADC_PORTS(AN0_AN1_AN3); //Configura as entradas analógicas RA0,RA1,RA3
SETUP_ADC(ADC_CLOCK_INTERNAL);           //Configura o conversor AD interno
Output_High(PIN_C2);                                //Liga ventoinha
while(true)                                      //Loop principal
   {

   SET_ADC_CHANNEL(0);                  //Configura o canal de leitura 0
   delay_us(100);                             //Tempo de ajuste do canal (necessário) 
   ad0 = READ_ADC();                       //Faz a conversão AD e a salva na variável ad0
   printf(lcd_escreve,"\fS0=%lu",ad0); //Mostra valor da conversão do canal 0

   SET_ADC_CHANNEL(1);   //Configura o canal de leitura 1
   delay_us(100);         //Tempo de ajuste do canal (necessário) 
   ad1 = READ_ADC();       //Faz a conversão AD e a salva na variável ad1

   SET_ADC_CHANNEL(3);             //Configura o canal de leitura 3
   delay_us(100);               //Tempo de ajuste do canal (necessário) 
   ad3 = READ_ADC();                 //Faz a conversão AD e a salva na variável ad3

   //Mostra valor da conversão dos canais 1 e 3
   printf(lcd_escreve,"\nS1=%lu - S3=%lu",ad1,ad3); 

   if (ad3>=80)                //Sendo ad3 >= 80...                 
      { 
         Output_High(PIN_C2); //Liga ventoinha
         Output_low(PIN_C1);  //Desliga aquecimento
         }
   if (ad3<=55)               //Sendo <= 55...            
         {
         Output_High(PIN_C1); //liga aquecimento
         Output_low(PIN_C2);  //Desliga ventoinha
         }
   
   delay_ms(1000);           //Atraso de 1 segundo       
   }
}                             

