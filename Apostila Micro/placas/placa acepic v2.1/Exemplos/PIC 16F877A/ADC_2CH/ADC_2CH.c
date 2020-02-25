#include<16F877A.h>             

#device ADC = 10                //Define 10 bits para o resultado da conversão AD

#use delay (clock=8000000)        

#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP //Configuração dos fusíveis

#include "LCD8B.c"      //Diretiva de inclusão do arquivo LCD8B.c ao projeto
 
unsigned int32 ad0,ad1;    //Variáves para armazenamento da conversão
unsigned int32 tensao;

 
void main()                 //Função principal 
{                                  
lcd_ini();             //Chama a função para inicialização do LCD     
               
SETUP_ADC_PORTS(RA0_RA1_RA3_ANALOG);  //Configura as entradas analógicas 
                                                                             //RA0,RA1,RA3
SETUP_ADC(ADC_CLOCK_INTERNAL);       //Configura o conversor AD interno

printf(lcd_escreve,"\f  CONVERSAO AD");

delay_ms(1500); 

while(true)                               //Loop principal
   {

   SET_ADC_CHANNEL(0);                     //Configura o canal de leitura 0
   delay_us(100);                                //Tempo de ajuste do canal (necessário) 
   ad0 = READ_ADC();                          //Faz a conversão AD e a salva na variável 
                                                                       //ad0
   tensao = (ad0*5000)/1023;                                                                     
   printf(lcd_escreve,"\fV1 = %04lu mV",tensao);    //Mostra valor da conversão do canal 0

   SET_ADC_CHANNEL(1);         //Configura o canal de leitura 1
   delay_us(100);         //Tempo de ajuste do canal (necessário) 
   ad1 = READ_ADC();             //Faz a conversão AD e a salva na variável 
                                                                       //ad1
   tensao = (ad1*5000)/1023;
   //Mostra valor da conversão dos canais 1 e 3
   printf(lcd_escreve,"\nV2 = %04lu mV",tensao); 
  
   delay_ms(500);                 //Atraso de 1 segundo       
   }
}        

