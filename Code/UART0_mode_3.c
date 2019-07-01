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
//  File Function: N76E003 UART-0 Mode3 demo code
//***********************************************************************************************************

#include "main.h"

#define BUFFER_SIZE		16
 //WIFI-DMX.COM
xdata UINT8  UART_BUFFER[BUFFER_SIZE],temp,dataxx;
xdata UINT16 u16CNT=0,u16CNT1=0;
bit riflag;
xdata uint8_t D485CRC,DMXCRC,DMXCRC_Slave,Priority;

/**
 * FUNCTION_PURPOSE: serial interrupt, echo received data.
 * FUNCTION_INPUTS: P3.0(RXD) serial input
 * FUNCTION_OUTPUTS: P3.1(TXD) serial output
 */
#if 0
void serial_IT(void) interrupt 4 
{
    if (RI) 
    {                                       /* if reception occur */
        clr_RI;                             /* clear reception flag for next reception */
        UART_BUFFER[u16CNT] = SBUF;
        u16CNT ++;
			  if(u16CNT >= 6)
				riflag =1;
    }
    if(TI)
    {
        clr_TI;                             /* if emission occur */
    }
}
#else
void serial_IT(void) interrupt 4 
{
    DMX512_Receive(&DMX_RegStructure,&DMX_Reg,1);
}
#endif

/*----------------------------
Send a byte data to UART
Input: dat (data to be sent)
Output:None
----------------------------*/
void SendAddress(uint8_t dat)
{
    TB8  = 0;            
    SBUF = dat;             //Send data to UART buffer
}
/*----------------------------
Send a byte data to UART
Input: dat (data to be sent)
Output:None
----------------------------*/
void SendData(uint8_t dat)
{
    TB8  = 1;            
    SBUF = dat;             //Send data to UART buffer
}

void USART_DMXSendPacket(void)
{
	if((SYS_StateBuf==SYS_Dmx)&&(Memory_Struct.Memory_NoDMXStatus==0)&&(RUN_State!=RUN_AutoTest))return;
	
	if((DMX_Reg.DMXTransmitFinish)&&(DMX_RegStructure.DMX_SIGNAL_MARK>=300)) 
	{
		DMX_RegStructure.DMXTransmitNow[D485_StobValue]=LED_RegStructure.StobValue;
		DMX_RegStructure.DMXTransmitNow[D485_StobState]=LED_RegStructure.LedStobState;
		
		DMX512_Master;
		DMX_Reg.DMXTransmitFinish=0;
		DMX_Reg.DMXTxCounter=0;
		DMXCRC=0;
		
		SendAddress(DMXAutoReceiveMark);
	}
}

/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void UART_Init(void)
{
//	UINT8 i;
   
    P06_Quasi_Mode;               					//Set UART GPIO are Quasi Mode
	P07_Quasi_Mode;
    InitialUART0_Timer3(250000+1);            /* 115200 Baud Rate from timer1*/
	
 //   SCON = 0xD2;														// Special setting the mode 3 
    
    set_ES;                                 //enable UART interrupt
    set_EA;                                 //enable global interrupt
 //   clr_TB8;
//    Send_Data_To_UART0(0x53);								//Send "start" ascii code show reset initial status
//	  Send_Data_To_UART0(0x74);
//	  Send_Data_To_UART0(0x61);
//	  Send_Data_To_UART0(0x72);
//	  Send_Data_To_UART0(0x74);
//		P10 = 1;
//	Timer0_Delay1ms(500);
/* 
    while(1);
		{
			if (riflag)
			{
				for(i=0; i<u16CNT; i++)
				{
				temp = UART_BUFFER[i];												//This part send the receive data from RXD to TXD 
				Send_Data_To_UART0(temp);
				}

				riflag = 0;
				u16CNT = 0;
			}
		}
*/	
}

