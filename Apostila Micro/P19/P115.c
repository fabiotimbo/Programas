#include <18f4550.h>
#byte portd=0xF83
#fuses HS,CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7)
//motor 28Byj-48 possui 2048 passos por rota��o ou 0,175� /passo
void main()
{
int16 a=2; //tempo 2ms =>  2048*0,002=4,096 segundos (per�odo do motor)
port_b_pullups (true);
set_tris_d(0x00);
set_tris_b(0xFF);
while(true)
{
    if ((input(pin_b0)==0)&&(input(pin_b1)==1))//bot�o b0 pressionado
       {
       portd=0b10010000;
       printf("d\r\n");
       delay_ms(a);
       portd=0b00110000;
        printf("d\r\n");
       delay_ms(a);
       portd=0b01100000;
        printf("d\r\n");
       delay_ms(a);
       portd=0b11000000;
        printf("d\r\n");
       delay_ms(a);
       }
    if ((input(pin_b0)==1)&&(input(pin_b1)==0))//bot�o b1 pressionado
       {
       portd=0b11000000;
        printf("s\r\n");
       delay_ms(a);
       portd=0b01100000;
        printf("s\r\n");
       delay_ms(a);
       portd=0b00110000;
        printf("s\r\n");
       delay_ms(a);
       portd=0b10010000;
        printf("s\r\n");
       delay_ms(a);       }
       portd=0b00000000;//evita energizar as bobinas e o aquecimento do motor
}}

