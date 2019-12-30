#line 1 "C:/Users/Fabio/Dropbox/Orientações em andamento/Placa USB/ControladorUSB/ControladorUSB/Firmware - 8MHz/ControladorUSB.c"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/built_in.h"
#line 5 "C:/Users/Fabio/Dropbox/Orientações em andamento/Placa USB/ControladorUSB/ControladorUSB/Firmware - 8MHz/ControladorUSB.c"
unsigned char HidReadBuff[64] absolute 0x500;
unsigned char HidWriteBuff[64] absolute 0x540;
unsigned char Reserve4thBankForUSB[256] absolute 0x400;

enum Comandos {None=0, Analog, DigitalIn, DigitalOut, PWM};

char cmd = None;

void interrupt()
{
 Usb_Interrupt_Proc();
}

void CheckCommand()
{
 if(cmd == None)
 {
 if(HidReadBuff[0] !=  0x0F ) return;
 cmd = HIDReadBuff[1];
 }
}

void EntradaAnalogica()
{
unsigned analogVal;
 HIDWriteBuff[1] = Analog;
analogVal = ADC_get_sample(0);
 HIDWriteBuff[2] =  ((char *)&analogVal)[1] ;
 HIDWriteBuff[3] =  ((char *)&analogVal)[0] ;
analogVal = ADC_get_sample(1);
 HIDWriteBuff[4] =  ((char *)&analogVal)[1] ;
 HIDWriteBuff[5] =  ((char *)&analogVal)[0] ;
analogVal = ADC_get_sample(2);
 HIDWriteBuff[6] =  ((char *)&analogVal)[1] ;
 HIDWriteBuff[7] =  ((char *)&analogVal)[0] ;
analogVal = ADC_get_sample(3);
 HIDWriteBuff[8] =  ((char *)&analogVal)[1] ;
 HIDWriteBuff[9] =  ((char *)&analogVal)[0] ;
analogVal = ADC_get_sample(4);
 HIDWriteBuff[10] =  ((char *)&analogVal)[1] ;
 HIDWriteBuff[11] =  ((char *)&analogVal)[0] ;
analogVal = ADC_get_sample(5);
 HIDWriteBuff[12] =  ((char *)&analogVal)[1] ;
 HIDWriteBuff[13] =  ((char *)&analogVal)[0] ;
analogVal = ADC_get_sample(6);
 HIDWriteBuff[14] =  ((char *)&analogVal)[1] ;
 HIDWriteBuff[15] =  ((char *)&analogVal)[0] ;
analogVal = ADC_get_sample(7);
 HIDWriteBuff[16] =  ((char *)&analogVal)[1] ;
 HIDWriteBuff[17] =  ((char *)&analogVal)[0] ;

 while(!HID_Write(&HIDWriteBuff, 64));
}

void EntradaDigital()
{
 HidWriteBuff[1] = DigitalIn;
 HidWriteBuff[2] = PORTB;

 while(!Hid_Write(&HidWriteBuff, 64));
}

void SaidaDigital()
{
 HidWriteBuff[1] = DigitalOut;
 HidWriteBuff[2] = PORTD;

 while(!Hid_write(&HidWriteBuff, 64));
}

void USB_Recv()
{
 char dataRx = 0;

 while(1)
 {
 HidWriteBuff[0] =  0x0F ;
 EntradaAnalogica();
 EntradaDigital();
 SaidaDigital();

 dataRx = HID_Read();

 if(dataRx)
 {
 dataRx = 0;
 CheckCommand();

 if(cmd == DigitalOut)
 {
 PORTD = PORTD ^ (1 << HidReadBuff[2]);
 cmd = None;
 }

 else if(cmd == PWM)
 {
 PWM1_Set_Duty(HidReadBuff[2]);
 PWM2_Set_Duty(HidReadBuff[3]);
 cmd = None;
 }
 }
 delay_ms(100);
 }
}

void main()
{
 TRISB = 255;
 TRISD = 0;
 TRISA = 255;
 TRISC = 0;
 PORTD = 0xAA;

 ADC_Init();
 PWM1_Init(4000);
 PWM2_Init(3000);
 PWM1_Set_Duty(127);
 PWM2_Set_Duty(127);
 PWM1_Start();
 PWM2_Start();
 HID_Enable(&HidReadBuff, &HidWriteBuff);

 Usb_Recv();
}
