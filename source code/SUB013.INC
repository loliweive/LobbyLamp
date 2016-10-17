

;******************013ϵͳ��ʼ��******************************
system_init:

	call	port_ini_013
	call	ram_clr_013
	call	main_ini_013
	
system_init_end:

	return
;----------------------------------------------------------

;****************PORT��ʼ��************************************
port_ini_013:

	MOVLW	PORTA_INI
	MOVWF	PORTA
		
	MOVLW	TRISA_INI
	MOVWF	TRISA
		
	MOVLW	PORTB_INI
	MOVWF	PORTB

	MOVLW	TRISB_INI
	MOVWF	TRISB
	
	MOVLW	ODCON_INI
	MOVWF	ODCON	
	
	MOVLW	PHCON_INI
	MOVWF	PHCON	

	MOVLW	PDCON_INI
	MOVWF	PDCON
	
	MOVLW	IOCB_INI
	MOVWF	IOCB	

		
port_ini_end:

	return
;---------------------------------------------------------------

;********************��RAM**************************************
ram_clr_013:
	
	CLRF    0X07
	clrwdt
	MOVLW	c_ram_start
	MOVWF	FSR
	
_INI_RAM_Loop:
	CLRF	INDF
	INCF	FSR, F

	MOVF    FSR,W
	XORLW	c_ram_end 
	BTFSS	Z         
	GOTO	_INI_RAM_Loop  
	
ram_clr_end:

	return	
;-------------------------------------------------------------------

;**********************�������ʼ��*************************************
main_ini_013:

	MOVLW	OPTION_INI		 
	MOVWF	OPTION

	MOVLW	T0_INI
	MOVWF   T0

	BCF	T0IF
	
	MOVLW	PCON_INI
	MOVWF	PCON
	
	MOVLW   INTECON_INI
	MOVWF   INTECON

	
main_ini_end:

	return
;---------------------------------------------------------------------