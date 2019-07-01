#ifndef _USART_N76_H
#define	_USART_N76_H
 //WIFI-DMX.COM
#include "Common.h"
//#include "rdm_config.h"

#define USART_TypeDef UART_T

#define DMX512BUFSIZE      20

#define D485_CRC     16
#define DMX_CRC      16
#define D485_MASTER    18
#define D485_SLAVE     18

#define DMXAutoReceiveMark 0x0088
#define DMXTempMark        0x00AA

typedef enum
{
	D485_Dimmer	    =((uint8_t)1),
	D485_STROBE	    =((uint8_t)2),
	D485_RED	    =((uint8_t)3),
	D485_GREEN	    =((uint8_t)4),
	D485_BLED	    =((uint8_t)5),
	D485_WHITE	    =((uint8_t)6),
	D485_YELLOW	    =((uint8_t)7),
	D485_PURPLE   	=((uint8_t)8),
	D485_StobValue	=((uint8_t)9),
	D485_StobState  =((uint8_t)10),

}DMX_Typedef;

typedef enum
{
	Signal_Null	      =((uint8_t)0),
	Signal_Dmx	      =((uint8_t)1),
	Signal_Slave	  =((uint8_t)2),
	Signal_Rdm	      =((uint8_t)3),
	Signal_Master	  =((uint8_t)4),
}Signal_Typedef;

typedef struct 	
{ 
uint8_t 
	DMX_SIGNAL_MARK,
	DMX_SIGNAL_ON, 
	DMXFinish, 
	DMXChange;
uint8_t 
	VUIV_CRC,
	//dmx_Recv_msg[255],
	DMXReceiveNow[DMX512BUFSIZE+4],
	DMXTransmitNow[DMX512BUFSIZE+4];
//  D485ReceiveNow[DMX512BUFSIZE+4],
//  D485TransmitNow[DMX512BUFSIZE+4],
//  DMXReceiveBuffer[DMX512BUFSIZE+4];
uint16_t 
	VUIV_data_length;
	//dmx_Recv_data[520];
	//VUIV_Recv_data[300];
}DMX_TypeDef;

typedef struct 	
{ 
uint16_t 
	UDR,
	pAddrData,
	pDMXData,
	pRDMData,
	DMXTxCounter,
	D485TxCounter,
	DMXTransmitFinish,
	D485TransmitFinish,
	DMX_Chang_Mark,
	DMX_Out_Mark;
	Signal_Typedef
	aFlagMark;
uint8_t 
	Move_Finish;
uint16_t 
	i;
}DMX_Type;

extern xdata DMX_TypeDef DMX_RegStructure;
extern xdata DMX_Type DMX_Reg;

void DMX512_Receive(DMX_TypeDef xdata *DMX,DMX_Type xdata *D,uint8_t xdata schang);

#endif
