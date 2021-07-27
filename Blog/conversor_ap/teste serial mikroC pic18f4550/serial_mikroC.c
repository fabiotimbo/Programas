char byte_read;
void main(){
UART1_Init(9600);
TRISD = 0x00; // Configura para ser saída D1 e D2
while(1) // Endless loop
{
byte_read = UART1_Read(); // Lê o byte enviado pela serial
if (byte_read=='L') // se o valor enviado for igual a l liga ou desliga o led;
{PORTD.F0 = 1;}
if (byte_read=='D') // se o valor enviado for igual a l liga ou desliga o led;
{PORTD.F0 = 0;}
}
}