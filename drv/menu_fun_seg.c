#include "main.h"

 //WIFI-DMX.COM

xdata Memory_TypeDef Memory_Struct=
{	
        0,0,Calibrations_N,Calibrations_N,Calibrations_N,Calibrations_N,Calibrations_N,Calibrations_N,0,1,0,50,_SlaveMode1,0,10,200,0,_2channel,1,1,1,1,1,0,0,_English,_Normal,_Auto_On,  
};
xdata LEDSEG_TypeDef LEDMenu_Buf=
{
		0x87,0xA3,0x8C,0xFF   
};
xdata LEDSEG_TypeDef LEDTemp_Buf=
{
		0,0,0,0   
};

void Update_Clear(void){
	Memory_Struct.Memory_Soud=0;
	Memory_Struct.Memory_Stob=0;

	LED_RegStructure.PurpleLumValue=0;
	LED_RegStructure.YellowLumValue=0;
	LED_RegStructure.WhiteLumValue=0;
	LED_RegStructure.BlueLumValue=0;
	LED_RegStructure.GreenLumValue=0;
	LED_RegStructure.RedLumValue=0;

	LedStobValueUpdate(Memory_Struct.Memory_Stob);
}

void UpdateExitMain(void){
    SystemNum=BackSystemTime-30;
}

void UpdateDmxAddress(void){
	DMX512_Slave;
	SYS_State=SYS_Dmx;
	SysBuf=SYS_State;SYS_StateBuf=SYS_State;
	IIC_WriteAddress();
}

void UpdateChanne(void){
	IIC_WriteChan();
//	Led.DMXHclState=0;
}

void UpdateChannel1(void){
	Memory_Struct.Memory_Chan=_1channel;
	UpdateChanne();
}

void UpdateChannel2(void){
	Memory_Struct.Memory_Chan=_2channel;
	UpdateChanne();
}

//void UpdateChannel3(void){
//	Memory_Struct.Memory_Chan=_3channel;
//	UpdateChanne();
//}

//void UpdateChannel4(void){
//	Memory_Struct.Memory_Chan=_4channel;
//	IIC_WriteChan();						   
//	UpdateChanne();
//}

void SlaveMode(void){
	if(SYS_State!=SYS_Slave){
		Update_Clear();
	}
	SYS_State=SYS_Slave;
	SysBuf=SYS_State;SYS_StateBuf=SYS_State;
	DMX512_Slave;
	
	IIC_WriteSysState();    
}

void Update_Slave1Mode(void){
	Memory_Struct.Memory_Mode=_SlaveMode1;
	SlaveMode();	

}
//void Update_Slave2Mode(void){   	
//	Memory_Struct.Memory_Mode=_SlaveMode2;
//	SlaveMode();
//}

void Update_SoundOn(void){   
	Memory_Struct.Memory_Soud=1;
	LED_RegStructure.ChangValue=1;
	LED_RegStructure.HclValue=0;
	LED_RegStructure.FadeValue=0;
	LED_RegStructure.StobValue=0;

	SYS_State=SYS_Soud;
	SysBuf=SYS_State;SYS_StateBuf=SYS_State;

	Update_Clear();

    IIC_WriteSoud();
	IIC_WriteSysState();
}

void Update_ResetYes(void){

	Reset_Mark=0;
	Temp_Reset=0;
	COLO_SIGNAL_MARK=1;
	DisplayStart     = 0; 			     
	UserChoose       = 0; 				 
	DisplayPoint     = 0; 				  
	MaxItems         = 0;  			  
	Option		    = 0;   
	Option1		    = 0;
	Task_Clear();
	Task_Cmd(&Task_st[TLedDMXFade],&Task_LedDMXFade,TaskEnable,Task_Null);
	RUN_State=RUN_Reset;
//	DeviceInit(&DeviceInfoStruct);
}

void Update_ResetNo(void){	

}  

void Update_FactoryYes(void){

	Memory_Struct.Memory_Addr=1;
	Memory_Struct.Memory_Stob=0;
	Memory_Struct.Memory_Chan=_2channel;
	Memory_Struct.Memory_NoDMXStatus=0;	  

//	Memory_Struct.Memory_Dimmer=0;
//	Memory_Struct.Memory_RefreshRate=1;
//	Memory_Struct.Memory_Smooth=1;
//	Memory_Struct.Memory_RAuto=_Auto_On;

//    TIME_Prescaler(Prescaler_1);
	LED_RegStructure.RedLumValue=0;
    LED_RegStructure.GreenLumValue=0;
    LED_RegStructure.BlueLumValue=0;

    LED_RegStructure.WhiteLumValue=0;
    LED_RegStructure.YellowLumValue=0;
    LED_RegStructure.PurpleLumValue=0;

	Memory_Struct.Memory_LED=0;
	SYS_State=SYS_Dmx;
	SysBuf=SYS_State;SYS_StateBuf=SYS_State;
	Memory_Struct.Memory_BACKLED=10;
	Memory_Struct.Memory_Hcl=1;
	Memory_Struct.Memory_Soud=0;
	Memory_Struct.Memory_Mode=_SlaveMode1;
	Memory_Struct.Memory_Sose=200;
	LCM_LIGHT_ON;
	DMX512_Slave;
//	Wireless=3;Wireless_L;

	IIC_WriteFactory();
	LedStobValueUpdate(Memory_Struct.Memory_Stob);

	PurpleLumValue=0;
	YellowLumValue=0;
	WhiteLumValue=0;
	BlueLumValue=0;
	GreenLumValue=0;
	RedLumValue=0;
	
	KeyBuf1=0xff,KeyBuf2=0xff;
} 

void Update_FactoryNo(void){	
} 

void Update_NoDMXStatusClose(void){
   if(Memory_Struct.Memory_NoDMXStatus)SYS_State=SYS_Dmx;
   Memory_Struct.Memory_NoDMXStatus=0;  
   IIC_WriteInverse();	
}

void Update_NoDMXStatusHold(void){  
   if(Memory_Struct.Memory_NoDMXStatus>1)SYS_State=SYS_Dmx;
   Memory_Struct.Memory_NoDMXStatus=1;
   IIC_WriteInverse();   	
}
/*
void Update_NoDMXStatusAuto(void){ 
   if(Memory_Struct.Memory_NoDMXStatus>1)SYS_State=SYS_Dmx;
   Memory_Struct.Memory_NoDMXStatus=2;
   IIC_WriteInverse(); 	
}

void Update_NoDMXStatusSound(void){
   if(Memory_Struct.Memory_NoDMXStatus>1)SYS_State=SYS_Dmx;
   Memory_Struct.Memory_NoDMXStatus=3;
   IIC_WriteInverse();	
}
*/

/*
void Update_Dimmer0(void){
   Memory_Struct.Memory_Dimmer=0;
   IIC_WriteDimmer(); 	
}

void Update_Dimmer1(void){
   Memory_Struct.Memory_Dimmer=1;
   IIC_WriteDimmer();  	
}

void Update_Dimmer2(void){
   Memory_Struct.Memory_Dimmer=2;
   IIC_WriteDimmer(); 	
}

void Update_Dimmer3(void){
   Memory_Struct.Memory_Dimmer=3;
   IIC_WriteDimmer(); 	
}

void Update_RefreshRate0(void){
   Memory_Struct.Memory_RefreshRate=0;
//   TIME_Prescaler(Prescaler_0);
   IIC_WriteDimmer(); 	
}

void Update_RefreshRate1(void){
   Memory_Struct.Memory_RefreshRate=1;
//   TIME_Prescaler(Prescaler_1);
   IIC_WriteDimmer();  	
}

void Update_RefreshRate2(void){
   Memory_Struct.Memory_RefreshRate=2;
//   TIME_Prescaler(Prescaler_2);
   IIC_WriteDimmer(); 	
}

void Update_RefreshRate3(void){
   Memory_Struct.Memory_RefreshRate=3;
//   TIME_Prescaler(Prescaler_3);
   IIC_WriteDimmer(); 	
}


void Update_Smooth0(void){
   Memory_Struct.Memory_Smooth=0;
   IIC_WriteDimmer();  	
}

void Update_Smooth1(void){
   Memory_Struct.Memory_Smooth=1;
   IIC_WriteDimmer(); 	
}

void Update_Smooth2(void){
   Memory_Struct.Memory_Smooth=2;
   IIC_WriteDimmer(); 	
}

void Update_Smooth3(void){
   Memory_Struct.Memory_Smooth=3;
   IIC_WriteDimmer(); 	
}
*/

/*
void Update_Degree1(void){
   Memory_Struct.Memory_Degree=1;
   IIC_WriteInverse();  	
}

void Update_Degree2(void){
   Memory_Struct.Memory_Degree=0;
   IIC_WriteInverse();  	
}

void Update_Chinese(void){
   Memory_Struct.Memory_Language=_Chinese;
   IIC_WriteLanguage();  	
}

void Update_English(void){
   Memory_Struct.Memory_Language=_English;
   IIC_WriteLanguage(); 	
}

void Update_RotaN(void){
   Memory_Struct.Memory_Rota=_Normal;
   Memory_Struct.Memory_RAuto=_Auto_Off;
   IIC_WriteRota(); 	
   KeyBuf1=0xff,KeyBuf2=0xff;
}

void Update_RotaR(void){
   Memory_Struct.Memory_Rota=_Rotate180;
   Memory_Struct.Memory_RAuto=_Auto_Off;
   IIC_WriteRota();  	
   KeyBuf1=0xff,KeyBuf2=0xff;
}

void Update_RotaA(void){
   Memory_Struct.Memory_RAuto=_Auto_On;
   IIC_WriteRota(); 	
   KeyBuf1=0xff,KeyBuf2=0xff;
}
*/
/*
void Update_SoundOff(void){
	Memory_Struct.Memory_Soud=0;
	DMX512_Slave;
	SYS_State=SYS_Dmx;
	SysBuf=SYS_State;SYS_StateBuf=SYS_State;	
	IIC_WriteSoud();
	IIC_WriteSysState();
	Update_Clear();
}
*/
void Update_SoundSose(void){   
	 IIC_WriteSose();   
}

void Update_BackLEDOn(void){
	Memory_Struct.Memory_LED=1;
	IIC_WriteLed();			
}

void Update_BackLED(void){
	//Memory_Struct.Memory_LED=1;
	IIC_WriteLed();			
}

void Update_BackLEDOff(void){
	Memory_Struct.Memory_LED=0;	
	IIC_WriteLed();			
}
/******************************************************************************/

void Update_ManuFunction(void){  
    IIC_WriteColoLumValue();
	IIC_WriteSysState();  
}	 

void Update_CalibrationsDefaultFunction(void){  
    Memory_Struct.Memory_CalibrationsRed=Calibrations_N;
	Memory_Struct.Memory_CalibrationsGreen=Calibrations_N;
	Memory_Struct.Memory_CalibrationsBlue=Calibrations_N;
	Memory_Struct.Memory_CalibrationsWhite=Calibrations_N;
	Memory_Struct.Memory_CalibrationsYellow=Calibrations_N;
	Memory_Struct.Memory_CalibrationsPurple=Calibrations_N;

	IIC_WriteColoLumValue();
	IIC_WriteSysState(); 	
}

void Enter_AddrFunction(void){  
	if(SYS_State!=SYS_Dmx){
		Update_Clear();
	}
	SYS_State=SYS_Dmx;
	SysBuf=SYS_State;SYS_StateBuf=SYS_State;
	DMX512_Slave;	
	IIC_WriteSysState();
}

void Enter_ManuFunction(void){  
	if(RUN_State==RUN_Normal)COLO_SIGNAL_MARK=0;
	if(SYS_State!=SYS_Colo){
		SYS_State=SYS_Colo;
		SysBuf=SYS_State;SYS_StateBuf=SYS_State;
		Update_Clear();
	}
//	DMX_RegStructure.D485TransmitNow[D485_XY_Speed]=0;
	Memory_Struct.Memory_Soud=0;	
	Memory_Struct.Memory_Stob=Memory_Stob,

	LED_RegStructure.PurpleLumValue=PurpleLumValue,
	LED_RegStructure.YellowLumValue=YellowLumValue,
	LED_RegStructure.WhiteLumValue=WhiteLumValue,
	LED_RegStructure.BlueLumValue=BlueLumValue,
	LED_RegStructure.GreenLumValue=GreenLumValue,
	LED_RegStructure.RedLumValue=RedLumValue,

	Task_Colo();	
	IIC_WriteSysState();
}

void Enter_AutoFunction(void){  
	if(SYS_State!=SYS_Auto){
		LED_RegStructure.HclValue=0;
		LED_RegStructure.ChangValue=1;
		Task_Sys_i=0;
		Update_Clear();
	}
	SYS_State=SYS_Auto;
	SysBuf=SYS_State;SYS_StateBuf=SYS_State;		
	Memory_Struct.Memory_Soud=0;	
	IIC_WriteSysState();     
}
/********************************************************************************/
void Update_AutoHclFunction(void){    
	IIC_WriteSysState();
	IIC_WriteHcl();
}
void Update_AutoFadeFunction(void){    
	IIC_WriteSysState();
	IIC_WriteFade();
}

//void Update_AutoStobFunction(void){
//	IIC_WriteSysState();
//	IIC_WriteStob();
//	IIC_WriteStobState(); 
//}

//void Update_AutoTestOn(void){	
//	LED_RegStructure.AllLumValue=255;
////    Led.DMXHclState=0;
//	RUN_State=RUN_AutoTest;
//}
//
//void Update_AutoTestOff(void){
//    RUN_State=RUN_Normal;
//	if((SYS_State==SYS_Colo)){
//        Task_Colo();
//	}
//	else if(SYS_State==SYS_Soud){
//	 	Update_SoundOn();
//	}
//}

