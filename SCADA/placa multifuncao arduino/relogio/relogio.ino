/* Programa Relógio Digital com alarme para Shield Multi-funções
  Blog Eletrogate - https://blog.eletrogate.com/guia-completo-do-shield-multi-funcoes-para-arduino
  Arduino UNO - IDE 1.8.5 - Shield Multi-funções para Arduino
  Gustavo Murta   14/junho/2018
*/
#include <TimerOne.h>                                   // Biblioteca TimerOne
#include <Wire.h>                                       // Biblioteca Wire
#include <MultiFuncShield.h>                            // Biblioteca Multifunction shield
volatile unsigned int clockMilliSeconds = 0;            // variáveis do relógio
volatile byte clockSeconds = 0;                         // segundos
volatile byte clockMinutes = 0;                         // minutos
volatile byte clockHours = 12;                          // horas
volatile byte clockEnabled = 1;                         // relógio ativado
byte alarmMinutes = 30;                                 // alarm inicial 06:30 hs
byte alarmHours = 6;
volatile byte alarmEnabled = false;                     // alarme desligado
byte alarmTogglePressed = false;
enum displayModeValues                                  // modos de amostragem do relógio
{
  MODE_CLOCK_TIME,
  MODE_CLOCK_TIME_SET_HOUR,
  MODE_CLOCK_TIME_SET_MINUTE,
  MODE_ALARM_TIME,
  MODE_ALARM_TIME_SET_HOUR,
  MODE_ALARM_TIME_SET_MINUTE
};
byte displayMode = MODE_CLOCK_TIME;                     // modo normal do relógio
void setup()
{
  Timer1.initialize();                                  // inicializa timer 1
  MFS.userInterrupt = clockISR;                         // uso da interrupção para contagem de tempo
  MFS.initialize(&Timer1);                              // inicializa shield multi-funções
  MFS.blinkDisplay(DIGIT_ALL);                          // pisca os dígitos do display
}
void loop()
{
  byte btn = MFS.getButton();                           // verifica botão pressionado
  switch (displayMode)                                  // seleciona o modo do relógio
  {
    case MODE_CLOCK_TIME:                               // modo normal
      displayTime(clockHours, clockMinutes);            // mostra horas e minutos
      if (btn == BUTTON_2_PRESSED)                      // se o botão 2 foi pressionado
      {
        MFS.beep(0);                                    // cancela o bip
        displayMode = MODE_ALARM_TIME;                  // seleciona o modo de alarme
      }
      else if (btn == BUTTON_1_LONG_PRESSED)            // se o botão 1 também for pressionado longo
      {
        MFS.blinkDisplay(DIGIT_ALL, OFF);               // para de piscar todos os dígitos
        MFS.blinkDisplay(DIGIT_1 | DIGIT_2);            // pisca somente as horas
        displayMode = MODE_CLOCK_TIME_SET_HOUR;         // seleciona modo de acerto de horas
        clockEnabled = false;                           // contagem de tempo parada
        clockMilliSeconds = 0;                          // zera os contadores de milisegundos
        clockSeconds = 0;                               // zera os segundos
      }
      else if (btn == BUTTON_3_LONG_PRESSED && !alarmTogglePressed)  // se o botão 3 for pressionado
      {
        alarmTogglePressed = true;                      // liga o alarme
        alarmEnabled = !alarmEnabled;
        MFS.writeLeds(LED_1, alarmEnabled);             // acende o Led 1
      }
      else if (btn == BUTTON_3_LONG_RELEASE)            // soltando o botão 3
      {
        alarmTogglePressed = false;                     // alarme pressionado é falso
      }
      break;
    case MODE_CLOCK_TIME_SET_HOUR:                      // modo para acerto de horas
      if (btn == BUTTON_1_PRESSED)                      // se o botão 1 for pressionado
      {
        MFS.blinkDisplay(DIGIT_1 | DIGIT_2, OFF);       // para de piscar as horas
        MFS.blinkDisplay(DIGIT_3 | DIGIT_4);            // pisca os minutos
        displayMode = MODE_CLOCK_TIME_SET_MINUTE;       // modo para acerto de minutos
      }
      else if (btn == BUTTON_3_PRESSED || btn == BUTTON_3_LONG_PRESSED) // se o botão 3 for pressionado
      {
        clockHours++;                                   // incrementa as horas
        if (clockHours >= 24)                           // se for mais de 24 horas
        {
          clockHours = 0;                               // zera as horas
        }
        displayTime(clockHours, clockMinutes);          // mostra horas e minutos
      }
      break;
    case MODE_CLOCK_TIME_SET_MINUTE:                    // modo para acerto de minutos
      if (btn == BUTTON_1_PRESSED)                      // se o botão 1 for pressionado
      {
        MFS.blinkDisplay(DIGIT_3 | DIGIT_4, OFF);       // para de piscar os minutos
        displayMode = MODE_CLOCK_TIME;                  // modo normal
        clockEnabled = true;                            // contagem de tempo iniciada
      }
      else if (btn == BUTTON_3_PRESSED || btn == BUTTON_3_LONG_PRESSED) // se o botão 3 for pressionado
      {
        clockMinutes++;                                 // incrementa os minutos
        if (clockMinutes >= 60)                         // se for mais de 60 minutos
        {
          clockMinutes = 0;                             // zera os minutos
        }
        displayTime(clockHours, clockMinutes);          // mostra horas e minutos
      }
      break;
    case MODE_ALARM_TIME:                              // modo de acerto do alarme
      displayTime(alarmHours, alarmMinutes);           // mostra horas e minutos do alarme
      if (btn == BUTTON_2_SHORT_RELEASE || btn == BUTTON_2_LONG_RELEASE)  // se o botão 2 for pressionado
      {
        displayMode = MODE_CLOCK_TIME;                 // modo normal
      }
      else if (btn == BUTTON_1_LONG_PRESSED)           // se o botão 1 for pressionado longo
      {
        MFS.blinkDisplay(DIGIT_ALL, OFF);              // para de piscar todos os dígitos
        MFS.blinkDisplay(DIGIT_1 | DIGIT_2);           // pisca somente as horas
        displayMode = MODE_ALARM_TIME_SET_HOUR;        // modo acerto de horas do alarme
        alarmEnabled = false;                          // alarme desligado
      }
      break;
    case MODE_ALARM_TIME_SET_HOUR:                     // modo acerto de horas do alarme
      if (btn == BUTTON_1_PRESSED)                     // se o botão 1 for pressionado
      {
        MFS.blinkDisplay(DIGIT_1 | DIGIT_2, OFF);      // para de piscar todos os dígitos
        MFS.blinkDisplay(DIGIT_3 | DIGIT_4);           // pisca os minutos
        displayMode = MODE_ALARM_TIME_SET_MINUTE;      // modo acerto dos minutos do alarme
      }
      else if (btn == BUTTON_3_PRESSED || btn == BUTTON_3_LONG_PRESSED)  // se o botão 3 for pressionado
      {
        alarmHours++;                                  // incrementa horas do alarme
        if (alarmHours >= 24)                          // se for mais de 24 horas
        {
          alarmHours = 0;                              // zera as horas
        }
        displayTime(alarmHours, alarmMinutes);         // mostra horas e minutos do alarme
      }
      break;
    case MODE_ALARM_TIME_SET_MINUTE:                   // modo acerto dos minutos do alarme
      if (btn == BUTTON_1_PRESSED)                     // se o botão 1 for pressionado
      {
        MFS.blinkDisplay(DIGIT_3 | DIGIT_4, OFF);      // para de piscar os minutos
        displayMode = MODE_CLOCK_TIME;                 // modo normal
        alarmEnabled = true;                           // alarme ligado
        MFS.writeLeds(LED_1, ON);                      // acende o Led 1
      }
      else if (btn == BUTTON_3_PRESSED || btn == BUTTON_3_LONG_PRESSED)  // se o botão 3 for pressionado
      {
        alarmMinutes++;                                // incrementa minutos do alarme
        if (alarmMinutes >= 60)                        // se for mais de 60 minutos
        {
          alarmMinutes = 0;                            // zera os minutos
        }
        displayTime(alarmHours, alarmMinutes);         // mostra horas e minutos do alarme
      }
      break;
  }
}
void displayTime (byte hours, byte minutes)           //  mostra relógio
{
  char time[5];                                       // vetor de 5 caracteres
  sprintf(time, "%03d", (hours * 100) + minutes);     // mostra horas e minutos
  MFS.write(time, 1);
}
void clockISR ()
{
  // Procedimento de contagem de tempo
  if (clockEnabled)
  {
    clockMilliSeconds++;
    if (clockMilliSeconds >= 1000)
    {
      clockMilliSeconds = 0;
      clockSeconds++;
      if (clockSeconds >= 60)
      {
        clockSeconds = 0;
        clockMinutes++;
        if (clockMinutes >= 60)
        {
          clockMinutes = 0;
          clockHours++;
          if (clockHours >= 24)
          {
            clockHours = 0;
          }
        }
        // se o horario do relógio coincide com o alarme, dispara o bip
        if (alarmEnabled && (clockMinutes == alarmMinutes) && (clockHours == alarmHours))
        {
          MFS.beep(
            10,        // 10 ms ON
            5,         // 5 ms OFF
            4,         // numero de repetições
            100,       // número de sequências
            50         // atraso entre as sequências
          );
        }
      }
    }
  }
}
