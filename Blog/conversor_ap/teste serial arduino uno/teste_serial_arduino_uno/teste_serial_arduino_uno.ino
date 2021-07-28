const int ledPin = 13; // Led nativo do arduino
void setup() {
Serial.begin(9600);//taxa de transmissão 9600bps
pinMode(ledPin, OUTPUT); // Pino 13 será de saída digital
}
 
void loop()
{
int vel;//tirar ()
if (Serial.available()) { // Verificar se há caracteres disponíveis pela serial
char caractere = Serial.read(); // Armazena caractere lido
switch (caractere) {
      case 'L':
        digitalWrite(ledPin, 1);// se o valor enviado for igual a "L" liga o led no pino 13
        break;
      case 'D':
        digitalWrite(ledPin, 0);// se o valor enviado for igual a "D" desliga o led no pino 13
        break;
}}}
