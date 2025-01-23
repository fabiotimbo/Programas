/* Programa de teste do Display do Shield Multi-função
  Blog Eletrogate - https://blog.eletrogate.com/guia-completo-do-shield-multi-funcoes-para-arduino
  Arduino UNO - IDE 1.8.5 - Shield Multi-função para Arduino
  Gustavo Murta   13/junho/2018
  Baseado em http://www.cohesivecomputing.co.uk/hackatronics/arduino-multi-function-shield/part-1/
*/
#include <TimerOne.h>                     // Bibliotec TimerOne 
#include <Wire.h>                         // Biblioteca Wire 
#include <MultiFuncShield.h>              // Biblioteca Multifunction shield

int spValue = 0, pvValue=0;  // variable to store the value coming from the sensor
int sensorValue = 0;  // variable to store the value coming from the sensor
const int pin_mv = 11;      // the pin that the LED is attached to
const int pin_pv = A1;  // Analog input pin that the potentiometer is attached to
const int pin_sp = A0;    // select the input pin for the potentiometer


void setup()
{
  Serial.begin(9600);
  pinMode(pin_mv, OUTPUT);
  pinMode(10, OUTPUT);
  Timer1.initialize();                    // inicializa o Timer 1
  MFS.initialize(&Timer1);                // initializa a biblioteca Multi função
                                // inicializa timer 1
  MFS.userInterrupt = amostragem;            // uso da interrupção para contagem de tempo
  MFS.write("8888");                        // escreve no display Hi
  delay(2000);                            // atraso de 2 segundos
}
int counter = 1000,teste=0,mv;                       // incializa o conatdor
                        

void loop()
{
    MFS.write((int)sensorValue/4);
    analogWrite(pin_mv, (int)spValue/4);  
    digitalWrite(10, LOW);
}
void amostragem ()
{ teste++; 
  if (teste>100) {
    teste=0;
    spValue = analogRead(pin_sp);
    pvValue = analogRead(pin_pv);
    Serial.println(pvValue);
      
    }
}
