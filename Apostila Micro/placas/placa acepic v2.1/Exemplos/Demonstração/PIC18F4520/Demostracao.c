/*******************************************************************************
*                     Kit de desenvolvimento ACEPIC PRO V2.0                   *
*                      ACEPIC Tecnologia e Treinamento LTDA                    *
*                               www.acepic.com.br                              * 
*                                                                              *
*Objetivo: Demonstração do Kit ACEPIC PRO V2.0                                 *
*                                                                              *
*Obs.: Chaves que devem ser acionadas                                          *
*      1 e 8 do DIP DP1                                                        *                
*      1, 2, 3, 5, 6, 7 e 8 do DIP DP2                                         *
*      2 e 3 do DIP DP3                                                        *
*      3 do DIP DP4                                                            *
********************************************************************************/
#include<18F4520.h> 
#device ADC = 10
#use delay (clock=8000000)
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP 
#use rs232(baud=9600, xmit = PIN_C6, rcv = PIN_C7)

#include "LCD8B.c"
#include "12Keys.c"
#include "2404.c"

#use fast_io(a)     

int16 adc; // d1, d2, d3, d4;

/*Matriz de 10 posições contendo o valor a ser enviado para a porta D a fim de
   mostrar o dígito referente nos displays */
int digito[10] =
               {0b00111111,    //Dígito 0
                0b00000110,    //Dígito 1
                0b01011011,    //Dígito 2
                0b01001111,    //Dígito 3
                0b01100110,    //Dígito 4
                0b01101101,    //Dígito 5
                0b01111101,    //Dígito 6
                0b00000111,    //Dígito 7
                0b01111111,    //Dígito 8
                0b01101111     //Dígito 9
               };
               
void main()
 {
  int i, leds;
  int1 le_adc=0;
 
  port_b_pullups(True);
  
  set_tris_a(0x01);

  SETUP_ADC_PORTS(AN0);       //Configurada a entrada analógica, somente a entrada RA0
  SETUP_ADC(ADC_CLOCK_INTERNAL);    //Configurado o conversor AD interno   
  SET_ADC_CHANNEL(0);            //Configurado o canal de leitura 0
  delay_us(10);
  
  output_low(PIN_E0);
  output_low(PIN_E1);
  output_low(PIN_E2);
  output_low(PIN_A5);
  
  lcd_ini();
    
  printf("DEMONSTRACAO KIT DE DESENVOLVIMENTO ACEPIC PRO V2.0\n\r");
  printf("===================================================\n\r");
  printf("\n\rMicrocontrolador PIC 18F4520;\r\n");
  printf("Baudrate = 9600 BPS;\r\n");
  printf("DataBits = 8.\r\n");
  printf("\r\n");
      
  printf(lcd_escreve,"\f   PIC18F4520");
  printf(lcd_escreve,"\n  DEMONSTRACAO");
  
  delay_ms(1000);
  
  printf(lcd_escreve,"\fDigite uma tecla"); 
  printf("Digite uma tecla.\r\n"); 
  printf("1- LEDS.\r\n");
  printf("2- DISPLAY DE 7 SEGMENTOS.\r\n");
  printf("3- CONVERSOR A/D.\r\n");
  printf("4- EEPROM EXTERNA.\r\n");
  printf("5- RELE.\r\n");
  printf("6- LED PWM2\r\n");
  
  tecla_pres=0;
   
  while(TRUE)
              {
               tecla = trata_teclas();
               if (tecla_pres)
                  {
                  output_high(PIN_C2);
                  delay_ms(50);
                  output_low(PIN_C2);
                  
                  printf(lcd_escreve,"\f    TECLA %c.",tecla);
                  printf("TECLA %c.\r\n",tecla);
                  if (tecla=='1')
                      {
                      printf(lcd_escreve,"\n      LEDS");
                      printf("LEDS.\r\n");                    
                      output_low(PIN_E0);
                      output_low(PIN_E1);
                      output_low(PIN_E2);
                      output_low(PIN_A5);
                      leds = 0;
                      for (i=0;i<=7;i++)
                          {
                          output_d(leds);
                          delay_ms(500);
                          leds=~leds;
                          }
                                            
                      }
                  if (tecla=='2')
                     {
                     printf(lcd_escreve,"\n DISPLAY 7 SEG.");
                     printf("DISPLAY 7 SEG.\r\n");
                     for (i=0;i<=2;i++)
                         { 
                         OUTPUT_D(digito[1]);   //Coloca na Porta D o valor referente ao dígito 0
                         OUTPUT_A(0x00); 
                         OUTPUT_E(0X01);      //Liga o Display 1 e desliga os demais
                         delay_ms(500);
                     
                         OUTPUT_D(digito[2]);   //Coloca na Porta D o valor referente ao dígito 1
                         OUTPUT_E(0X02);      //Liga o Display 2 e desliga os demais
                         delay_ms(500);
                     
                         OUTPUT_D(digito[3]);   //Coloca na Porta D o valor referente ao dígito 2
                         OUTPUT_E(0X04);      //Liga o Display 3 e desliga os demais
                         delay_ms(500);
                     
                         OUTPUT_D(digito[4]);   //Coloca na Porta D o valor referente ao dígito 2
                         OUTPUT_E(0x00); 
                         OUTPUT_A(0X20);      //Liga o Display 4 e desliga os demais
                         delay_ms(500);
                         }
                     output_low(PIN_E0);
                     output_low(PIN_E1);
                     output_low(PIN_E2);
                     output_low(PIN_A5);
                     
                    
                     }
                  if (tecla=='3')
                     { 
                     printf(lcd_escreve,"\n  CONVERSOR AD");
                     printf("CONVERSOR AD.\r\n");
                     
                     delay_ms(1000);
                     le_adc=~le_adc;
                     if (!le_adc);                         
                     else
                        {
                        printf(lcd_escreve,"\fDIGITE 3 P/ SAIR");
                        printf("DIGITE NOVAMENTE 3 P/ SAIR.\r\n");
                        delay_ms(2000);
                        printf(lcd_escreve,"\fATUE NO POT ADC1");
                        printf("ATUE NO POT ADC1.");
                        }
                     
                     }
                     
                  if (tecla=='4')
                     {
                     printf(lcd_escreve,"\n EEPROM EXTERNA");
                     printf("EEPROM EXTERNA.\r\n");
                     delay_ms(1000);
                     init_ext_eeprom();
                     delay_ms(50);
                     printf(lcd_escreve,"\fEscrevendo: 0x43");
                     printf(lcd_escreve,"\nAguarde...");
                     
                     write_ext_eeprom(0x10,0x43);

                     delay_ms(1500);
  
                     printf(lcd_escreve,"\fLeitura em 0x10:");
                     printf(lcd_escreve,"\n%x - ASCII: %c",read_ext_eeprom(0x10),read_ext_eeprom(0x10));
                     delay_ms(1500);
                     
                     }
                     
                  if (tecla=='5')
                     {
                     printf(lcd_escreve,"\n      RELE");
                     printf("RELE.\r\n");
                     for (i=0;i<=2;i++)
                         { 
                         output_high(PIN_C0);
                         delay_ms(1000);
                         output_low(PIN_C0);
                         delay_ms(1000);
                         }
                          
                     }    
                     
                  if (tecla=='6')
                     {
                     printf(lcd_escreve,"\n    LED PWM2"); 
                     printf("LED PWM2.\r\n");
                     for (i=0;i<=2;i++)
                         { 
                         output_high(PIN_C1);
                         delay_ms(1000);
                         output_low(PIN_C1);
                         delay_ms(1000);
                         }
                     
                     }    
                  
                  if (tecla=='7')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000); 
                       
                     }
                     
                  if (tecla=='8')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);    
                     }
                     
                  if (tecla=='9')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);     
                     }
                     
                  if (tecla=='0')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);    
                     } 
                     
                  if (tecla=='A')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);   
                     }   
                     
                  if (tecla=='B')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);    
                     }
                  
                  if (tecla=='C')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);    
                     }
                  
                  if (tecla=='D')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);    
                     }
                  
                  if (tecla=='E')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);    
                     }
                     
                  /*if (tecla=='*'); //Tecla '*'
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);     
                     }
                  
                  if (tecla=='#')
                     {
                     printf(lcd_escreve,"\n    SEM ACAO");
                     printf("SEM ACAO.\r\n");
                     delay_ms(1000);     
                     }   */
                                  
                  printf("Digite uma tecla.\r\n"); 
                  printf(lcd_escreve,"\fDigite uma tecla"); 
                  tecla_pres = 0;      
               } 
               
             if (le_adc)
                     { 
                     adc = READ_ADC();
                     printf(lcd_escreve,"\nLENDO ADC1: %04lu",adc);
                     printf("LENDO ADC1: %04lu\r\n",adc);
                     delay_ms(500);
                     }              
             }
}

