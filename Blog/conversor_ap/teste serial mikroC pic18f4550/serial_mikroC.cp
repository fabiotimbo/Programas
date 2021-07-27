#line 1 "C:/Users/Fabio T. Brito/Dropbox/IFCE/Disciplinas_IFCE/Apostilas IFCE/Micro/Programas oficiais/Blog/conversor_ap/serial_mikroC.c"
char byte_read;
void main(){
UART1_Init(9600);
TRISD = 0x00;
while(1)
{
byte_read = UART1_Read();
if (byte_read=='L')
{PORTD.F0 = 1;}
if (byte_read=='D')
{PORTD.F0 = 0;}
}
}
