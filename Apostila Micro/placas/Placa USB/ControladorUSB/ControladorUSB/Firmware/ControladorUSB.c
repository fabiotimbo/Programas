#include <Built_in.h>

#define STX 0x0F

unsigned char HidReadBuff[64]  absolute 0x500;
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
     if(HidReadBuff[0] != STX) return;
     cmd = HIDReadBuff[1];
   }
}

void EntradaAnalogica()
{
unsigned analogVal;
  HIDWriteBuff[1] =  Analog;
analogVal = ADC_get_sample(0);
  HIDWriteBuff[2] =  Hi(analogVal);
  HIDWriteBuff[3] =  Lo(analogVal);
analogVal = ADC_get_sample(1);
  HIDWriteBuff[4] =  Hi(analogVal);
  HIDWriteBuff[5] =  Lo(analogVal);
analogVal = ADC_get_sample(2);
  HIDWriteBuff[6] =  Hi(analogVal);
  HIDWriteBuff[7] =  Lo(analogVal);
analogVal = ADC_get_sample(3);
  HIDWriteBuff[8] =  Hi(analogVal);
  HIDWriteBuff[9] =  Lo(analogVal);
analogVal = ADC_get_sample(4);
  HIDWriteBuff[10] =  Hi(analogVal);
  HIDWriteBuff[11] =  Lo(analogVal);
analogVal = ADC_get_sample(5);
  HIDWriteBuff[12] =  Hi(analogVal);
  HIDWriteBuff[13] =  Lo(analogVal);
analogVal = ADC_get_sample(6);
  HIDWriteBuff[14] =  Hi(analogVal);
  HIDWriteBuff[15] =  Lo(analogVal);
analogVal = ADC_get_sample(7);
  HIDWriteBuff[16] =  Hi(analogVal);
  HIDWriteBuff[17] =  Lo(analogVal);

  while(!HID_Write(&HIDWriteBuff, 64));
}

void EntradaDigital()
{
   HidWriteBuff[1] = DigitalIn;
   HidWriteBuff[2] = PORTD;

   while(!Hid_Write(&HidWriteBuff, 64));
}

void SaidaDigital()
{
   HidWriteBuff[1] = DigitalOut;
   HidWriteBuff[2] = PORTB;

   while(!Hid_write(&HidWriteBuff, 64));
}

void USB_Recv()
{
 char dataRx = 0;

   while(1)
   {
      HidWriteBuff[0] = STX;
      EntradaAnalogica();
      EntradaDigital();
      SaidaDigital();

      dataRx = HID_Read();

      if(dataRx)
      {
        dataRx = 0;
        CheckCommand();

        if(cmd == DigitalOut) //Saídas Digitais
        {
          PORTB = PORTB ^ (1 << HidReadBuff[2]);
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
    TRISD = 255;
    TRISB = 0;
    TRISA = 255;
    TRISC = 0;
    PORTB = 0xAA;
    
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