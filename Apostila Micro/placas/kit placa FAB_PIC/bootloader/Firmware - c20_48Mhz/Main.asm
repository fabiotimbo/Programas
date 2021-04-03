
_Ack:

;Main.c,63 :: 		void Ack( char cmd )
;Main.c,65 :: 		HidWriteBuff[0] = STX;
	MOVLW       15
	MOVWF       1344 
;Main.c,66 :: 		HidWriteBuff[1] = cmd;   //Comando
	MOVF        FARG_Ack_cmd+0, 0 
	MOVWF       1345 
;Main.c,67 :: 		while( !HID_Write(&HidWriteBuff, 64) );
L_Ack0:
	MOVLW       _HidWriteBuff+0
	MOVWF       FARG_HID_Write_writebuff+0 
	MOVLW       hi_addr(_HidWriteBuff+0)
	MOVWF       FARG_HID_Write_writebuff+1 
	MOVLW       64
	MOVWF       FARG_HID_Write_len+0 
	CALL        _HID_Write+0, 0
	MOVF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_Ack1
	GOTO        L_Ack0
L_Ack1:
;Main.c,68 :: 		}
L_end_Ack:
	RETURN      0
; end of _Ack

_CheckCmd:

;Main.c,71 :: 		void CheckCmd()
;Main.c,73 :: 		if( CmdCode == cmdNONE )
	MOVF        _CmdCode+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_CheckCmd2
;Main.c,75 :: 		if( HidReadBuff[0] != STX )   //cmdSTART
	MOVLW       0
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L__CheckCmd30
	MOVLW       15
	XORWF       1280, 0 
L__CheckCmd30:
	BTFSC       STATUS+0, 2 
	GOTO        L_CheckCmd3
;Main.c,76 :: 		return;
	GOTO        L_end_CheckCmd
L_CheckCmd3:
;Main.c,78 :: 		CmdCode =     HIDReadBuff[1]; //Comando
	MOVF        1281, 0 
	MOVWF       _CmdCode+0 
;Main.c,79 :: 		Hi(Address) = HidReadBuff[2]; //Address
	MOVF        1282, 0 
	MOVWF       _Address+1 
;Main.c,80 :: 		Lo(Address) = HidReadBuff[3]; //Address
	MOVF        1283, 0 
	MOVWF       _Address+0 
;Main.c,81 :: 		}
L_CheckCmd2:
;Main.c,82 :: 		}
L_end_CheckCmd:
	RETURN      0
; end of _CheckCmd

_EnterBootloader:

;Main.c,84 :: 		char EnterBootloader()
;Main.c,86 :: 		unsigned timer = 7000;
	MOVLW       88
	MOVWF       EnterBootloader_timer_L0+0 
	MOVLW       27
	MOVWF       EnterBootloader_timer_L0+1 
;Main.c,87 :: 		while( timer-- )
L_EnterBootloader4:
	MOVF        EnterBootloader_timer_L0+0, 0 
	MOVWF       R0 
	MOVF        EnterBootloader_timer_L0+1, 0 
	MOVWF       R1 
	MOVLW       1
	SUBWF       EnterBootloader_timer_L0+0, 1 
	MOVLW       0
	SUBWFB      EnterBootloader_timer_L0+1, 1 
	MOVF        R0, 0 
	IORWF       R1, 0 
	BTFSC       STATUS+0, 2 
	GOTO        L_EnterBootloader5
;Main.c,89 :: 		USB_Polling_Proc();
	CALL        _USB_Polling_Proc+0, 0
;Main.c,91 :: 		if( HID_Read() )
	CALL        _HID_Read+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_EnterBootloader6
;Main.c,93 :: 		CheckCmd();
	CALL        _CheckCmd+0, 0
;Main.c,95 :: 		if( CmdCode == cmdINFO )
	MOVF        _CmdCode+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_EnterBootloader7
;Main.c,97 :: 		*(BootInfo*)(&HidWriteBuff+2) = mcuBootInfo;
	MOVLW       34
	MOVWF       R1 
	MOVLW       _HidWriteBuff+2
	MOVWF       FSR1 
	MOVLW       hi_addr(_HidWriteBuff+2)
	MOVWF       FSR1H 
	MOVLW       _mcuBootInfo+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(_mcuBootInfo+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(_mcuBootInfo+0)
	MOVWF       TBLPTRU 
L_EnterBootloader8:
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
	DECF        R1, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_EnterBootloader8
;Main.c,98 :: 		Ack( cmdINFO );
	MOVLW       1
	MOVWF       FARG_Ack_cmd+0 
	CALL        _Ack+0, 0
;Main.c,99 :: 		CmdCode = cmdNONE;
	CLRF        _CmdCode+0 
;Main.c,100 :: 		return 1;
	MOVLW       1
	MOVWF       R0 
	GOTO        L_end_EnterBootloader
;Main.c,101 :: 		}
L_EnterBootloader7:
;Main.c,102 :: 		}
L_EnterBootloader6:
;Main.c,104 :: 		Delay_ms(1);
	MOVLW       16
	MOVWF       R12, 0
	MOVLW       148
	MOVWF       R13, 0
L_EnterBootloader9:
	DECFSZ      R13, 1, 1
	BRA         L_EnterBootloader9
	DECFSZ      R12, 1, 1
	BRA         L_EnterBootloader9
	NOP
;Main.c,105 :: 		}
	GOTO        L_EnterBootloader4
L_EnterBootloader5:
;Main.c,107 :: 		return 0;
	CLRF        R0 
;Main.c,108 :: 		}
L_end_EnterBootloader:
	RETURN      0
; end of _EnterBootloader

_StartBootloader:

;Main.c,110 :: 		void StartBootloader()
;Main.c,112 :: 		while(1)
L_StartBootloader10:
;Main.c,114 :: 		USB_Polling_Proc();
	CALL        _USB_Polling_Proc+0, 0
;Main.c,116 :: 		if( HID_Read() )
	CALL        _HID_Read+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_StartBootloader12
;Main.c,118 :: 		CheckCmd();
	CALL        _CheckCmd+0, 0
;Main.c,120 :: 		if( CmdCode == cmdWRITE )
	MOVF        _CmdCode+0, 0 
	XORLW       3
	BTFSS       STATUS+0, 2 
	GOTO        L_StartBootloader13
;Main.c,122 :: 		if( WriteData == 0 )
	BTFSC       _flags+0, 0 
	GOTO        L_StartBootloader14
;Main.c,124 :: 		WriteData = 1;
	BSF         _flags+0, 0 
;Main.c,125 :: 		}
	GOTO        L_StartBootloader15
L_StartBootloader14:
;Main.c,128 :: 		if( Address < BOOTLOADER_START )
	MOVLW       0
	SUBLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L__StartBootloader33
	MOVLW       0
	SUBLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L__StartBootloader33
	MOVLW       98
	SUBWF       _Address+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__StartBootloader33
	MOVLW       192
	SUBWF       _Address+0, 0 
L__StartBootloader33:
	BTFSC       STATUS+0, 0 
	GOTO        L_StartBootloader16
;Main.c,129 :: 		Flash_Write_32( Address, &HidReadBuff[4] );
	MOVF        _Address+0, 0 
	MOVWF       FARG_FLASH_Write_32_address+0 
	MOVF        _Address+1, 0 
	MOVWF       FARG_FLASH_Write_32_address+1 
	MOVLW       0
	MOVWF       FARG_FLASH_Write_32_address+2 
	MOVWF       FARG_FLASH_Write_32_address+3 
	MOVLW       _HidReadBuff+4
	MOVWF       FARG_FLASH_Write_32_data_+0 
	MOVLW       hi_addr(_HidReadBuff+4)
	MOVWF       FARG_FLASH_Write_32_data_+1 
	CALL        _FLASH_Write_32+0, 0
L_StartBootloader16:
;Main.c,130 :: 		}
L_StartBootloader15:
;Main.c,131 :: 		Ack( cmdWRITE );
	MOVLW       3
	MOVWF       FARG_Ack_cmd+0 
	CALL        _Ack+0, 0
;Main.c,132 :: 		CmdCode = cmdNONE;
	CLRF        _CmdCode+0 
;Main.c,133 :: 		}
	GOTO        L_StartBootloader17
L_StartBootloader13:
;Main.c,135 :: 		else if( CmdCode == cmdERASE )
	MOVF        _CmdCode+0, 0 
	XORLW       4
	BTFSS       STATUS+0, 2 
	GOTO        L_StartBootloader18
;Main.c,139 :: 		for( EraseBlocks = 0; EraseBlocks < EraseBlockSize; EraseBlocks++ )
	CLRF        StartBootloader_EraseBlocks_L3+0 
	CLRF        StartBootloader_EraseBlocks_L3+1 
L_StartBootloader19:
	MOVF        _Address+1, 0 
	SUBWF       StartBootloader_EraseBlocks_L3+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__StartBootloader34
	MOVF        _Address+0, 0 
	SUBWF       StartBootloader_EraseBlocks_L3+0, 0 
L__StartBootloader34:
	BTFSC       STATUS+0, 0 
	GOTO        L_StartBootloader20
;Main.c,141 :: 		max = EraseBlocks * _FLASH_ERASE;
	MOVLW       6
	MOVWF       R0 
	MOVF        StartBootloader_EraseBlocks_L3+0, 0 
	MOVWF       StartBootloader_max_L3+0 
	MOVF        StartBootloader_EraseBlocks_L3+1, 0 
	MOVWF       StartBootloader_max_L3+1 
	MOVF        R0, 0 
L__StartBootloader35:
	BZ          L__StartBootloader36
	RLCF        StartBootloader_max_L3+0, 1 
	BCF         StartBootloader_max_L3+0, 0 
	RLCF        StartBootloader_max_L3+1, 1 
	ADDLW       255
	GOTO        L__StartBootloader35
L__StartBootloader36:
	MOVLW       0
	MOVWF       StartBootloader_max_L3+2 
	MOVWF       StartBootloader_max_L3+3 
;Main.c,142 :: 		if( max < BOOTLOADER_START )
	MOVLW       0
	SUBWF       StartBootloader_max_L3+3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__StartBootloader37
	MOVLW       0
	SUBWF       StartBootloader_max_L3+2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__StartBootloader37
	MOVLW       98
	SUBWF       StartBootloader_max_L3+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__StartBootloader37
	MOVLW       192
	SUBWF       StartBootloader_max_L3+0, 0 
L__StartBootloader37:
	BTFSC       STATUS+0, 0 
	GOTO        L_StartBootloader22
;Main.c,143 :: 		Flash_Erase_64( max );
	MOVF        StartBootloader_max_L3+0, 0 
	MOVWF       FARG_FLASH_Erase_64_address+0 
	MOVF        StartBootloader_max_L3+1, 0 
	MOVWF       FARG_FLASH_Erase_64_address+1 
	MOVF        StartBootloader_max_L3+2, 0 
	MOVWF       FARG_FLASH_Erase_64_address+2 
	MOVF        StartBootloader_max_L3+3, 0 
	MOVWF       FARG_FLASH_Erase_64_address+3 
	CALL        _FLASH_Erase_64+0, 0
L_StartBootloader22:
;Main.c,139 :: 		for( EraseBlocks = 0; EraseBlocks < EraseBlockSize; EraseBlocks++ )
	INFSNZ      StartBootloader_EraseBlocks_L3+0, 1 
	INCF        StartBootloader_EraseBlocks_L3+1, 1 
;Main.c,144 :: 		}
	GOTO        L_StartBootloader19
L_StartBootloader20:
;Main.c,145 :: 		Ack( cmdERASE );
	MOVLW       4
	MOVWF       FARG_Ack_cmd+0 
	CALL        _Ack+0, 0
;Main.c,146 :: 		CmdCode = cmdNONE;
	CLRF        _CmdCode+0 
;Main.c,147 :: 		}
	GOTO        L_StartBootloader23
L_StartBootloader18:
;Main.c,149 :: 		else if( CmdCode == cmdSTART )
	MOVF        _CmdCode+0, 0 
	XORLW       2
	BTFSS       STATUS+0, 2 
	GOTO        L_StartBootloader24
;Main.c,151 :: 		Ack( cmdSTART );
	MOVLW       2
	MOVWF       FARG_Ack_cmd+0 
	CALL        _Ack+0, 0
;Main.c,152 :: 		return;
	GOTO        L_end_StartBootloader
;Main.c,153 :: 		}
L_StartBootloader24:
L_StartBootloader23:
L_StartBootloader17:
;Main.c,154 :: 		}
L_StartBootloader12:
;Main.c,155 :: 		}
	GOTO        L_StartBootloader10
;Main.c,156 :: 		}
L_end_StartBootloader:
	RETURN      0
; end of _StartBootloader

_StartProgram:

;Main.c,159 :: 		void StartProgram()
;Main.c,161 :: 		asm sleep;
	SLEEP
;Main.c,162 :: 		}
L_end_StartProgram:
	RETURN      0
; end of _StartProgram

_main:

;Main.c,165 :: 		void main()
;Main.c,167 :: 		ConfigMem();
	MOVLW       0
	MOVWF       R0 
	MOVLW       4
	MOVWF       R1 
	MOVF        R0, 0 
	IORWF       R1, 0 
	BTFSC       STATUS+0, 2 
	GOTO        L_main25
L_main25:
;Main.c,169 :: 		HID_Enable( &HidReadBuff, &HidWriteBuff );
	MOVLW       _HidReadBuff+0
	MOVWF       FARG_HID_Enable_readbuff+0 
	MOVLW       hi_addr(_HidReadBuff+0)
	MOVWF       FARG_HID_Enable_readbuff+1 
	MOVLW       _HidWriteBuff+0
	MOVWF       FARG_HID_Enable_writebuff+0 
	MOVLW       hi_addr(_HidWriteBuff+0)
	MOVWF       FARG_HID_Enable_writebuff+1 
	CALL        _HID_Enable+0, 0
;Main.c,171 :: 		if( EnterBootloader() )
	CALL        _EnterBootloader+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main26
;Main.c,173 :: 		StartBootloader();
	CALL        _StartBootloader+0, 0
;Main.c,174 :: 		}
L_main26:
;Main.c,176 :: 		Hid_Disable();
	CALL        _HID_Disable+0, 0
;Main.c,177 :: 		Delay_ms(10);
	MOVLW       156
	MOVWF       R12, 0
	MOVLW       215
	MOVWF       R13, 0
L_main27:
	DECFSZ      R13, 1, 1
	BRA         L_main27
	DECFSZ      R12, 1, 1
	BRA         L_main27
;Main.c,178 :: 		StartProgram();
	CALL        25276, 0
;Main.c,179 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
