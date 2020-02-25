char txt[7];
int adc;

void main()
{
ADCON1 = 0x04;

TRISC.F1 = 0;
TRISC.F2 = 0;

LCD_Config(&PORTB,0,1,6,5,4,3,2);
LCD_CMD(LCD_CURSOR_OFF);
LCD_CMD(LCD_CLEAR);

Lcd_out(1,1,"ADC:");

//PORTC.F1 = 1;
PORTC.F2 = 1;



while(1)
        {
        adc = ADC_READ(3);
        
        IntToStr(adc,txt);
        
        LCD_OUT(1,6,txt);
        
        if (adc > 100)
           {
           PORTC.F1 = 0;
           PORTC.F2 = 1;
           }
        if (adc < 80)
           {
           PORTC.F1 = 1;
           PORTC.F2 = 0;
           }
           

        
        delay_ms(1000);
        }
}