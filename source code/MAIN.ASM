 
	list p = 18p013, r=dec
	#include "hc18p013.inc"			
	#include "reg.inc"
;	#include "sub010.inc"


;********************************************
;               code start                  
;********************************************

        org     0000h	
        goto    reset  
        goto    reset   
	goto    reset   
        goto    reset 
        goto    reset  
        goto    reset   
	goto    reset   
        goto    reset       
                
        org     0008h  						
int_start:		

	movwf	w_temp
	swapf	w_temp,f	; save w
	swapf	STATUS,W
	movwf	status_temp	; save status
     
	btfss	T0IF		;125us  8M4T
	goto	int_exit
	bcf	T0IF
	
	movlw	T0_INI
	movwf	T0
		
int_timeflag:
	
	incf	cnt_100us,f
	movlw	d'40'		
	subwf	cnt_100us,w
	btfss	C
	goto	int_timeflag_end
	clrf	cnt_100us
	bsf	f_5ms		
		
int_timeflag_end:
;-----------------------------------------------
int_exit:
    							
	swapf	status_temp, w
	movwf	STATUS				
        swapf	w_temp, w					
	retfie				

;***************************************  	  

reset:   
        clrf    INTECON
        clrf	INTFLAG
	clrf	PCON    
 	clrwdt
 	call	system_init

	
	
;====================================================================	
;				主函数
;====================================================================
mainloop:

	clrwdt	       
	btfss	f_5ms
	goto	mainloop
	bcf	f_5ms
	call	get_pb4_status
	call	status_proc
	call	time_cnt
	goto	mainloop
	
;-----------------------------------------------------------

;***********************************************************
;
;***********************************************************	
get_pb4_status:

	btfss	PORTB,4
	goto	pb4_low
	goto	pb4_high
	
pb4_low:

	clrf	cnt_pb4_h
	incf	cnt_pb4_l,f
	movlw	d'10'
	subwf	cnt_pb4_l,w
	btfss	C
	goto	get_pb4_status_end
	clrf	cnt_pb4_l
	bsf	f_status_on
	goto	get_pb4_status_end
	
pb4_high:

	clrf	cnt_pb4_l
	incf	cnt_pb4_h,f
	movlw	d'10'
	subwf	cnt_pb4_h,w
	btfss	C
	goto	get_pb4_status_end
	clrf	cnt_pb4_h
	bcf	f_status_on
	goto	get_pb4_status_end
	
get_pb4_status_end:

	return
;-----------------------------------------------------------

;***********************************************************
;
;***********************************************************
status_proc:

	btfss	f_status_on
	goto	power_off
	goto	get_pb5_status
	
get_pb5_status:

	btfss	PORTB,5
	goto	pb5_low
	goto	pb5_high
	
pb5_low:

	clrf	cnt_pb5_h
	incf	cnt_pb5_l,f
	movlw	d'10'
	subwf	cnt_pb5_l,w
	btfss	C
	goto	status_proc_end
	clrf	cnt_pb5_l		;;;;;;;;此处开关为关的时候，是否应该关灯，而不论现在处于何种状态,,,不应该关灯
	bsf	f_pb5_low
	goto	status_proc_end
	
pb5_high:

	clrf	cnt_pb5_l
	incf	cnt_pb5_h,f
	movlw	d'10'
	subwf	cnt_pb5_h,w
	btfss	C
	goto	status_proc_end
	clrf	cnt_pb5_h
	bsf	f_pb5_high
	btfss	f_pb5_low
	goto	get_pb5_status_end
	bcf	f_pb5_low
	clrf	cnt_delay_l
	clrf	cnt_delay_h
	bsf	PORTB,0
	bsf	PORTB,1	
	bsf	f_timecnt_start
	goto	status_proc_end
	
get_pb5_status_end:
	
	btfsc	f_first_light
	goto	status_proc_end
	bsf	f_timecnt_start
	bsf	PORTB,0
	bsf	PORTB,1	
	bsf	f_first_light
	goto	status_proc_end
	
power_off:

	bcf	PORTB,0
	bcf	PORTB,1
	bcf	f_pb5_low
	bcf	f_pb5_high
	bcf	f_first_light
	bcf	f_timecnt_start
	clrf	cnt_delay_l
	clrf	cnt_delay_h
	goto	status_proc_end
	
status_proc_end:

	return
;-----------------------------------------------------------
;***********************************************************
;
;***********************************************************
time_cnt:

	btfss	f_timecnt_start
	goto	time_cnt_end
	
	incf	cnt_delay_l,f
	movlw	d'186'
	subwf	cnt_delay_l,w
	btfss	C
	goto	time_cnt_end
	clrf	cnt_delay_l
	incf	cnt_delay_h,f
	movlw	d'30'
	subwf	cnt_delay_h,w
	btfss	C
	goto	time_cnt_end
	goto	pb0_auto_low	
	
pb0_auto_low:

	bcf	PORTB,0
	movlw	d'60'
	subwf	cnt_delay_h,w
	btfss	C
	goto	time_cnt_end
	clrf	cnt_delay_h
	bcf	PORTB,1
	goto	time_cnt_end
	
time_cnt_end:

	return
	
	
;********************************************
       #include "sub013.inc" 		;此包含可放在0~3ff中间任何位置
;       #include "key.inc"
;       #include	"zero.inc"
        org     03ffh                          
        goto    reset                           
        end


;********************************************
;               code end                    
;********************************************

