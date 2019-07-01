#include "main.h"

 //WIFI-DMX.COM

xdata uint8_t Data[FMC_DAT_Length+10];
xdata uint8_t j=0,u32Data=0;


//void FLSH_Write(void){
//    for(j = 0; j < FMC_DAT_Length; j++)
//	{
//		write_DATAFLASH_BYTE(DATA_START_ADDR,Data[j]);
//    }	
//}

//void FLSH_Read(void){
//	for(j = 0; j < FMC_DAT_Length; j++){  
//		Data[j]=read_APROM_BYTE(DATA_START_ADDR+j);
//	}
//}

uint8_t IIC_Write(uint16_t xdata Address,uint8_t xdata ByteData){
//   Data[Address]=ByteData;
   write_DATAFLASH_BYTE(Address,ByteData);
   return 1;
}

uint8_t IIC_Read(UINT16 code *Address){
//	return Data[Address];
	return read_APROM_BYTE(Address);
}


void IIC_WriteAddress(void){ 
    IIC_Write(IIC_ADDRESS_DMXADDRH,(uint8_t)(Memory_Struct.Memory_Addr>>8));
    IIC_Write(IIC_ADDRESS_DMXADDRL,(uint8_t)Memory_Struct.Memory_Addr);
//	FLSH_Write();
}

void IIC_WriteColoLumValue(void){
    
	IIC_Write(IIC_ADDRESS_RedLumValue ,(uint8_t)LED_RegStructure.RedLumValue);
    IIC_Write(IIC_ADDRESS_GreenLumValue ,(uint8_t)LED_RegStructure.GreenLumValue);
    IIC_Write(IIC_ADDRESS_BlueLumValue ,(uint8_t)LED_RegStructure.BlueLumValue);
    IIC_Write(IIC_ADDRESS_WhiteLumValue ,(uint8_t)LED_RegStructure.WhiteLumValue);
    IIC_Write(IIC_ADDRESS_YellowLumValue ,(uint8_t)LED_RegStructure.YellowLumValue);
	IIC_Write(IIC_ADDRESS_PurpleLumValue ,(uint8_t)LED_RegStructure.PurpleLumValue);

	IIC_Write(IIC_ADDRESS_Stob ,(uint8_t)Memory_Struct.Memory_Stob);

	IIC_Write(IIC_ADDRESS_CalibrationsRed ,(uint8_t)Memory_Struct.Memory_CalibrationsRed);
    IIC_Write(IIC_ADDRESS_CalibrationsGreen ,(uint8_t)Memory_Struct.Memory_CalibrationsGreen);
	IIC_Write(IIC_ADDRESS_CalibrationsBlue ,(uint8_t)Memory_Struct.Memory_CalibrationsBlue);
	IIC_Write(IIC_ADDRESS_CalibrationsWhite ,(uint8_t)Memory_Struct.Memory_CalibrationsWhite);
	IIC_Write(IIC_ADDRESS_CalibrationsYellow ,(uint8_t)Memory_Struct.Memory_CalibrationsYellow);
    IIC_Write(IIC_ADDRESS_CalibrationsPurple ,(uint8_t)Memory_Struct.Memory_CalibrationsPurple);

   	IIC_Write(IIC_ADDRESS_AllLumValue ,(uint8_t)LED_RegStructure.AllLumValue);  
//	FLSH_Write();
}

void IIC_WriteHcl(void){ 
    IIC_Write(IIC_ADDRESS_Hcl ,(uint8_t)Memory_Struct.Memory_Hcl);
//	FLSH_Write();
}

void IIC_WriteFade(void){
	IIC_Write(IIC_ADDRESS_Fade ,(uint8_t)Memory_Struct.Memory_Fade);   
}

void IIC_WriteLed(void){ 
    IIC_Write(IIC_ADDRESS_LED ,(uint8_t)Memory_Struct.Memory_LED);
	IIC_Write(IIC_ADDRESS_BACKLED,(uint8_t)Memory_Struct.Memory_BACKLED);
//	FLSH_Write();	   
}

void IIC_WriteSoud(void){ 
    IIC_Write(IIC_ADDRESS_SOUD ,(uint8_t)Memory_Struct.Memory_Soud);   
//	FLSH_Write();
}

void IIC_WriteSose(void){ 
    IIC_Write(IIC_ADDRESS_SOSE ,(uint8_t)Memory_Struct.Memory_Sose);   
//	FLSH_Write();
}

void IIC_WriteSysState(void){ 
	IIC_Write(IIC_ADDRESS_SysState ,(uint8_t)SYS_State);
	IIC_Write(IIC_ADDRESS_SysStateBuf ,(uint8_t)SYS_StateBuf);  
//	FLSH_Write();
}

void IIC_WriteChan(void){ 
	IIC_Write(IIC_ADDRESS_Chan ,(uint8_t)Memory_Struct.Memory_Chan);  
//	FLSH_Write();
}

void IIC_WriteInverse(void){ 
	IIC_Write(IIC_ADDRESS_NoDMXStatus ,(uint8_t)Memory_Struct.Memory_NoDMXStatus);  
//	FLSH_Write();
}

void IIC_WriteDimmer(void){ 
	IIC_Write(IIC_ADDRESS_Dimmer ,(uint8_t)Memory_Struct.Memory_Dimmer);  
//	FLSH_Write();
}
 
void IIC_WriteFactory(void){  
	IIC_Write(IIC_ADDRESS_MARK,0xA6);
	IIC_WriteAddress();
	IIC_WriteLed();
	IIC_WriteSysState();
	IIC_WriteHcl();
	IIC_WriteFade();

	IIC_WriteChan();

	IIC_WriteSose();
	IIC_WriteSoud();

	IIC_WriteInverse();
	IIC_WriteDimmer();
	IIC_WriteColoLumValue();
}

void IIC_Eprom_Config(void)
{
//  SetDataFlashBase(FLSH_DAT_ADDR_BASE);
//	FLSH_Read();
    if(IIC_Read(IIC_ADDRESS_MARK)!=0xA6) //≥ı ºªØ
    {
		IIC_WriteFactory();
	}
	else
	{
		Memory_Struct.Memory_Addr=IIC_Read(IIC_ADDRESS_DMXADDRH)<<8;
		Memory_Struct.Memory_Addr|=IIC_Read(IIC_ADDRESS_DMXADDRL);
		LED_RegStructure.RedLumValue=IIC_Read(IIC_ADDRESS_RedLumValue);
		LED_RegStructure.GreenLumValue=IIC_Read(IIC_ADDRESS_GreenLumValue);
		LED_RegStructure.BlueLumValue=IIC_Read(IIC_ADDRESS_BlueLumValue);
		LED_RegStructure.WhiteLumValue=IIC_Read(IIC_ADDRESS_WhiteLumValue);
		LED_RegStructure.YellowLumValue=IIC_Read(IIC_ADDRESS_YellowLumValue);
		LED_RegStructure.PurpleLumValue=IIC_Read(IIC_ADDRESS_PurpleLumValue);

		Memory_Struct.Memory_Hcl=IIC_Read(IIC_ADDRESS_Hcl);
		Memory_Struct.Memory_Stob=IIC_Read(IIC_ADDRESS_Stob);
		Memory_Struct.Memory_Fade=IIC_Read(IIC_ADDRESS_Fade);
		
		Memory_Struct.Memory_LED=IIC_Read(IIC_ADDRESS_LED);
		Memory_Struct.Memory_Soud=IIC_Read(IIC_ADDRESS_SOUD);
		Memory_Struct.Memory_Sose=IIC_Read(IIC_ADDRESS_SOSE);
		LED_RegStructure.AllLumValue=IIC_Read(IIC_ADDRESS_AllLumValue);

		Memory_Struct.Memory_Chan=(Channel_Type)IIC_Read(IIC_ADDRESS_Chan);
	  		
		Memory_Struct.Memory_BACKLED=IIC_Read(IIC_ADDRESS_BACKLED);
		SYS_State=(SYS_Typedef)IIC_Read(IIC_ADDRESS_SysState);
		SYS_StateBuf=(SYS_Typedef)IIC_Read(IIC_ADDRESS_SysStateBuf);	 

		Memory_Struct.Memory_Dimmer=IIC_Read(IIC_ADDRESS_Dimmer);
		Memory_Struct.Memory_NoDMXStatus=IIC_Read(IIC_ADDRESS_NoDMXStatus);

		Memory_Struct.Memory_CalibrationsRed=IIC_Read(IIC_ADDRESS_CalibrationsRed);
		Memory_Struct.Memory_CalibrationsGreen=IIC_Read(IIC_ADDRESS_CalibrationsGreen);
		Memory_Struct.Memory_CalibrationsBlue=IIC_Read(IIC_ADDRESS_CalibrationsBlue);
		Memory_Struct.Memory_CalibrationsWhite=IIC_Read(IIC_ADDRESS_CalibrationsWhite);
		Memory_Struct.Memory_CalibrationsYellow=IIC_Read(IIC_ADDRESS_CalibrationsYellow);
		Memory_Struct.Memory_CalibrationsPurple=IIC_Read(IIC_ADDRESS_CalibrationsPurple);

		
		LCM_LIGHT_ON;
		SysBuf=SYS_State;
		
		Memory_Stob=Memory_Struct.Memory_Stob;

 		PurpleLumValue=LED_RegStructure.PurpleLumValue;
		YellowLumValue=LED_RegStructure.YellowLumValue;
		WhiteLumValue=LED_RegStructure.WhiteLumValue;
		BlueLumValue=LED_RegStructure.BlueLumValue;
		GreenLumValue=LED_RegStructure.GreenLumValue;
		RedLumValue=LED_RegStructure.RedLumValue;
	   
	}    
}

/*******************************************************************************************************
                                 end  file!!!
********************************************************************************************************/

