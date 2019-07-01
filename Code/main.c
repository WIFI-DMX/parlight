/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2016 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/21/2016
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E003 demo code
//***********************************************************************************************************
#include "main.h"
 //WIFI-DMX.COM
uint32_t idata LocalTime = 0;
xdata uint8_t SysBuf=0,LCDDisplight=1;

xdata SYS_Typedef SYS_State=SYS_Dmx;
xdata SYS_Typedef SYS_StateBuf=SYS_Dmx;
xdata RUN_Typedef RUN_State=RUN_Reset;
xdata uint16_t SystemNum,KeyBuf1=0xff,KeyBuf2=0xff;
xdata uint16_t BackLightNum=1,TimeOut=0,Task_Sys_i=0,Task_XY_State=0,Task_COLOR_State=0;
xdata uint8_t COLO_SIGNAL_MARK=1,Reset_Mark=0,Reset_Time=0,Temp_Reset=0,TempDispMark=0,Temperature=31;


/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main(void)
{
	Set_All_GPIO_Quasi_Mode;
	Pwm_Init();
	P05_PushPull_Mode;
//	TM1618_Update(LED_0,LED_1,LED_2,LED_3,LED_PN);
	IIC_Eprom_Config();
	Task_Init();
	Timer2_Init();
	UART_Init();
	RUN_State=RUN_Normal;	
	SYS_MenuInit();
	MenuShow();
	//DataFlashCheck();
	while(1){
		Task_Run(Task_st,Task_Null,&Priority);
	}
}