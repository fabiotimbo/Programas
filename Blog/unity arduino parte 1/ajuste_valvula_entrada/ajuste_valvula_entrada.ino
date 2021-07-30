const int potenciometro = 0; // pino de entrada do potenciômetro
int valor = 0;
 
void setup() {
Serial.begin(9600);//taxa de transmissão
}

void loop() {
valor = analogRead(potenciometro);
valor=(valor/10.23);//valor máximo transmitido 100 l/s
Serial.println(valor);
delay(100);
}
