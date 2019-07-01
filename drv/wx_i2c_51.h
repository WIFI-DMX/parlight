#ifndef _WX_I2C_H
#define _WX_I2C_H
 //WIFI-DMX.COM
#include "Common.h"

typedef enum
{
 IIC_ADDRESS_MARK0	  =((uint16_t)0x4600),
 IIC_ADDRESS_MARK,       
 IIC_ADDRESS_DMXADDRH,
 IIC_ADDRESS_DMXADDRL,
 IIC_ADDRESS_RedLumValue,
 IIC_ADDRESS_GreenLumValue,
 IIC_ADDRESS_BlueLumValue,
 IIC_ADDRESS_WhiteLumValue,
 IIC_ADDRESS_YellowLumValue,
 IIC_ADDRESS_PurpleLumValue,
 IIC_ADDRESS_CalibrationsRed,
 IIC_ADDRESS_CalibrationsGreen,
 IIC_ADDRESS_CalibrationsBlue,
 IIC_ADDRESS_CalibrationsWhite,	
 IIC_ADDRESS_CalibrationsYellow,
 IIC_ADDRESS_CalibrationsPurple,
 IIC_ADDRESS_Chan,
 IIC_ADDRESS_SysStateBuf,
 IIC_ADDRESS_SysState,

 IIC_ADDRESS_LED,
 IIC_ADDRESS_SOUD,
 IIC_ADDRESS_SOSE,
 IIC_ADDRESS_Hcl,
 IIC_ADDRESS_Stob,
 IIC_ADDRESS_Fade,	

 IIC_ADDRESS_NoDMXStatus,  
 IIC_ADDRESS_BACKLED,
 IIC_ADDRESS_TLedStob,
 IIC_ADDRESS_TLedHcl,
 IIC_ADDRESS_TLedFade, 

 IIC_ADDRESS_Dimmer,
 IIC_ADDRESS_AllLumValue,	 
}IIC_ADDRESS;


void FLSH_Write(void);
void FLSH_Read(void);

void IIC_WriteAddress(void);
void IIC_WriteColoLumValue(void);
void IIC_WriteStob(void);
void IIC_WriteHcl(void);
void IIC_WriteFade(void);

void IIC_WriteLed(void);
void IIC_WriteSoud(void);
void IIC_WriteSose(void);
void IIC_WriteSysState(void);

void IIC_WriteAllLumValue(void);	

void IIC_WriteChan(void);
void IIC_WriteInverse(void);

void IIC_WriteFactory(void);
void IIC_WriteDimmer(void);

void IIC_Eprom_Config(void);


extern xdata uint8_t Data[];

#endif

/*******************************************************************************************************
					endfile!!!
********************************************************************************************************/

