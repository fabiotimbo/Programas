char byte_read;
void main(){
UART1_Init(9600);
TRISD = 0x00; // Configura porta D como saída
while(1) // Loop infinito
{
byte_read = UART1_Read(); // Lê o byte enviado pela serial
if (byte_read=='L') // se o valor enviado for igual a L liga o led no pino D0
{PORTD.F0 = 1;}
if (byte_read=='D') // se o valor enviado for igual a D desliga o led no pino D0
{PORTD.F0 = 0;}
}
}