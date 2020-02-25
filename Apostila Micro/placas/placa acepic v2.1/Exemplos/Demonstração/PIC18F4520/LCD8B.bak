#define EN PIN_E1
#define RS PIN_E0
#define DATA OUTPUT_D

void lcd_cmd(byte cmd)
{
 DATA(cmd);
 OUTPUT_HIGH(EN);
 OUTPUT_LOW(EN);
}

void lcd_envia_byte(boolean endereco,byte dado)
{
 OUTPUT_LOW(RS);
 OUTPUT_BIT(RS,endereco);
 delay_us(100);
 OUTPUT_LOW(EN);
 lcd_cmd(dado);
 OUTPUT_LOW(RS);
}

void lcd_pos_xy(byte x, byte y)
{
 byte endereco;
 if (y!=1)
         endereco = 0xC0;
 else
         endereco = 0x80;
 endereco += x-1;         
 lcd_envia_byte(0,endereco);
 }
 
void lcd_escreve(char c)
{
 switch(c)
 {
  case '\f' : lcd_envia_byte(0,1);
              delay_ms(2);
              break;
  case '\n' : 
  case '\r' : lcd_pos_xy(1,2);
              break;
  case '\b' : lcd_envia_byte(0,0x10);
              break;
  default    : lcd_envia_byte(1,c);
              break;
 }
}  

void lcd_ini()
{
 byte conta;
 
 DATA(0x00);
 OUTPUT_LOW(RS);
 //OUTPUT_LOW(RW);
 OUTPUT_LOW(EN);
 
 delay_ms(15);
 
 for (conta=1;conta<=3;conta++)
      {
      lcd_cmd(0x30);
      delay_ms(5);
      }
 
 lcd_cmd(0x38); //Escreve comando para interface de 8 vias de dados
 lcd_cmd(0x01); //Escreve comando para limpar todo o display
 
 delay_ms(1);
 
 lcd_cmd(0x0C); //Escreve comando para ligar o display sem cursor
 lcd_cmd(0x06); //Escreve comando para incrementar automaticamente á direita
} 
 

