#define EN PIN_E1			//Definimos o pino 1 da porta E como EN
#define RS PIN_E0			//Definimos o pino 0 da porta E como RS
#define DATA OUTPUT_D		//Definimos a saída para a porta D como DATA


void lcd_cmd(byte cmd)		//Função para envio de comandos para o LCD
{
 DATA(cmd);				//Coloca o conteúdo da variável cmd na porta D
 OUTPUT_HIGH(EN);			//Pulso alto (1) no pino EN (Pino 1 da porta E)
 OUTPUT_LOW(EN);			//Retorna a nível baixo (0) em EN
}


void lcd_envia_byte(boolean nivel,byte dado) 	//Função para envio de dados ou escrita para o 
 												//LCD
{
 OUTPUT_LOW(RS);			//Coloca em nível baixo o pino RS (Pino 0 da porta E)
 OUTPUT_BIT(RS,nivel);		//Coloca o pino RS no nível da variável nivel
 delay_us(100);				//Atraso de 100 us
 OUTPUT_LOW(EN);			//Coloca em nível baixo o pino EN
 lcd_cmd(dado);				//Chama a função lcd_cmd já com os dados a serem enviados   
 							//para a porta D
}



void lcd_pos_xy(byte x, byte y)	//Função de posicionamento do cursor			
{
 byte endereco;		 		//Variável de informação para o endereço do cursor 
 if (y!=1)			 		//Se o valor de y for 2
         endereco = 0xC0;	 	//então endereco vai ser igual a 0xC0 (endereço da segunda linha)
 else				 		//Senão
         endereco = 0x80;	 	//endereço vai ser igual a 0x80 (endereço da primeira linha) 
 endereco += x-1;         	 	//Aqui decrementa o valor da variável x e o resultado é somado com
 				 			//a variável endereço...
 lcd_envia_byte(0,endereco);  //Chama a função lcd_envia_byte, com o valor 0, informando para
 				  			  //o LCD que será enviado um dado e o dado está contido na
				  			  //variável endereço...		
 }
 
void lcd_escreve(char c)		//Função para envio dos caracteres e/ou dados para o LCD
{
 switch(c)						//comando switch com a variável c
 {
  case '\f' : lcd_envia_byte(0,1);	//Caso c seja ‘\f’, o dado 1 será enviado ao LCD para 
								//limpar todo o seu conteúdo.
                  delay_ms(2);		//Atraso de 2 ms
                  break;				//Comando break, terminou o processo acima, já não testa 
 								//nenhum outro caso... 
  case '\n' : 					//Caso c seja ‘\n’
  case '\r' : lcd_pos_xy(1,2);		//ou ‘\r’, muda o cursor para a segunda linha do LCD
                  break;				//Comando break
  case '\b' : lcd_envia_byte(0,0x10); //Caso c seja ‘\b’ então desloca o cursor para a esquerda
                   break;				//Comando break
  default    : lcd_envia_byte(1,c);	//caso seja um caractere qualquer, então este será escrito no 
 									//LCD pela função lcd_envia_byte…
                   break;				//Comando break
 }
}  



void lcd_ini()						//Função de inicialização do LCD
{
 byte conta;						//Variável de contagem 
 	
 DATA(0x00);						//Coloca na porta D o valor 0x00
 OUTPUT_LOW(RS);					//Coloca em nível baixo o pino RS
 OUTPUT_LOW(EN);					//Coloca em nível baixo o pino EN
 
 delay_ms(15);						//Atraso de 15ms
 
 for (conta=1;conta<=3;conta++)	//Para conta = 1 até conta = 3, ou seja executará 3 vezes os  
 									//comandos abaixo
      {
      lcd_cmd(0x30);					//Envia o comando 0x30 para o LCD
      delay_ms(5);					//Atraso de 5ms
      }
 
 lcd_cmd(0x38); 		//Escreve comando para interface de 8 vias de dados
 lcd_cmd(0x01); 		//Escreve comando para limpar todo o display
 
 delay_ms(1);			//Atraso de 1ms
 
 lcd_cmd(0x0C); 		//Escreve comando para ligar o display sem cursor
 lcd_cmd(0x06); 		//Escreve comando para incrementar automaticamente à direita
} 
