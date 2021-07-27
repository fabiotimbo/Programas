const int ledPin = 13; // Pino ao qual o LED será conectado
void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT); // Pino 13 será de saída de sinais
}
 
void loop()
{
int vel;//tirar ()
if (Serial.available()) { // Verificar se há caracteres disponíveis
char caractere = Serial.read(); // Armazena caractere lido
switch (caractere) {
      case 'L':
        digitalWrite(ledPin, 1);
        break;
      case 'D':
        digitalWrite(ledPin, 0);
        break;
} 
}
}
