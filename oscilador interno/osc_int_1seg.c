#include <18f4550.h>
#fuses hs,nowdt,noprotect,nolvp,NOMCLR

void main()
{

int delay_reg1;
int delay_reg2; 
#asm
GOTO teste

Delay100ms:
   movlw 0x83
   movwf delay_reg1
   movlw 0xFF
   movwf delay_reg2
loop1:
   DECFSZ delay_reg1
   GOTO loop2
   GOTO exit
loop2:
   DECFSZ delay_reg2
   GOTO loop2
   GOTO loop1
Exit:
   RETURN
   
teste:   
movlw  0x80
movwf  0xFF1
movlw  0xFF
movwf  0xF93
movlw  0x00
movwf  0xF95
movlw  0xE6
movwf  0xFD3

loop:
   clrf    0XF83
   call    Delay100ms
   movlw   0xff
   movwf   0XF83
   call    Delay100ms
   goto    loop
#endasm
}




