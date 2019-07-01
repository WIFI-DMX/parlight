#include "main.h"

#define DMXFadeStartValue  255
xdata uint8_t LedEffect1_State=1,LedEffect2_State=1,LedEffect2_StateMARK=1,LedEffect3_State=1,LedEffect4_State=1,LedEffect5_State=1,FadePwmValue=0;
xdata LED_TypeDef LED_RegStructure;
//xdata LED_Type Led;
 //WIFI-DMX.COM
#define Led_FadeValue(HclSpeed)	((((255-HclSpeed)*2880000)/255)+184000)

code uint16_t CHASE_LED[LED_Point_Num]={COLOR_0,COLOR_1,COLOR_2,COLOR_3};

#define Led_ChaseValue(ChaseSpeed)	(((255-ChaseSpeed)/20)*((255-ChaseSpeed)/20)+8)

/*
const uint8_t TabHoldColor[]=
{

     0,     0,     0,		0,	  //0
//    R      G      B		w
     255,     0,     0,		0,	  //1
       0,   255,     0,	    0,     //2
       0,     0,   255,    	0,	   //3
       0,     0,     0,   255,	   //4

     255,   255,     0,	    0,	   //5 Y
     255,     0,   255,     0,	   //6 P
     255,     0,     0,   255,	   //7
       0,   255,   255,     0,	   //8 C
       0,   255,     0,   255,	   //9
       0,     0,   255,   255,	   //10

     255,   255,   255,     0,	   //11
     255,   255,     0,   255,	   //12
	 255,     0,   255,   255,	   //13
	   0,   255,   255,   255,	   //14

     255,   255,   255,	  255,	   //15	ALL

 	255,   0,   0,	 0,  //  16 R
	255,   0,   0, 100,  //  17 
	255,   0,   0, 200,  //  18
	255,  50,   0,   0,  //  19
	255, 150,   0,   0,  //  20
	255, 255,   0,   0,  //  21
	255, 255,   0,  75,  //  22
	  0, 255,   0, 255,  //  23
	  0, 255,   0, 150,  //  24
	  0, 255,   0,  50,  //  25
	  0, 255,   0,   0,  //  26
	  0, 255,  50,   0,  //  27
	  0, 255, 150,   0,  //  28
	  0, 255, 255,   0,  //  29
	  0, 255, 255,  75,  //  30
	  0, 255, 255, 150,  //  31
	  0, 100, 255, 255,  //  32
	  0,   0, 255, 100,  //  33
	  0,   0, 255,  50,  //  34
	  0,   0, 255,   0,  //  35
	 75,   0, 255,   0,  //  36
	160,   0, 255,   0,  //  37
	255,   0, 255,   0,  //  38
	255,   0, 175,   0,  //  39
	255,   0, 100,   0,  //  40
	255,   0, 100,  50,  //  41
	255,   0,  25,  50,  //  42
	255,   0,  25,  25,  //  43
	255,   0,  25,   0,  //  44
	  0,   0,   0, 255,  //  45
	 75,  75,   0, 255,  //  46
	  0,   0, 100, 255,  //  47
	255, 255, 255, 255,  //  48
	255, 255, 255, 255,  //  48
	255, 255, 255, 255,  //  48
	255, 255, 255, 255,  //  48
};
*/
/*
void LedGetColor(__IO uint8_t Bytedata, __IO uint8_t *pSource)
{

    *pSource ++ = TabHoldColor[Bytedata * 4 + 0];
	*pSource ++ = TabHoldColor[Bytedata * 4 + 1];
	*pSource ++ = TabHoldColor[Bytedata * 4 + 2];
	*pSource    = TabHoldColor[Bytedata * 4 + 3]; 

}

const uint8_t TabHoldColor1[]=
{
     0,     0,     0,		0,	   //0
//    R      G      B		w
     255,     0,     0,		0,	   //1
     255,    62,     0,	    0,     //2
       2,   255,     0,    	0,	   //3
       2,   255,   255,     0,	   //4
       2,     0,   255,	    0,	   //5 Y
     255,     0,   130,     0,	   //6 P
       0,     0,     0,   255,	   //7
};
const uint8_t TabHoldColor2[]=
{
     0,     0,     0,		0,	   //0
//    R      G      B		w
     255,     0,     0,		0,	   //1
     255,     0,   255,	    0,     //2
       0,     0,     0,   255,	   //3
};
const uint8_t TabHoldColor3[]=
{
     0,     0,     0,		0,	   //0
//    R      G      B		w
       0,   255,     0,		0,	   //1
     255,     0,    50,	    0,     //2
};
const uint8_t TabHoldColor4[]=
{
     0,     0,     0,		0,	   //0
//    R      G      B		w
     255,     0,     0,		0,	   //1
       0,     0,     0,	  255,     //2
     255,     0,     0,    	0,	   //3
       0,     0,   255,     0,	   //4
};
const uint8_t TabHoldColor5[]=
{
     0,     0,     0,		0,	   //0
//    R      G      B		w
     255,     0,     0,		0,	   //1
	 255,     0,     0,		0,	   //2
	 255,     0,     0,		0,	   //3
	 255,     0,     0,		0,	   //4
	 255,     0,     0,		0,	   //5
	 255,     0,     0,		0,	   //6
	 255,     0,     0,		0,	   //7
	 255,     0,     0,		0,	   //8
	 255,     0,     0,		0,	   //9
	 255,     0,     0,		0,	   //10
     255,   255,   255,	  255,     //11
       0,     0,   255,    	0,	   //12
	   0,     0,   255,    	0,	   //13
	   0,     0,   255,    	0,	   //14
	   0,     0,   255,    	0,	   //15
	   0,     0,   255,    	0,	   //16
	   0,     0,   255,    	0,	   //17
	   0,     0,   255,    	0,	   //18
	   0,     0,   255,    	0,	   //19
	   0,     0,   255,    	0,	   //20
	   0,     0,   255,    	0,	   //21
    255,   255,   255,	  255,	   //22
};
const uint8_t TabHoldColor6[]=
{
     0,     0,     0,		0,	   //0
//    R      G      B		w
     255,     0,    50,		0,	   //1
	   0,     0,     0,	  255,	   //2
	   0,   255,     0,		0,	   //3
       2,     0,     0,	  255,     //4
};
const uint8_t TabHoldColor7[]=
{
     0,     0,     0,		0,	   //0
//    R      G      B		w
     255,   100,     0,		0,	   //1
	   0,   255,   255,	    0,	   //2
};
const uint8_t TabHoldColor8[]=
{
     0,     0,     0,		0,	   //0
//    R      G      B		w
       0,     0,   255,		0,	   //1
	   0,     0,     0,	  255,	   //2
};

*/
//void LedGetColor_(uint8_t *TabHoldColor,uint8_t Bytedata,uint8_t *pSource)
//{
///*R G B */
///*
//    *pSource ++ = TabHoldColor[Bytedata * 3 + 0];
//	*pSource ++ = TabHoldColor[Bytedata * 3 + 1];
//	*pSource    = TabHoldColor[Bytedata * 3 + 2];  */
//
///*R G B W */
//
//    *pSource ++ = TabHoldColor[Bytedata * 4 + 0];
//	*pSource ++ = TabHoldColor[Bytedata * 4 + 1];
//	*pSource ++ = TabHoldColor[Bytedata * 4 + 2];
//	*pSource    = TabHoldColor[Bytedata * 4 + 3]; 
//
///*R G B W Y*/
///*
//    *pSource ++ = TabHoldColor[Bytedata * 5 + 0];
//	*pSource ++ = TabHoldColor[Bytedata * 5 + 1];
//	*pSource ++ = TabHoldColor[Bytedata * 5 + 2];
//	*pSource ++ = TabHoldColor[Bytedata * 5 + 3];
//	*pSource    = TabHoldColor[Bytedata * 5 + 4];
//	*/
///*R G B W Y P*/
///*
//    *pSource ++ = TabHoldColor[Bytedata * 6 + 0];
//	*pSource ++ = TabHoldColor[Bytedata * 6 + 1];
//	*pSource ++ = TabHoldColor[Bytedata * 6 + 2];
//	*pSource ++ = TabHoldColor[Bytedata * 6 + 3];
//	*pSource ++ = TabHoldColor[Bytedata * 6 + 4];
//	*pSource    = TabHoldColor[Bytedata * 6 + 5];
//*/
//}

//void Led_Init(void){	  
//
//  LED_RegStructure.RedLumValue=0;
//  LED_RegStructure.GreenLumValue=0;
//  LED_RegStructure.BlueLumValue=0;
//  LED_RegStructure.WhiteLumValue=0;
//  LED_RegStructure.YellowLumValue=0;
//  LED_RegStructure.PurpleLumValue=0;
//
//  LED_RegStructure.AllLumValue=0;				  
//  
//  LED_RegStructure.StobValue=0;	
//  LED_RegStructure.HclValue=0;
//  LED_RegStructure.FadeValue=0;
//  LED_RegStructure.ChangValue=1; 
//}


/************************************************************************************/

void LedRedValueUpdate(uint8_t idata ByteData){
	DMX_RegStructure.DMXTransmitNow[D485_RED]=ByteData;
}

void LedGreenValueUpdate(uint8_t idata ByteData){
	DMX_RegStructure.DMXTransmitNow[D485_GREEN]=ByteData;
}

void LedBlueValueUpdate(uint8_t idata ByteData){
	DMX_RegStructure.DMXTransmitNow[D485_BLED]=ByteData;
}

void LedWhiteValueUpdate(uint8_t idata ByteData){
	DMX_RegStructure.DMXTransmitNow[D485_WHITE]=ByteData;
}

void LedYellowValueUpdate(uint8_t idata ByteData){
	DMX_RegStructure.DMXTransmitNow[D485_YELLOW]=ByteData;
}

void LedPurpleValueUpdate(uint8_t idata ByteData){
	DMX_RegStructure.DMXTransmitNow[D485_PURPLE]=ByteData;
}

void LedAllValueUpdate_0(void){    

	LedRedValueUpdate(0);
	LedGreenValueUpdate(0);
	LedBlueValueUpdate(0);	
	LedWhiteValueUpdate(0);
	LedYellowValueUpdate(0);
	LedPurpleValueUpdate(0);
}

uint8_t LedStobValueTask(uint8_t idata e){
//	if(!Led.LedStobState){
//		if(e)Led.LedStobState=1;
//	}
//	else{   
//		if(e)Led.LedStobState=0;	
//	}
//	if(Led.LedStobState)
//	return ((DMX_RegStructure.D485TransmitNow[D485_STROBE]+1)/10)*((DMX_RegStructure.D485TransmitNow[D485_STROBE]+1)/5);
//	else
	return 1;
}

void LedStobValueUpdate(uint8_t idata ByteData){
//	if(Memory_Struct.Memory_Stob>0){
//		LED_RegStructure.StobValue=(257-Memory_Struct.Memory_Stob)/4+2;
//	}
//	else{
//		LED_RegStructure.StobValue=0;
//		Led.LedStobState=0;
//		LED_RegStructure.AllLumValue=255;//zong
//		LedRedValueUpdate(LED_RegStructure.RedLumValue);
//		LedGreenValueUpdate(LED_RegStructure.GreenLumValue);
//	}
//	
//	DMX_RegStructure.D485TransmitNow[D485_STROBE]=LED_RegStructure.StobValue;
//	Led.StobValuebuf=0;
//	Led.LEDStobValueBuf=LedStobValueTask(0);
}


//void DMX_Move(uint8_t DIMMER,uint8_t STROBE)
//{
//	LED_RegStructure.AllLumValue = DMX_RegStructure.DMXReceiveNow[DIMMER];
//
//	if((DMX_RegStructure.DMXReceiveNow[STROBE]>10)){		  
//		LED_RegStructure.StobValue=(257-DMX_RegStructure.DMXReceiveNow[STROBE])/4+2;
//		if((DMX_RegStructure.DMXReceiveBuffer[STROBE]<=10)){
//			Led.LocalTime_Stob=1;
//			Led.LedStobState=0;												
//			Led.LTime_Stob=0;
//		}
//		DMX_RegStructure.D485TransmitNow[STROBE]=LED_RegStructure.StobValue*1;
//		Led.LEDStobValueBuf=LedStobValueTask(0);					
//	}
//	else{
//		DMX_RegStructure.D485TransmitNow[STROBE]=LED_RegStructure.StobValue=0;
//	}
//	DMX_RegStructure.DMXReceiveBuffer[STROBE]=DMX_RegStructure.DMXReceiveNow[STROBE];	
//
//}


//void DMX_Move(uint8_t DIMMER,uint8_t STROBE){
//	LED_RegStructure.AllLumValue = DMX_RegStructure.DMXReceiveNow[DIMMER];
//	if((DMX_RegStructure.DMXReceiveNow[STROBE]>10)){		  
//		if(DMX_RegStructure.DMXReceiveNow[STROBE]>128){
//			LED_RegStructure.StobValue=(257-DMX_RegStructure.DMXReceiveNow[STROBE])/2;
//			if((ABS(DMX_RegStructure.DMXReceiveBuffer[STROBE],DMX_RegStructure.DMXReceiveNow[STROBE])>30)
//			||(DMX_RegStructure.DMXReceiveBuffer[STROBE]<=128)){
//				Led.LocalTime_Stob=1;
//				Led.LedStobState=0;												
//				if(DMX_RegStructure.DMXReceiveBuffer[STROBE]<=128)Led.LTime_Stob=0;
//			}
//			DMX_RegStructure.D485TransmitNow[D485_STROBE]=LED_RegStructure.StobValue*2;
//			Led.LEDStobValueBuf=LedStobValueTask(0);
//		}
//		else{
//			LED_RegStructure.StobValue=129-DMX_RegStructure.DMXReceiveNow[STROBE]+2;		  
//		}					
//	}
//	else{
//		DMX_RegStructure.D485TransmitNow[D485_STROBE]=LED_RegStructure.StobValue=0;
//	}
//	DMX_RegStructure.DMXReceiveBuffer[STROBE]=DMX_RegStructure.DMXReceiveNow[STROBE];	
//}

void LedDMXDataCmd(void){	 
     LED_RegStructure.HclValue=0;
	 LED_RegStructure.FadeValue=0;

	 switch (Memory_Struct.Memory_Chan)
	 {
	  	case _1channel:				
		LED_RegStructure.AllLumValue = 255;
		LED_RegStructure.StobValue = 0;

		LedRedValueUpdate(DMX_RegStructure.DMXReceiveNow[DMX_RED_CH1]);
		LedGreenValueUpdate(DMX_RegStructure.DMXReceiveNow[DMX_GREEN_CH1]);
		LedBlueValueUpdate(DMX_RegStructure.DMXReceiveNow[DMX_BLUE_CH1]);
		LedWhiteValueUpdate(DMX_RegStructure.DMXReceiveNow[DMX_WHITE_CH1]);

		break;
		case _2channel:				
//		DMX_Move(DMX_DIMMER_CH2,DMX_STROBE_CH2);
//		DMX_LedFade(DMX_RegStructure.DMXReceiveNow,DMX_AUTO_CH2,DMX_SPEED_CH2);

		LED_RegStructure.AllLumValue = 255;
		LED_RegStructure.StobValue = 0;

		LedRedValueUpdate(DMX_RegStructure.DMXReceiveNow[DMX_RED_CH2]);
		LedGreenValueUpdate(DMX_RegStructure.DMXReceiveNow[DMX_GREEN_CH2]);
		LedBlueValueUpdate(DMX_RegStructure.DMXReceiveNow[DMX_BLUE_CH2]);
		LedWhiteValueUpdate(DMX_RegStructure.DMXReceiveNow[DMX_WHITE_CH2]);
		break;
	  	case _3channel:			
		break;
		default:break;
	 }	
}


