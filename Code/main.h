#ifndef _MAIN_H
#define _MAIN_H
 //WIFI-DMX.COM
#include <stdio.h>
#include "N76E003.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "Tm1618_n76.h"
#include "task.h"
#include "task_51.h"
#include "menu.h"
#include "menu_fun_seg.h"
#include "led.h"	
#include "wx_i2c_51.h"
#include "usart_n76.h"
#include "uled_n76.h"


#define ABS(x,y) ((x>y)?(x-y):(y-x))

#define DMX_Value_20Y   55
#define DMX_Value_45Y   100
#define DMX_Value_90Y   128
#define DMX_Value_135Y  154
#define DMX_Value_150Y  200
#define DMX_Value_255Y  255

#define LCM_SEG_ENABLE	    (1)

#define TM1618_DIO_SET     P16=1
#define TM1618_DIO_CLR     P16=0
#define TM1618_CLK_SET     P14=1
#define TM1618_CLK_CLR     P14=0
#define TM1618_STB_SET     P13=1
#define TM1618_STB_CLR     P13=0
#define TM1618_DIO_READ    P16	

#define DMX_CS_Pin		    P05
#define DMX512_Master       DMX_CS_Pin=1
#define DMX512_Slave        DMX_CS_Pin=0
//#define DMX512_UART         USART1	 


#define DMX_RED_CH1        1
#define DMX_GREEN_CH1      2
#define DMX_BLUE_CH1       3
#define DMX_WHITE_CH1      4

#define DMX_DIMMER_CH2     1
#define DMX_RED_CH2        2
#define DMX_GREEN_CH2      3
#define DMX_BLUE_CH2       4
#define DMX_WHITE_CH2      5	
#define DMX_STROBE_CH2     6
#define DMX_AUTO_CH2       7   //(255-10)/20  <170
#define DMX_SPEED_CH2      8



//°´¼üÊôÐÔ
	
#define	Up	    0xD0	                    						   
#define Down    0xB0                      				      	      			      
//#define	Enter   MENU_ENTER_Pin	
#define	Enter   0x70				 
#define Esc     0xE0	
				 
#define NO_KEY  0xF0 


#define LCM_LIGHT_ON  LCDDisplight=1 
#define LCM_LIGHT_OFF LCDDisplight=0


typedef enum
{
	SYS_Dmx	      =((uint8_t)0),
	SYS_Auto	  =((uint8_t)1),
	SYS_Slave	  =((uint8_t)2),
	SYS_Soud	  =((uint8_t)3),
	SYS_Colo	  =((uint8_t)4),
}SYS_Typedef;
extern xdata SYS_Typedef SYS_State;
extern xdata SYS_Typedef SYS_StateBuf;

typedef enum
{
 RUN_Reset	  =((uint8_t)0),
 RUN_Prepare  =((uint8_t)1),
 RUN_Normal	  =((uint8_t)2),
 RUN_AutoTest =((uint8_t)3),
}RUN_Typedef;
extern xdata RUN_Typedef RUN_State;



//#define     DATA_SIZE           (128*1)   

#define COLOR_6_ENABLE	    (0)


#define Calibrations_N    200
#define Calibrations_Min  128

#define LED_Point_Num     (4)

#define PWM_MAX	    (4096-1)
#define PWM_INIT    (2000-1)

#define Drv_LED_R    4
#define Drv_LED_G    5
#define Drv_LED_B    0  
#define Drv_LED_W    3 
#define Drv_LED_Y    2
#define Drv_LED_P    1

#define FMC_DAT_Length 	 (60)


void SendAddress(uint8_t dat);
void SendData(uint8_t dat);


void Pwm_Update(uint8_t state,uint16_t pwm);
void Pwm_Init(void);
void Timer2_Init(void);
void UART_Init(void);
extern xdata uint16_t SystemNum,KeyBuf1,KeyBuf2;
extern xdata uint8_t SysBuf,LCDDisplight;
extern xdata uint16_t BackLightNum,TimeOut,Task_Sys_i,Task_XY_State,Task_COLOR_State;
extern xdata uint8_t COLO_SIGNAL_MARK,Reset_Mark,Reset_Time,Temp_Reset,TempDispMark,Temperature;

extern xdata uint8_t D485CRC,DMXCRC,DMXCRC_Slave,Priority;

UINT8 read_APROM_BYTE(UINT16 code *u16_addr);
void write_DATAFLASH_BYTE(UINT16 xdata u16_addr,UINT8 xdata u8_data);


#endif /* _H */