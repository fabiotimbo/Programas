//Definições da matriz do teclado
#define COL1   pin_b4
#define COL2   pin_b5
#define COL3   pin_b6
#define COL4   pin_b7
#define LIN1   pin_b0
#define LIN2   pin_b1
#define LIN3   pin_b2
#define LIN4   pin_b3

char tecla;
boolean tecla_pres;

char varre_teclas(void)
{
char key = ' ';
output_high(COL4);
output_high(COL3);
output_high(COL2);
output_low(COL1); //Ativa a primeira coluna
if (!input(LIN1)) key = '1';
if (!input(LIN2)) key = '4';
if (!input(LIN3)) key = '7';
if (!input(LIN4)) key = '*';
output_high(COL1);
output_low(COL2); //Ativa a segunda coluna
if (!input(LIN1)) key = '2';
if (!input(LIN2)) key = '5';
if (!input(LIN3)) key = '8';
if (!input(LIN4)) key = '0';
output_high(COL2);
output_low(COL3); //Ativa a terceira coluna
if (!input(LIN1)) key = '3';
if (!input(LIN2)) key = '6';
if (!input(LIN3)) key = '9';
if (!input(LIN4)) key = '#';
output_high(COL3);
output_low(COL4);
if (!input(LIN1)) key = 'A';
if (!input(LIN2)) key = 'B';
if (!input(LIN3)) key = 'C';
if (!input(LIN4)) key = 'D';
output_high(COL4);

return(key);
}

char trata_teclas(void)
{
int t;

t=varre_teclas();  //Verifica se há uma tecla pressionada
if((t != ' ') && (!tecla_pres)) //Se há tecla pressionada e o flag está apagado
{
   tecla_pres = 1; //ativa o flag
   if (t != tecla)
    // Se a tecla atual é diferente da anterior
   {
      //filtra o ruído de contato
      delay_ms(10);
      // Lê novamente as teclas e verifica 
      // se a mesma tecla ainda está pressionada
      // caso positivo, retorna a tecla
      if (varre_teclas() == t) return (t);
   }
}
tecla_pres = 0; // se não há tecla, retorna 0
}
