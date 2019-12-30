
_interrupt:

;ControladorUSB.c,13 :: 		void interrupt()
;ControladorUSB.c,15 :: 		Usb_Interrupt_Proc();
	CALL        _USB_Interrupt_Proc+0, 0
;ControladorUSB.c,16 :: 		}
L_end_interrupt:
L__interrupt16:
	RETFIE      1
; end of _interrupt

_CheckCommand:

;ControladorUSB.c,18 :: 		void CheckCommand()
;ControladorUSB.c,20 :: 		if(cmd == None)
	MOVF        _cmd+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_CheckCommand0
;ControladorUSB.c,22 :: 		if(HidReadBuff[0] != STX) return;
	MOVF        1280, 0 
	XORLW       15
	BTFSC       STATUS+0, 2 
	GOTO        L_CheckCommand1
	GOTO        L_end_CheckCommand
L_CheckCommand1:
;ControladorUSB.c,23 :: 		cmd = HIDReadBuff[1];
	MOVF        1281, 0 
	MOVWF       _cmd+0 
;ControladorUSB.c,24 :: 		}
L_CheckCommand0:
;ControladorUSB.c,25 :: 		}
L_end_CheckCommand:
	RETURN      0
; end of _CheckCommand

_EntradaAnalogica:

;ControladorUSB.c,27 :: 		void EntradaAnalogica()
;ControladorUSB.c,30 :: 		HIDWriteBuff[1] =  Analog;
	MOVLW       1
	MOVWF       1345 
;ControladorUSB.c,31 :: 		analogVal = ADC_get_sample(0);
	CLRF        FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+0 
	MOVF        R1, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+1 
;ControladorUSB.c,32 :: 		HIDWriteBuff[2] =  Hi(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+1, 0 
	MOVWF       1346 
;ControladorUSB.c,33 :: 		HIDWriteBuff[3] =  Lo(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+0, 0 
	MOVWF       1347 
;ControladorUSB.c,34 :: 		analogVal = ADC_get_sample(1);
	MOVLW       1
	MOVWF       FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+0 
	MOVF        R1, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+1 
;ControladorUSB.c,35 :: 		HIDWriteBuff[4] =  Hi(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+1, 0 
	MOVWF       1348 
;ControladorUSB.c,36 :: 		HIDWriteBuff[5] =  Lo(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+0, 0 
	MOVWF       1349 
;ControladorUSB.c,37 :: 		analogVal = ADC_get_sample(2);
	MOVLW       2
	MOVWF       FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+0 
	MOVF        R1, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+1 
;ControladorUSB.c,38 :: 		HIDWriteBuff[6] =  Hi(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+1, 0 
	MOVWF       1350 
;ControladorUSB.c,39 :: 		HIDWriteBuff[7] =  Lo(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+0, 0 
	MOVWF       1351 
;ControladorUSB.c,40 :: 		analogVal = ADC_get_sample(3);
	MOVLW       3
	MOVWF       FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+0 
	MOVF        R1, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+1 
;ControladorUSB.c,41 :: 		HIDWriteBuff[8] =  Hi(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+1, 0 
	MOVWF       1352 
;ControladorUSB.c,42 :: 		HIDWriteBuff[9] =  Lo(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+0, 0 
	MOVWF       1353 
;ControladorUSB.c,43 :: 		analogVal = ADC_get_sample(4);
	MOVLW       4
	MOVWF       FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+0 
	MOVF        R1, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+1 
;ControladorUSB.c,44 :: 		HIDWriteBuff[10] =  Hi(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+1, 0 
	MOVWF       1354 
;ControladorUSB.c,45 :: 		HIDWriteBuff[11] =  Lo(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+0, 0 
	MOVWF       1355 
;ControladorUSB.c,46 :: 		analogVal = ADC_get_sample(5);
	MOVLW       5
	MOVWF       FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+0 
	MOVF        R1, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+1 
;ControladorUSB.c,47 :: 		HIDWriteBuff[12] =  Hi(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+1, 0 
	MOVWF       1356 
;ControladorUSB.c,48 :: 		HIDWriteBuff[13] =  Lo(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+0, 0 
	MOVWF       1357 
;ControladorUSB.c,49 :: 		analogVal = ADC_get_sample(6);
	MOVLW       6
	MOVWF       FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+0 
	MOVF        R1, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+1 
;ControladorUSB.c,50 :: 		HIDWriteBuff[14] =  Hi(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+1, 0 
	MOVWF       1358 
;ControladorUSB.c,51 :: 		HIDWriteBuff[15] =  Lo(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+0, 0 
	MOVWF       1359 
;ControladorUSB.c,52 :: 		analogVal = ADC_get_sample(7);
	MOVLW       7
	MOVWF       FARG_ADC_Get_Sample_channel+0 
	CALL        _ADC_Get_Sample+0, 0
	MOVF        R0, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+0 
	MOVF        R1, 0 
	MOVWF       EntradaAnalogica_analogVal_L0+1 
;ControladorUSB.c,53 :: 		HIDWriteBuff[16] =  Hi(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+1, 0 
	MOVWF       1360 
;ControladorUSB.c,54 :: 		HIDWriteBuff[17] =  Lo(analogVal);
	MOVF        EntradaAnalogica_analogVal_L0+0, 0 
	MOVWF       1361 
;ControladorUSB.c,56 :: 		while(!HID_Write(&HIDWriteBuff, 64));
L_EntradaAnalogica2:
	MOVLW       _HidWriteBuff+0
	MOVWF       FARG_HID_Write_writebuff+0 
	MOVLW       hi_addr(_HidWriteBuff+0)
	MOVWF       FARG_HID_Write_writebuff+1 
	MOVLW       64
	MOVWF       FARG_HID_Write_len+0 
	CALL        _HID_Write+0, 0
	MOVF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_EntradaAnalogica3
	GOTO        L_EntradaAnalogica2
L_EntradaAnalogica3:
;ControladorUSB.c,57 :: 		}
L_end_EntradaAnalogica:
	RETURN      0
; end of _EntradaAnalogica

_EntradaDigital:

;ControladorUSB.c,59 :: 		void EntradaDigital()
;ControladorUSB.c,61 :: 		HidWriteBuff[1] = DigitalIn;
	MOVLW       2
	MOVWF       1345 
;ControladorUSB.c,62 :: 		HidWriteBuff[2] = PORTD;
	MOVF        PORTD+0, 0 
	MOVWF       1346 
;ControladorUSB.c,64 :: 		while(!Hid_Write(&HidWriteBuff, 64));
L_EntradaDigital4:
	MOVLW       _HidWriteBuff+0
	MOVWF       FARG_HID_Write_writebuff+0 
	MOVLW       hi_addr(_HidWriteBuff+0)
	MOVWF       FARG_HID_Write_writebuff+1 
	MOVLW       64
	MOVWF       FARG_HID_Write_len+0 
	CALL        _HID_Write+0, 0
	MOVF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_EntradaDigital5
	GOTO        L_EntradaDigital4
L_EntradaDigital5:
;ControladorUSB.c,65 :: 		}
L_end_EntradaDigital:
	RETURN      0
; end of _EntradaDigital

_SaidaDigital:

;ControladorUSB.c,67 :: 		void SaidaDigital()
;ControladorUSB.c,69 :: 		HidWriteBuff[1] = DigitalOut;
	MOVLW       3
	MOVWF       1345 
;ControladorUSB.c,70 :: 		HidWriteBuff[2] = PORTB;
	MOVF        PORTB+0, 0 
	MOVWF       1346 
;ControladorUSB.c,72 :: 		while(!Hid_write(&HidWriteBuff, 64));
L_SaidaDigital6:
	MOVLW       _HidWriteBuff+0
	MOVWF       FARG_HID_Write_writebuff+0 
	MOVLW       hi_addr(_HidWriteBuff+0)
	MOVWF       FARG_HID_Write_writebuff+1 
	MOVLW       64
	MOVWF       FARG_HID_Write_len+0 
	CALL        _HID_Write+0, 0
	MOVF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_SaidaDigital7
	GOTO        L_SaidaDigital6
L_SaidaDigital7:
;ControladorUSB.c,73 :: 		}
L_end_SaidaDigital:
	RETURN      0
; end of _SaidaDigital

_USB_Recv:

;ControladorUSB.c,75 :: 		void USB_Recv()
;ControladorUSB.c,77 :: 		char dataRx = 0;
;ControladorUSB.c,79 :: 		while(1)
L_USB_Recv8:
;ControladorUSB.c,81 :: 		HidWriteBuff[0] = STX;
	MOVLW       15
	MOVWF       1344 
;ControladorUSB.c,82 :: 		EntradaAnalogica();
	CALL        _EntradaAnalogica+0, 0
;ControladorUSB.c,83 :: 		EntradaDigital();
	CALL        _EntradaDigital+0, 0
;ControladorUSB.c,84 :: 		SaidaDigital();
	CALL        _SaidaDigital+0, 0
;ControladorUSB.c,86 :: 		dataRx = HID_Read();
	CALL        _HID_Read+0, 0
;ControladorUSB.c,88 :: 		if(dataRx)
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_USB_Recv10
;ControladorUSB.c,91 :: 		CheckCommand();
	CALL        _CheckCommand+0, 0
;ControladorUSB.c,93 :: 		if(cmd == DigitalOut) //Saídas Digitais
	MOVF        _cmd+0, 0 
	XORLW       3
	BTFSS       STATUS+0, 2 
	GOTO        L_USB_Recv11
;ControladorUSB.c,95 :: 		PORTB = PORTB ^ (1 << HidReadBuff[2]);
	MOVF        1282, 0 
	MOVWF       R1 
	MOVLW       1
	MOVWF       R0 
	MOVF        R1, 0 
L__USB_Recv22:
	BZ          L__USB_Recv23
	RLCF        R0, 1 
	BCF         R0, 0 
	ADDLW       255
	GOTO        L__USB_Recv22
L__USB_Recv23:
	MOVF        R0, 0 
	XORWF       PORTB+0, 1 
;ControladorUSB.c,96 :: 		cmd = None;
	CLRF        _cmd+0 
;ControladorUSB.c,97 :: 		}
	GOTO        L_USB_Recv12
L_USB_Recv11:
;ControladorUSB.c,99 :: 		else if(cmd == PWM)
	MOVF        _cmd+0, 0 
	XORLW       4
	BTFSS       STATUS+0, 2 
	GOTO        L_USB_Recv13
;ControladorUSB.c,101 :: 		PWM1_Set_Duty(HidReadBuff[2]);
	MOVF        1282, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;ControladorUSB.c,102 :: 		PWM2_Set_Duty(HidReadBuff[3]);
	MOVF        1283, 0 
	MOVWF       FARG_PWM2_Set_Duty_new_duty+0 
	CALL        _PWM2_Set_Duty+0, 0
;ControladorUSB.c,103 :: 		cmd = None;
	CLRF        _cmd+0 
;ControladorUSB.c,104 :: 		}
L_USB_Recv13:
L_USB_Recv12:
;ControladorUSB.c,105 :: 		}
L_USB_Recv10:
;ControladorUSB.c,106 :: 		delay_ms(100);
	MOVLW       7
	MOVWF       R11, 0
	MOVLW       23
	MOVWF       R12, 0
	MOVLW       106
	MOVWF       R13, 0
L_USB_Recv14:
	DECFSZ      R13, 1, 1
	BRA         L_USB_Recv14
	DECFSZ      R12, 1, 1
	BRA         L_USB_Recv14
	DECFSZ      R11, 1, 1
	BRA         L_USB_Recv14
	NOP
;ControladorUSB.c,107 :: 		}
	GOTO        L_USB_Recv8
;ControladorUSB.c,108 :: 		}
L_end_USB_Recv:
	RETURN      0
; end of _USB_Recv

_main:

;ControladorUSB.c,110 :: 		void main()
;ControladorUSB.c,112 :: 		TRISD = 255;
	MOVLW       255
	MOVWF       TRISD+0 
;ControladorUSB.c,113 :: 		TRISB = 0;
	CLRF        TRISB+0 
;ControladorUSB.c,114 :: 		TRISA = 255;
	MOVLW       255
	MOVWF       TRISA+0 
;ControladorUSB.c,115 :: 		TRISC = 0;
	CLRF        TRISC+0 
;ControladorUSB.c,116 :: 		PORTB = 0xAA;
	MOVLW       170
	MOVWF       PORTB+0 
;ControladorUSB.c,118 :: 		ADC_Init();
	CALL        _ADC_Init+0, 0
;ControladorUSB.c,119 :: 		PWM1_Init(4000);
	BSF         T2CON+0, 0, 0
	BSF         T2CON+0, 1, 0
	MOVLW       187
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
;ControladorUSB.c,120 :: 		PWM2_Init(3000);
	BSF         T2CON+0, 0, 0
	BSF         T2CON+0, 1, 0
	MOVLW       249
	MOVWF       PR2+0, 0
	CALL        _PWM2_Init+0, 0
;ControladorUSB.c,121 :: 		PWM1_Set_Duty(127);
	MOVLW       127
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;ControladorUSB.c,122 :: 		PWM2_Set_Duty(127);
	MOVLW       127
	MOVWF       FARG_PWM2_Set_Duty_new_duty+0 
	CALL        _PWM2_Set_Duty+0, 0
;ControladorUSB.c,123 :: 		PWM1_Start();
	CALL        _PWM1_Start+0, 0
;ControladorUSB.c,124 :: 		PWM2_Start();
	CALL        _PWM2_Start+0, 0
;ControladorUSB.c,125 :: 		HID_Enable(&HidReadBuff, &HidWriteBuff);
	MOVLW       _HidReadBuff+0
	MOVWF       FARG_HID_Enable_readbuff+0 
	MOVLW       hi_addr(_HidReadBuff+0)
	MOVWF       FARG_HID_Enable_readbuff+1 
	MOVLW       _HidWriteBuff+0
	MOVWF       FARG_HID_Enable_writebuff+0 
	MOVLW       hi_addr(_HidWriteBuff+0)
	MOVWF       FARG_HID_Enable_writebuff+1 
	CALL        _HID_Enable+0, 0
;ControladorUSB.c,127 :: 		Usb_Recv();
	CALL        _USB_Recv+0, 0
;ControladorUSB.c,128 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
