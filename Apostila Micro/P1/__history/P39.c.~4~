#include <18f4550.h>
#fuses hs,nowdt,noprotect,nolvp,NOMCLR
void main()
{
 int delay_reg1;// declaração de variáveis
 int delay_reg2;// declaração de variáveis
#asm
goto inicio // vai para label inicio
Delay100ms:
  movlw 0x83 //w=131d
  movwf delay_reg1 // reg1=131d
  movlw 0xFF // w=255d
  movwf delay_reg2 // reg2=255d
loop1:
  DECFSZ delay_reg1 // decrementa e pula se igual a zero
  goto loop2
  goto exit
loop2:
  DECFSZ delay_reg2 // decrementa e pula se igual a zero
  goto loop2
  goto loop1
Exit:
  RETURN

inicio:   
 movlw  0x00  // 00h= pullup habilitado;80h=pullup desabilitado.
 movwf  0xFF1 //intcon2=00h
 movlw  0xFF  //w=11111111b
 movwf  0xF93  //trisbB=11111111b
 movlw  0x00 //w=00000000b
 movwf  0xF95 // trisD=00000000b
 movlw  0xE6 //w=11100110b
// movwf  0xFD3 // Oscilador 4Mhz Sem cristal e capacitor $$$$

loop:
   clrf    0XF83 // limpa porta d
   call    Delay100ms // vai pra subrotina Delay100ms
   movlw   0xff// w=ffh
   movwf   0XF83 // porta d=11111111b
   call    Delay100ms // vai pra subrotina Delay100ms
   goto    loop //vai pra subrotina loop
#endasm
}

