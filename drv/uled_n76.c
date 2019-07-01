#include "Main.h"
#define ABC(x,y) {if(x<y){x++;}else if(x>y){x--;}}
 //WIFI-DMX.COM
uint32_t xdata
	wLumValue[LED_TOTAL],
	wLumLastValue[LED_TOTAL];

p_position xdata curve[LED_TOTAL]={
{0,0,0,0,0,8,2,10,0},
{0,0,0,0,0,8,2,10,0},
{0,0,0,0,0,8,2,10,0},
{0,0,0,0,0,8,2,10,0},
{0,0,0,0,0,8,2,10,0},
{0,0,0,0,0,8,2,10,0},
};
#if 0 
void LedDrive(void)
{
	unsigned char 
		c;
	unsigned short w = 0;

	for (c = 0; c != LED_TOTAL; c++)
	{	
		if(DMX_RegStructure.DMXReceiveNow[D485_Dimmer]==20)
		wLumValue[c] = Led_PwmValueA[Led.cDriverValue[c]];
		else
		if(DMX_RegStructure.DMXReceiveNow[D485_Dimmer]==40)
		wLumValue[c] = Led_PwmValueB[Led.cDriverValue[c]];
		else
		if(DMX_RegStructure.DMXReceiveNow[D485_Dimmer]==60)
		wLumValue[c] = Led_PwmValueC[Led.cDriverValue[c]];
		else
		wLumValue[c] = Led_PwmValue[Led.cDriverValue[c]];
			if((Led.cDriverValue[c]==0)||(wLumLastValue[c]==0))
	        {
			   wLumLastValue[c] = wLumValue[c];
			}
			else if (wLumLastValue[c] != wLumValue[c])
			{
				if (wLumLastValue[c] > wLumValue[c])
				{
					w = wLumLastValue[c] - wLumValue[c];
					wLumLastValue[c] = wLumLastValue[c]  - LedGetSpaceSpeed(w, Led.wLedSpeed + c);
				}
				else 
				{
					w = wLumValue[c] - wLumLastValue[c];
					wLumLastValue[c] = wLumLastValue[c] + LedGetSpaceSpeed(w, Led.wLedSpeed + c);// Led.wLedSpeed + c对应颜色的速度
				}
			}
			
			if (wLumLastValue[c] == wLumValue[c])
			{
				Led.wLedSpeed[c] = 0;
			}
	  
	             
		    if((Temperature>50)||(Temp_error>240))
			{
			  //Fan_ON;
			  if(Temperature>70)
			  {
			  	if(TempValue<70000)TempValue++;
			  }	
			  else if(Temperature>60)
			  {
			  	if(TempValue<40000)TempValue++;
			  }	
			  else if(Temperature>55)
			  { 
				 if(TempValue<30000)TempValue++;
			  }
			  else
			  {
			  	 if(TempValue<20000)TempValue++;
			  }
				 wLumLastValueTemp[c]=wLumLastValue[c]*(100000-TempValue)/100000;
		    }
			else
			{
			   	   if(TempValue)TempValue--;
				   wLumLastValueTemp[c]=wLumLastValue[c]*(100000-TempValue)/100000;
				   
			}

		    LED_PWM[c] = wLumLastValueTemp[c];
	}
		  	
}

#endif

#if 1 
void LedDrive(void)
{
	uint8_t xdata c;	

	for (c = 0; c != LED_TOTAL; c++)
	{	
		   wLumLastValue[c] =LED_RegStructure.cDriverValue[c]*LED_RegStructure.AllLumValue*16/255;
	}
	if((LED_RegStructure.StobValue&&LED_RegStructure.LedStobState)||(RUN_State==RUN_Reset)){
		Pwm_Update(Drv_LED_R,0);
		Pwm_Update(Drv_LED_G,0);
		Pwm_Update(Drv_LED_B,0);
		Pwm_Update(Drv_LED_W,0);
		Pwm_Update(Drv_LED_Y,0);
		Pwm_Update(Drv_LED_B,0);
	}
	else{
		Pwm_Update(Drv_LED_R , wLumLastValue[0]*Memory_Struct.Memory_CalibrationsRed/Calibrations_N);
		Pwm_Update(Drv_LED_G , wLumLastValue[1]*Memory_Struct.Memory_CalibrationsGreen/Calibrations_N);
		Pwm_Update(Drv_LED_B , wLumLastValue[2]*Memory_Struct.Memory_CalibrationsBlue/Calibrations_N);
		Pwm_Update(Drv_LED_W , wLumLastValue[3]*Memory_Struct.Memory_CalibrationsWhite/Calibrations_N);
		Pwm_Update(Drv_LED_Y , wLumLastValue[4]*Memory_Struct.Memory_CalibrationsYellow/Calibrations_N);
		Pwm_Update(Drv_LED_P , wLumLastValue[6]*Memory_Struct.Memory_CalibrationsPurple/Calibrations_N);
	}
		  	
}
#endif

#if 0 
void LedDrive(void)
{
	unsigned char 
		c;
	const uint16_t *p=Led_PwmSquare;

	switch(DMX_RegStructure.DMXReceiveNow[D485_Dimmer])
	{
	case 20:p = Led_PwmLinear;
	break;
	case 40:p = Led_PwmScurve;
	break;
	case 60:p = Led_PwmInsquare;
	break;
	default:break;
	}	

	//for (c = 0; c != LED_TOTAL; c++)
	c = 0;
	//{	
		   wLumValue[c] = *(p+Led.cDriverValue[c]);

			if((Led.cDriverValue[c]==0)||(wLumLastValue[c]==0))
	        {
			   wLumLastValue[c] = (wLumValue[c]*250)>>8;
			}
			else if (wLumLastValue[c] != wLumValue[c])
			{
				if (wLumLastValue[c] > wLumValue[c])
				{
					(w_[c] = ((wLumLastValue[c] - wLumValue[c])*(256))/(*(p+Led.cDriverValue[c])+256));ABC(w[c],w_[c]);
					//w = ((wLumLastValue[c] - wLumValue[c])*512)/(*(p+255));
					LedGetSpeed (0,w[c],10000,1,&wLumLastValue[c]);
					if (wLumLastValue[c] <= wLumValue[c])wLumLastValue[c] = wLumValue[c];
				}
				else 
				{
					(w_[c] = ((wLumValue[c] - wLumLastValue[c])*(256))/(*(p+Led.cDriverValue[c])+256));ABC(w[c],w_[c]);
					//w = ((wLumValue[c] - wLumLastValue[c])*512)/(*(p+255));			
					LedGetSpeed (1,w[c],10000,1,&wLumLastValue[c]);
					if (wLumLastValue[c] >= wLumValue[c])wLumLastValue[c] = wLumValue[c];
				}
			}
			
			if (wLumLastValue[c] == wLumValue[c])
			{
				Led.wLedSpeed[c] = 0;
			}
	  
	             
		    if(((Temperature&0x7f)>59)||(Temp_error>240))
			{
			  FAN_ON;
			  if(((Temperature&0x7f)>75)||(Temp_error>240))
			  {
			  	 if(TempValue<70000)TempValue=TempValue+20;
			  }
			  else
			  {
			  	 if(TempValue<((Temperature&0x7f)-59)*4200)TempValue=TempValue+(1+(1*(((Temperature&0x7f)-59)*4200-TempValue))/10000);
			  }
				 wLumLastValueTemp[c]=wLumLastValue[c]*(100000-TempValue)/100000;
		    }
			else 
			{
			   	   if(TempValue)TempValue=TempValue-(1+(1*TempValue)/10000);
				   wLumLastValueTemp[c]=wLumLastValue[c]*(100000-TempValue)/100000;				   
			}

			if(DMX_RegStructure.DMXReceiveNow[D485_Reset]>168)
			{
			  if(wLumLastValueTemp[c])
			  LED1_R=LED1_G=LED1_B=LED1_W = wLumLastValueTemp[c]+20;
			  else 
			  LED1_R=LED1_G=LED1_B=LED1_W = wLumLastValueTemp[c];
			}
			else
			{
				LED1_R=LED1_G=LED1_B=LED1_W =0;
			}
	//}
		  	
}
#endif
