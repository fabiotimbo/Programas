
_main:

;serial_mikroC.c,2 :: 		void main(){
;serial_mikroC.c,3 :: 		UART1_Init(9600);
	BSF         BAUDCON+0, 3, 0
	MOVLW       2
	MOVWF       SPBRGH+0 
	MOVLW       8
	MOVWF       SPBRG+0 
	BSF         TXSTA+0, 2, 0
	CALL        _UART1_Init+0, 0
;serial_mikroC.c,4 :: 		TRISD = 0x00; // Configura porta D como saída
	CLRF        TRISD+0 
;serial_mikroC.c,5 :: 		while(1) // Loop infinito
L_main0:
;serial_mikroC.c,7 :: 		byte_read = UART1_Read(); // Lê o byte enviado pela serial
	CALL        _UART1_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _byte_read+0 
;serial_mikroC.c,8 :: 		if (byte_read=='L') // se o valor enviado for igual a L liga o led no pino D0
	MOVF        R0, 0 
	XORLW       76
	BTFSS       STATUS+0, 2 
	GOTO        L_main2
;serial_mikroC.c,9 :: 		{PORTD.F0 = 1;}
	BSF         PORTD+0, 0 
L_main2:
;serial_mikroC.c,10 :: 		if (byte_read=='D') // se o valor enviado for igual a D desliga o led no pino D0
	MOVF        _byte_read+0, 0 
	XORLW       68
	BTFSS       STATUS+0, 2 
	GOTO        L_main3
;serial_mikroC.c,11 :: 		{PORTD.F0 = 0;}
	BCF         PORTD+0, 0 
L_main3:
;serial_mikroC.c,12 :: 		}
	GOTO        L_main0
;serial_mikroC.c,13 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
