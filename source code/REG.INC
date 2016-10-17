
;CONST defined here
#define	CONST_KEY_DEBOUNCE	d'10'		;8ms

	
;;const          
#define		PORTA_INI	b'00000000'	; PORTA端口初值 
#define 	PORTB_INI	b'00000000'	; PORTB端口初值  

#define 	TRISA_INI	b'00000000'	; PORTA方向初值  0 输出 1输入
#define 	TRISB_INI	b'00111000'	; PORTB方向初值

#define 	PHCON_INI	b'11001111'	; 上拉 0 使能 1禁止
#define 	PDCON_INI	b'11111111'	; 下拉 0 使能 1禁止 
#Define 	ODCON_INI	b'00000000'	; 开漏输出      1 使能 0禁止


#define		OPTION_INI	b'10001001'	; X 上升沿下降沿 T0时钟源 T0计数沿选择 分频器派送 T0预分频1:1
#define 	T0_INI	        2		;156+1	4M/4T 256US	  8M4T 128

#define		PCON_INI	B'10111000'     ;WDT使能   外部int禁止	        
#define		IOCB_INI	B'00000000'     ;PB 中断和唤醒 0 禁止

#define		INTECON_INI	B'10000001'     ;B0=1，TM0中断使能   外部int禁止

;-------IO define------------------
#define		LedG1		PORTB,7		;POWER LED
#define		LedR1		PORTA,0
#define		LedG2		PORTB,5		;HEAT LED
#define		LedR2		PORTB,6
#define		Key0		PORTB,4		;开关机
#define		Zero_Fen	PORTB,3
#define		Triac		PORTB,2		;可控硅
#define		PIN_ZERO	PORTB,1		;过零点
#define		Gnd		PORTB,0
#define 	Buzzer		PORTA,3
#define 	RC_STD		PORTA,2
#define		RC_STD_IO	TRISA,2
#define		RC_NTC		PORTA,1
#define		RC_NTC_IO	TRISA,1

;--------------------------------------
#define c_ram_start		0x10
#define c_ram_end		0xC0

;;;;;;;ram start here,20~3f优先使用
cnt_buzzer_l	equ	0x20
cnt_buzzer_h	equ	0x21
cnt_100us	equ	0x22			;产生波特率300bps
cnt_5ms		equ	0x23
flag_txd	equ	0x24
#define		f_STD_err	flag_txd,0
#define		f_50s_over	flag_txd,4
#define		f_cnt_heat	flag_txd,2
#define		f_temp_getted	flag_txd,3
#define		f_delay_over	flag_txd,1
flag_byte	equ	0x25
#define		f_5ms		flag_byte,0
#define		f_pb5_high	flag_byte,1
#define		f_pb5_low	flag_byte,2
#define		f_first_light	flag_byte,3
#define		f_timecnt_start	flag_byte,4
#define		f_status_on	flag_byte,5
#define		f_keylock_long	flag_byte,6
#define		f_heat_on	flag_byte,7
led_byte	equ	0x26
#define		f_G1		led_byte,0	
#define		f_R1		led_byte,1	
#define		f_G2		led_byte,2	
#define		f_R2		led_byte,3	
#define		f_flash		led_byte,4		;0-加热完成，1-未加热，或加热未完成
#define		f_heat_over	led_byte,4		;0-加热完成，1-未加热，或加热未完成
key_byte	equ	0x27
#define		f_key0		key_byte,0
#define		f_key1		key_byte,1
#define		f_key2		key_byte,2
#define		f_key3		key_byte,3
#define		f_short_press	key_byte,4
#define		f_long_press	key_byte,5
zero_cross_byte		equ	0x3c
#define	F_STATUS_ON_B		zero_cross_byte,0
#define	F_ZEROCROSS_H_B		zero_cross_byte,1
#define	F_ZEROCROSS_L_B		zero_cross_byte,2
#define	F_ZERO_SURE_B		zero_cross_byte,3
;#define	F_STATUS_ON_G		zero_cross_byte,0
;#define	F_STATUS_ON_H		zero_cross_byte,0
;#define	F_STATUS_ON_J		zero_cross_byte,0
;#define	F_STATUS_ON_N		zero_cross_byte,0
cnt_pb4_h		equ	0x28
cnt_pb4_l		equ	0x29
cnt_pb5_h		equ	0x2a
cnt_pb5_l		equ	0x2b
state			equ	0x2c
cnt_delay_l		equ	0x2d
cnt_delay_h		equ	0x2e
cnt_NTC_err		equ	0x2f
cnt_1s			equ	0x30
cnt_key_release		equ	0x31
cnt_RC1			equ	0x32
data_STD		equ	0x33
data_NTC		equ	0x34
cnt_RC			equ	0x35
ZERO_CROSS_DELAY	equ	0x36
ZERO_CROSS_DELAY_BUFF	EQU	0x37
CNT_ONSCR_TIME		equ	0x38


pclath_temp	    	equ       0x3d 
status_temp     	equ       0x3e
w_temp          	equ       0x3f        
;;;;;ram ends here
	
;***********************************************************************

;-----------------------------------------------------------------------		
	
