void main()
{
LCD_Config(&PORTB,0,1,6,5,4,3,2);
LCD_CMD(LCD_CURSOR_OFF);
LCD_CMD(LCD_CLEAR);

Usart_Init(9600);

Lcd_out(1,1,"Enviando...");

Delay_ms(2000);

Usart_Write('T');
Usart_Write('E');
Usart_Write('S');
Usart_Write('T');
Usart_Write('E');

Lcd_out(2,1,"OK!!!");

while(1)
        {
        if (Usart_Data_Ready())
           {
           LCD_Out(2,7,"ok!");
           }
        }
}