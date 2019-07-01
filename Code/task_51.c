#include "main.h"
#define MAXTASKS 10
xdata TASK Task_st[MAXTASKS];
void Task_Null(void) {;}
uint8_t xdata SysTick_i=0;
 //WIFI-DMX.COM
extern uint32_t idata LocalTime;
//uint16_t Minute_Time=0,Long_Time=0,BackLight_Time=0,UnLockBuf=0;

void Task_Clear(void)
{
//	uint8_t i=0;
//	for(i=D485_START;i<DMX512BUFSIZE;i++)
//	{
//		DMX_RegStructure.D485TransmitNow[i]=0;
//		DMX_RegStructure.DMXReceiveBuffer[i]=0;
//	}
//	DMX_RegStructure.D485TransmitNow[D485_XY_Speed]=0;
//	PanValueUpdate(0);
//	TiltValueUpdate(0);
//	DMX_RegStructure.D485TransmitNow[D485_X_CFine]=Memory_Struct.Memory_CalibrationsPan;
//	DMX_RegStructure.D485TransmitNow[D485_Y_CFine]=Memory_Struct.Memory_CalibrationsTilt;
//	LED_RegStructure.StobValue=0;
//	LED_RegStructure.FadeValue=0;
//	LED_RegStructure.HclValue=0;
//	LED_RegStructure.ChaseValue=0;
//	Led.DMXHclState=0;

}
void Task_Colo(void)
{
    Memory_Struct.Memory_Stob=Memory_Stob;
	LED_RegStructure.PurpleLumValue=PurpleLumValue;
	LED_RegStructure.YellowLumValue=YellowLumValue;
	LED_RegStructure.WhiteLumValue=WhiteLumValue;
	LED_RegStructure.BlueLumValue=BlueLumValue;
	LED_RegStructure.GreenLumValue=GreenLumValue;
	LED_RegStructure.RedLumValue=RedLumValue;
	LED_RegStructure.AllLumValue=255;
	LedRedValueUpdate(LED_RegStructure.RedLumValue);
	LedGreenValueUpdate(LED_RegStructure.GreenLumValue);
	LedBlueValueUpdate(LED_RegStructure.BlueLumValue);
	LedWhiteValueUpdate(LED_RegStructure.WhiteLumValue);
	LedYellowValueUpdate(LED_RegStructure.YellowLumValue);
	LedPurpleValueUpdate(LED_RegStructure.PurpleLumValue);
	LedStobValueUpdate(Memory_Struct.Memory_Stob);

//	LED_RegStructure.TiltValue=TiltValue;
//	LED_RegStructure.PanValue=PanValue;

//	LED_RegStructure.ZoomValue=ZoomValue;
//	LED_RegStructure.RotaValue=RotaValue;
//	LED_RegStructure.RedALumValue=RedALumValue;
//	LED_RegStructure.GreenALumValue=GreenALumValue;
//	LED_RegStructure.BlueALumValue=BlueALumValue;
//	
//	DMX_RegStructure.D485TransmitNow[D485_XY_Speed]=0;
//	PanValueUpdate(LED_RegStructure.PanValue);
//	TiltValueUpdate(LED_RegStructure.TiltValue);
//	ZoomValueUpdate(LED_RegStructure.ZoomValue);

//	LedRedValueUpdate_1(LED_RegStructure.RedALumValue);
//	LedGreenValueUpdate_1(LED_RegStructure.GreenALumValue);
//	LedBlueValueUpdate_1(LED_RegStructure.BlueALumValue);

//	DMX_RegStructure.D485TransmitNow[D485_X_CFine]=Memory_Struct.Memory_CalibrationsPan;
//	DMX_RegStructure.D485TransmitNow[D485_Y_CFine]=Memory_Struct.Memory_CalibrationsTilt;
}

void Task_TempUpdate(void)
{
//static uint8_t i=0;
//	if(i){
//		i=0;TM1618_Update(&SEGMenu_Buf,LED_0,LED_1,LED_2,LED_3,LED_PN);
//	}
//	else{
//		i=1;TM1618_Update(&SEGMenu_Buf,LED_off,LED_off,LED_off,LED_off,LED_PN);
//	}
//	uint8_t i=0,data3=3,data4=2;
//	static uint8_t state=0,Temp=0;
//	if(ABS(TemperatureBuf[0],TemperatureBuf[1]<8)&&ABS(TemperatureBuf[2],TemperatureBuf[1]<8)){
//		//Temperature=TemperatureBuf[1];
//	}
//	if((Temperature>120)&&(RUN_State==RUN_Normal)){
//		if(Temp++>4)Temp_Reset=1;
//	}
//	else{
//		Temp=0;Temp_Reset=0;
//	}
//
//	if((TempDispMark)&&(LCDDisplight)&&(RUN_State==RUN_Normal))
//	{	
//		if((state)&&((DeviceInfoStruct.ResetStatus1!=S1Status_Succeed)||(Temp_Reset))){  
//			state=0;  
//			LCM_Clr();	
//			if((DeviceInfoStruct.ResetStatus1)==S2ResetStatus_Color1)
//				LCM_Prints(0,2,"Color:Error");
//			else if((DeviceInfoStruct.ResetStatus2)==S2ResetStatus_Gobo)
//				LCM_Prints(0,2,"Water1:Error");
//			else if((DeviceInfoStruct.ResetStatus2)==S2ResetStatus_Zoom)
//				LCM_Prints(0,2,"Zoom:Error");
//			else if((DeviceInfoStruct.ResetStatus2)==S2ResetStatus_Color2)
//				LCM_Prints(0,2,"Water2:Error");
//			if(Temp_Reset)
//			LCM_Prints(0,3,"Temp:Error");
//			
////			data2 = (uint8_t)((ADC_ConvertedValue[0]) % 1000 / 100);
////			data3 = (uint8_t)((ADC_ConvertedValue[0]) % 100 / 10);
////			data4 = (uint8_t)((ADC_ConvertedValue[0]) % 10);
////			LCM_PrintsTemp(11,2,&Number_Char[data2]);
////			LCM_PrintsTemp(12,2,&Number_Char[data3]);
////			LCM_PrintsTemp(13,2,&Number_Char[data4]);
//		}
//		else{	   
//			if(state==0){SystemShow();if(Minute_Time>=200)LCM_Prints(0,3," Locked... ");} 
//			state=1;
//		}
//		data3 = (uint8_t)((Temperature&0x7f) % 100 / 10);
//		data4 = (uint8_t)((Temperature&0x7f) % 10);
//		LCM_PrintsTemp(12,3,&Number_Char[data3]);
//		LCM_PrintsTemp(13,3,&Number_Char[data4]);	
//		
//		for(i=7;i<8;i++){ 
//			LCM_PrintChinese(2*i,3,HZ_temp);
//		}
//	}
	Task_st[TTempUpdate].uiTimeCount=100;//1S
}

void Task_LedStob(void){
      Task_st[TLedStob].uiTimeCount=1550;
}

void Task_LedHcl(void){
//	if((SYS_State==SYS_Auto)&&(RUN_State==RUN_Normal)){ 
//		LED_RegStructure.StobValue=0;
//		LED_RegStructure.FadeValue=0;
//		LED_RegStructure.HclValue=0;
//		LED_RegStructure.ChaseValue=0;
//		DMX_RegStructure.D485TransmitNow[D485_STROBE]=0;
//		LedTab_ShowMarcoXY(Task_XY_State,Memory_Struct.Memory_Hcl,1);
//		Task_Sys_i++;
//		
//		if(Task_Sys_i%20==0){
//			Task_XY_State=(Task_XY_State<15)?Task_XY_State+1:0;
//		}	
//		if(Task_Sys_i%(10*Memory_Struct.Memory_Hcl)==0){
//			Task_COLOR_State=(Task_COLOR_State<15)?Task_COLOR_State+1:0;
//		}
//		LedMic(Task_COLOR_State);
//							
//		if(Task_Sys_i>=800){
//			Task_Sys_i=0;
//		}
//	}
   Task_st[TLedHcl].uiTimeCount=24;
}

void Led_Stob(void)
{
//	if(Led.LTime_Stob++>=4)
//	{ 
//		Led.LTime_Stob=0;
//		Led.LocalTime_Stob++;
//		if((LED_RegStructure.StobValue)&&(RUN_State==RUN_Normal)&&(SYS_State!=SYS_Slave))
//		{
//			if((Led.LocalTime_Stob>=Led.LEDStobValueBuf))
//			{
//				Led.LocalTime_Stob=0;
//				Led.LEDStobValueBuf=LedStobValueTask(1);
//			}
//		}
//	}
//	Task_Sys();
}

void Task_LedFade(void)
{
uint8_t xdata i=0;
	LED_RegStructure.SumValue=0;
	for(i=0;i<LED_TOTAL;i++){
		LED_RegStructure.cDriverValue[i] = DMX_RegStructure.DMXTransmitNow[D485_RED+i];
		LED_RegStructure.SumValue+=LED_RegStructure.cDriverValue[i];	
	}
	LedDrive();
//static uint8_t i=0;	
//	ADC_GET();
//	if(i++>60){
//		i=0;
//		if(Temperature<40)FAN_OFF;
//		else if((Temp_error>240)||(Temperature>50)){
//			FAN_ON;
//		}
//	}
	Task_st[TLedFade].uiTimeCount=12; 
}

//void SysTick_Handler(void){LocalTime +=1;}

void Task_LedDMXFade(void) 
{   
//	if(((MotoResetTime++>80)&&(RUN_State==RUN_Reset))||(RUN_State==RUN_Normal)){
		RUN_State=RUN_Normal;
//		DMX_RegStructure.D485TransmitNow[D485_Reset]=200;
//		
//		MotoResetTime=0;
//		DMX512_DataInit();
//		SYS_MenuInit();
//		if((SYS_State==SYS_Colo)&&(COLO_SIGNAL_MARK)){
//			Task_Colo();
//		}		
		Task_Cmd(&Task_st[TLedDMXFade],&Task_LedDMXFade,TaskDisable,Task_Null);
//		SystemNum=BackSystemTime+1;
//		Reset_Time=0;
//	}

   Task_st[TLedDMXFade].uiTimeCount=1000; 
}

void SysChang_State(void){
//	if(Reset_Time)Reset_Time++;if(DMX_Reg.DMX_Chang_Mark)DMX_Reg.DMX_Chang_Mark--;
//	
//	if(DMX_RegStructure.DMX_SIGNAL_MARK>800){
//		if(SYS_StateBuf==SYS_Dmx){BackLightNum=1;LCM_LIGHT_ON;}else {LED_DMX=0;}    
//		
//		if(MainNormal()){
//			if(DMX_RegStructure.DMX_SIGNAL_MARK<2000){SystemNum=BackSystemTime+1;DMX_RegStructure.DMX_SIGNAL_MARK=2000;}
//			if((SYS_StateBuf==SYS_Dmx)&&(SYS_State!=SYS_Slave)){
//				switch(Memory_Struct.Memory_NoDMXStatus){
//					case 0:Task_Clear();SYS_State=SYS_Dmx;
//					break;
//					case 1:
//					break;
//					case 2:
//					if(SYS_State!=SYS_Auto){ 
//						Task_Clear();
//						SystemNum=BackSystemTime+1;
//						SYS_State=SYS_Auto;
//					}
//					break;
//					case 3:SYS_State=SYS_Soud;
//					break;
//					default:break;
//				}
//			}
//			else if(SYS_State!=SYS_StateBuf){
//				Task_Clear();
//				SystemNum=BackSystemTime+1;
//				SYS_State=SYS_StateBuf;
//			}
//			else if(SYS_State==SYS_Slave)Task_Clear();
//			
//		}
//	}
//	if((SYS_State==SYS_Colo))Task_Colo();
}

void Task_LedFading(void){
//static uint8_t i=0; 
//   if(((SYS_State==SYS_Dmx)||(SYS_State==SYS_Slave))&&(RUN_State==RUN_Normal)&&(rdm.identify_state)&&(DMX_RegStructure.DMX_SIGNAL_MARK>300))
//   {
//   	  if(i){
//	  	i=0;PanValueUpdate(0);TiltValueUpdate(0);
//	  }
//	  else{
//	  	i=1;PanValueUpdate(255);TiltValueUpdate(255);
//	  }
//   }
//   else
//   {
//   	  rdm.identify_state=0;
//      if(RUN_State==RUN_Normal)SysChang_State();
//   }
//	//LED_DMX=~LED_DMX;
//	WdtClear();	
	Task_st[TLedFading].uiTimeCount=1000; 
}

void Task_Menu(void){
	if(RUN_State!=RUN_Reset){MenuChange();}
	TM1618_Display();
	Task_st[TMenu].uiTimeCount=18;	
//	if((RUN_State==RUN_Normal)&&(DMX_RegStructure.DMX_SIGNAL_MARK<1000))DMX_RegStructure.DMX_SIGNAL_MARK+=3;	
}

//void Task_DMXReset(uint8_t Reset_)
//{
//	if((DMX_RegStructure.DMXReceiveNow[Reset_]>9)&&(DMX_RegStructure.DMXReceiveNow[Reset_]<21)){
//		if(Reset_Time==0)Reset_Time=1;
//		if(Reset_Time>6){  
//			Reset_Time=0;
//			MotoResetTime=0;
//			RUN_State=RUN_Reset;
//			Update_ResetYes();
//		}
//	}
//	else{
//		Reset_Time=0;
//	}
//}

void Task_DMXUpdate(void){
static uint8_t xdata j=0;
	DMX_RegStructure.DMX_SIGNAL_MARK=0;

	if((SYS_State==SYS_Dmx)&&(RUN_State==RUN_Normal)){
		LedDMXDataCmd();
	}
	else if((RUN_State==RUN_Normal)&&(MainNormal())){
	   if(DMX_Reg.DMX_Chang_Mark++>20){
	   	 DMX_Reg.DMX_Chang_Mark=0;
		 SysBuf=SYS_State;
		 SYS_State=SYS_Dmx;
		 LED_RegStructure.HclValue=0;
		 LED_RegStructure.StobValue=0;
	   }
	}
	
//     switch (Memory_Struct.Memory_Chan)
//	 {
//		 case _1channel:
//		 break;
//		 case _2channel:
//		 case _3channel:
//		 Task_DMXReset(DMX_FUNCTION_CH2);
//		 break;
//	 }

	if(j++==10){
		pSEG->Point|=LED_P4;
	}
	else if(j++>=20){
		j=0;
		pSEG->Point&=~LED_P4;
	}	
 	
	Task_Cmd(&Task_st[TDMXUpdate],&Task_DMXUpdate,TaskDisable,Task_Null);
}

void Task_MotoY(void){
//	uint32_t buff=0;
//	static uint32_t state=0;
//	static uint32_t i=1000,j=0,k=0,State_Buf=0; 
//	if((SYS_State==SYS_Soud)&&(RUN_State==RUN_Normal)){	
//		
//		AdcFilter();
//		if(buff!=ADC_ConvertedValueLocal[0]){  
//			buff=ADC_ConvertedValueLocal[0];  
//		}
//		
//		LED_RegStructure.StobValue=0;
//		LED_RegStructure.FadeValue=0;
//		LED_RegStructure.HclValue=0;
//		LED_RegStructure.ChaseValue=0;
//		DMX_RegStructure.D485TransmitNow[D485_STROBE]=0;
//		
//		//if((buff+0>=(100+(150*(255-Memory_Struct.Memory_Sose)/255)))&&(Memory_Struct.Memory_Sose)){
//        if((buff+0>=(20+(200*(255-Memory_Struct.Memory_Sose)/255)))&&(Memory_Struct.Memory_Sose)){
//		if(j>=150){LED_SOUND_ON;}
//		j=0;	 
//		}	 
//		if((j<150)&&(RUN_State==RUN_Normal)&&(SYS_State==SYS_Soud)){
//			j++;
//			
//			if((i%200==0)||(j==0)){	  
//				if(state==0){
//					Task_XY_State=(Task_XY_State<15)?Task_XY_State+1:0;
//					state=400;
//				}
//			}	
//			if(i%100==0){	  
//					Task_COLOR_State=(Task_COLOR_State<15)?Task_COLOR_State+1:0;
//			}
//			DMX_RegStructure.D485TransmitNow[D485_XY_Speed]=0;		
//		}
//		else if((RUN_State==RUN_Normal)&&(SYS_State==SYS_Soud)&&(i%1000==0)){
//			j=2000;
//			if(i%500==0){
//				Task_COLOR_State=1;
//				Task_XY_State=(Task_XY_State<15)?Task_XY_State+1:0;
//			}
//			DMX_RegStructure.D485TransmitNow[D485_XY_Speed]=255;
//		}
//		
//		LedTab_ShowMarcoXY(Task_XY_State,1,0);
//		DMX_RegStructure.D485TransmitNow[D485_XX]=0;
//		DMX_RegStructure.D485TransmitNow[D485_YY]=0;
//		LedMic(Task_COLOR_State);
//			
//		if(State_Buf!=Task_COLOR_State){
//		
//			State_Buf=Task_COLOR_State;
//			//(*(fp+(i/40)))(1);
//		}		  				
//		
//		if(i++>800){i=0;}	
//
//	k++;
//	if((30==k)&&(RUN_State==RUN_Normal)&&(DMX_RegStructure.DMX_SIGNAL_MARK>=300))
//	{
//
//	}
//	else if((60<=k)&&(RUN_State==RUN_Normal))
//	{
//		LED_SOUND_OFF;
//		k=0;
//	}
//  	  
//	if(state)state--;
//	Task_st[TMotoY].uiTimeCount=22*((25+100-Memory_Struct.Memory_Sose)/100);
//  }
}

void Task_MotoZ(void)
{
//	uint8_t i=0,D485TransmitNowBuf=0;
//	static uint8_t j=0;
//	if(DMX_RegStructure.DMX_SIGNAL_MARK>800){SystemNum=BackSystemTime+1;}
//	DMX_RegStructure.DMX_SIGNAL_MARK=0;
//	if((SYS_State==SYS_Slave)&&(RUN_State==RUN_Normal)){	    
//		D485TransmitNowBuf=DMX_RegStructure.D485TransmitNow[D485_Reset];
//		for(i=0;i<5;i++){
//			DMX_RegStructure.D485TransmitNow[i]=DMX_RegStructure.D485ReceiveNow[i];
//		}
//		DMX_RegStructure.D485TransmitNow[D485_XY_Speed]=DMX_RegStructure.D485ReceiveNow[D485_XY_Speed];
//		for(i=D485_START;i<D485_MASTER;i++){
//			DMX_RegStructure.D485TransmitNow[i]=DMX_RegStructure.D485ReceiveNow[i];
//		}
//		DMX_RegStructure.D485TransmitNow[D485_Reset]=D485TransmitNowBuf;
//		
//		if(((!Memory_Struct.Memory_PanInverse)&&(Memory_Struct.Memory_Mode == _SlaveMode2))||((Memory_Struct.Memory_PanInverse)&&(Memory_Struct.Memory_Mode == _SlaveMode1)))
//		{		
//			DMX_RegStructure.D485TransmitNow[D485_X]=255-DMX_RegStructure.D485ReceiveNow[D485_X];
//		}
//		
//		if(((!Memory_Struct.Memory_TiltInverse)&&(Memory_Struct.Memory_Mode == _SlaveMode2))||((Memory_Struct.Memory_TiltInverse)&&(Memory_Struct.Memory_Mode == _SlaveMode1)))
//		{
//			DMX_RegStructure.D485TransmitNow[D485_Y]=255-DMX_RegStructure.D485ReceiveNow[D485_Y];
//		}
//		Led.LedStobState = DMX_RegStructure.D485ReceiveNow[D485_StobState];;
//		LED_RegStructure.StobValue = DMX_RegStructure.D485ReceiveNow[D485_StobValue];
//		LED_RegStructure.FadeValue=0;
//		LED_RegStructure.HclValue=0;
//		LED_RegStructure.ChaseValue=0;
//	}  
//	else if((RUN_State==RUN_Normal)&&(MainNormal())){	
//		if(DMX_Reg.DMX_Chang_Mark++>20){
//			DMX_Reg.DMX_Chang_Mark=0;
//			SysBuf=SYS_State;
//			SYS_State=SYS_Slave;
//			SystemNum=BackSystemTime+1;
//		}
//	}
//
//	j++;
//	if((j==20)&&(RUN_State==RUN_Normal)){
//		//LED_SLAVE_ON;if(SYS_StateBuf==SYS_Dmx)LED_DMX_ON;
//	}
//	else if((j>=40)&&(RUN_State==RUN_Normal)){
//		j=0;
//		//LED_SLAVE_OFF;
//	}

	 Task_Cmd(&Task_st[TMotoZ],&Task_MotoZ,TaskDisable,Task_Null); 
}


void Task_Run(TASK*p,void (*fpNull)(),volatile unsigned char *uiPriority) {
   unsigned char i;  
	for(i=0;i<MAXTASKS;i++){   
		if(*uiPriority){i=*uiPriority;*uiPriority=0;}
		if((p+i)->fpTask!=fpNull){    
			if(LocalTime-(p+i)->uiTimeBuf>=(p+i)->uiTimeCount){ 
				(p+i)->uiTimeBuf=LocalTime;(*(p+i)->fpTask)();
			}  
		}	 
	}
	SysTick_i=SysTick_i+1;
}

void Tasks_Init(TASK *pTasks,void (*fpTask)(),volatile unsigned int uiTimeCount,volatile unsigned int uiTimeBuf) {
	pTasks->fpTask=fpTask;
	pTasks->uiTimeCount=uiTimeCount;	
	pTasks->uiTimeBuf=uiTimeBuf;
}

void Task_Cmd(TASK *pTasks,void (*fpTask)(),TASK_CmdTypeDef bTaskCmd,void (*fpNull)()){
  if(bTaskCmd != TaskDisable){
    pTasks->fpTask=fpTask;
  }
  else{
    pTasks->fpTask=fpNull;
  }
}

void Task_Init(void) 
{
	 Tasks_Init(&Task_st[TTempUpdate],&Task_TempUpdate,72,0);
	 Tasks_Init(&Task_st[TLedStob],&Task_LedStob,0,0);
	 Tasks_Init(&Task_st[TLedHcl],&Task_LedHcl,0,0);
	 Tasks_Init(&Task_st[TLedFade],&Task_LedFade,0,0);
	 Tasks_Init(&Task_st[TLedFading],&Task_LedFading,0,0);
	 Tasks_Init(&Task_st[TLedDMXFade],&Task_LedDMXFade,35,0);

	 Tasks_Init(&Task_st[TMenu],&Task_Menu,155,0);
	 Tasks_Init(&Task_st[TDMXUpdate],&Task_DMXUpdate,0,0);
	 Tasks_Init(&Task_st[TMotoY],&Task_Menu,15,0);
	 Tasks_Init(&Task_st[TMotoZ],&Task_DMXUpdate,15,0);

	 Task_Cmd(&Task_st[TTempUpdate],&Task_TempUpdate,TaskEnable,Task_Null);
	 Task_Cmd(&Task_st[TLedStob],&Task_LedStob,TaskEnable,Task_Null);
	 Task_Cmd(&Task_st[TLedHcl],&Task_LedHcl,TaskEnable,Task_Null);
	 Task_Cmd(&Task_st[TLedFade],&Task_LedFade,TaskEnable,Task_Null);

	 Task_Cmd(&Task_st[TLedFading],&Task_LedFading,TaskEnable,Task_Null);
	 Task_Cmd(&Task_st[TLedDMXFade],&Task_LedDMXFade,TaskEnable,Task_Null);
 
	 Task_Cmd(&Task_st[TDMXUpdate],&Task_DMXUpdate,TaskDisable,Task_Null);

	 Task_Cmd(&Task_st[TMotoY],&Task_MotoY,TaskEnable,Task_Null);
	 Task_Cmd(&Task_st[TMotoZ],&Task_MotoZ,TaskDisable,Task_Null); 
	 Task_Cmd(&Task_st[TMenu],&Task_Menu,TaskEnable,Task_Null);

}

void ADC_Con(uint8_t *p ,uint16_t *StobValuebuf,uint16_t StobValue)
{
//	*p=StobValue/((10-(SysTick->VAL*SysTick_i)&0x7))+(4-(SysTick->VAL*SysTick_i)&0x3)+2;
//	*StobValuebuf=*p/4+1;
}

void Task_Sys(void)
{
//	if((SYS_State==SYS_Dmx)&&(RUN_State==RUN_Normal))
//	{
//		if((++Led.StobValuebuf_j>Led.StobValuebuf*2)&&(LED_RegStructure.StobValue))
//		{
//			Led.StobValuebuf_j=1;
//			if(Memory_Struct.Memory_Chan==_1channel) 
//			{ 	
//				if(DMX_RegStructure.DMXReceiveBuffer[DMX_STROBE_CH1]<129){
//					ADC_Con(&DMX_RegStructure.D485TransmitNow[D485_STROBE] ,&Led.StobValuebuf,LED_RegStructure.StobValue);
//				}
//				else{
//					DMX_RegStructure.D485TransmitNow[D485_STROBE]=LED_RegStructure.StobValue;Led.StobValuebuf=0;
//				}
//			}
//			else if(Memory_Struct.Memory_Chan==_2channel)
//			{
//				if(DMX_RegStructure.DMXReceiveBuffer[DMX_STROBE_CH2]<129){
//					ADC_Con(&DMX_RegStructure.D485TransmitNow[D485_STROBE] ,&Led.StobValuebuf,LED_RegStructure.StobValue);
//				}
//				else{
//					DMX_RegStructure.D485TransmitNow[D485_STROBE]=LED_RegStructure.StobValue;Led.StobValuebuf=0;
//				}
//			}
//		}
//	}
//	else if((++Led.StobValuebuf_j>Led.StobValuebuf*2)&&(LED_RegStructure.StobValue)&&(SYS_State==SYS_Colo)&&(RUN_State==RUN_Normal))
//	{
//		Led.StobValuebuf_j=1;
//		LED_RegStructure.FadeValue=0;
//		LED_RegStructure.HclValue=0;
//		LED_RegStructure.ChaseValue=0;
//		if(Memory_Struct.Memory_Stob<129){
//			ADC_Con(&DMX_RegStructure.D485TransmitNow[D485_STROBE] ,&Led.StobValuebuf,LED_RegStructure.StobValue);
//		}
//		else{
//			DMX_RegStructure.D485TransmitNow[D485_STROBE]=LED_RegStructure.StobValue;Led.StobValuebuf=0;
//		}
//	}					   
//
//	D485_DMXSendPacket();
//	
//	if((SYS_State!=SYS_Slave)&&(SYS_State!=SYS_Dmx)&&(RUN_State==RUN_Normal))DMX512_DMXSendData();
//	else if(RUN_State==RUN_AutoTest) DMX512_DMXSendData();

}































