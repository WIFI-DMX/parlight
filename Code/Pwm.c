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
 //WIFI-DMX.COM
//***********************************************************************************************************
//  File Function: N76E003 PWM Output demo code
//***********************************************************************************************************
#include "main.h"

//*****************  The Following is in define in Fucntion_define.h  ***************************
//****** Always include Function_define.h call the define you want, detail see main(void) *******
//***********************************************************************************************
#if 0 
////--------- PMW clock source select define ---------------------
//#define		PWM_CLOCK_FSYS					CKCON&=0xBF
//#define		PWM_CLOCK_TIMER1				CKCON|=0x40
////--------- PWM clock devide define ----------------------------
//#define		PWM_CLOCK_DIV_2					PWMCON1|=0x01;PWMCON1&=0xF9
//#define		PWM_CLOCK_DIV_4					PWMCON1|=0x02;PWMCON1&=0xFA
//#define		PWM_CLOCK_DIV_8					PWMCON1|=0x03;PWMCON1&=0xFB
//#define		PWM_CLOCK_DIV_16				PWMCON1|=0x04;PWMCON1&=0xFC
//#define		PWM_CLOCK_DIV_32				PWMCON1|=0x05;PWMCON1&=0xFD
//#define		PWM_CLOCK_DIV_64				PWMCON1|=0x06;PWMCON1&=0xFE
//#define		PWM_CLOCK_DIV_128				PWMCON1|=0x07
////--------- PWM I/O select define ------------------------------
//#define		PWM5_P15_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x20;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.5 as PWM5 output enable
//#define		PWM5_P03_OUTPUT_ENABLE		PIOCON0|=0x20																										//P0.3 as PWM5
//#define		PWM4_P01_OUTPUT_ENABLE		PIOCON0|=0x10																										//P0.1 as PWM4 output enable
//#define		PWM3_P04_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x08;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P0.4 as PWM3 output enable
//#define		PWM3_P00_OUTPUT_ENABLE		PIOCON0|=0x08																										//P0.0 as PWM3 
//#define		PWM2_P05_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x04;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.0 as PWM2 output enable
//#define		PWM2_P10_OUTPUT_ENABLE		PIOCON0|=0x04																										//P1.0 as PWM2
//#define		PWM1_P14_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x02;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.4 as PWM1 output enable
//#define		PWM1_P11_OUTPUT_ENABLE		PIOCON0|=0x02																										//P1.1 as PWM1 
//#define		PWM0_P12_OUTPUT_ENABLE		PIOCON0|=0x01																										//P1.2 as PWM0 output enable
//#define 	ALL_PWM_OUTPUT_ENABLE			PIOCON0=0xFF;PIOCON1=0xFF
//#define		PWM5_P15_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xDF;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.5 as PWM5 output disable
//#define		PWM5_P03_OUTPUT_DISABLE		PIOCON0&=0xDF																										//P0.3 as PWM5
//#define		PWM4_P01_OUTPUT_DISABLE		PIOCON0&=0xEF																										//P0.1 as PWM4 output disable
//#define		PWM3_P04_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xF7;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P0.4 as PWM3 output disable
//#define		PWM3_P00_OUTPUT_DISABLE		PIOCON0&=0xF7																										//P0.0 as PWM3 
//#define		PWM2_P05_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xFB;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.0 as PWM2 output disable
//#define		PWM2_P10_OUTPUT_DISABLE		PIOCON0&=0xFB																										//P1.0 as PWM2
//#define		PWM1_P14_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xFD;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.4 as PWM1 output disable
//#define		PWM1_P11_OUTPUT_DISABLE		PIOCON0&=0xFD																										//P1.1 as PWM1 
//#define		PWM0_P12_OUTPUT_DISABLE		PIOCON0&=0xFE																										//P1.2 as PWM0 output disable
//#define 	ALL_PWM_OUTPUT_DISABLE		PIOCON0=0x00;PIOCON1=0x00
////--------- PWM I/O Polarity Control ---------------------------
//#define		PWM5_OUTPUT_INVERSE			PNP|=0x20				
//#define		PWM4_OUTPUT_INVERSE			PNP|=0x10				
//#define		PWM3_OUTPUT_INVERSE			PNP|=0x08				
//#define		PWM2_OUTPUT_INVERSE			PNP|=0x04				
//#define		PWM1_OUTPUT_INVERSE			PNP|=0x02				
//#define		PWM0_OUTPUT_INVERSE			PNP|=0x01				
//#define		PWM_OUTPUT_ALL_INVERSE	PNP=0xFF
//#define		PWM5_OUTPUT_NORMAL			PNP&=0xDF				
//#define		PWM4_OUTPUT_NORMAL			PNP&=0xEF				
//#define		PWM3_OUTPUT_NORMAL			PNP&=0xF7				
//#define		PWM2_OUTPUT_NORMAL			PNP&=0xFB				
//#define		PWM1_OUTPUT_NORMAL			PNP&=0xFD				
//#define		PWM0_OUTPUT_NORMAL			PNP&=0xFE				
//#define		PWM_OUTPUT_ALL_NORMAL		PNP=0x00
////--------- PWM type define ------------------------------------
//#define		PWM_EDGE_TYPE						PWMCON1&=~SET_BIT4
//#define		PWM_CENTER_TYPE					PWMCON1|=SET_BIT4
////--------- PWM mode define ------------------------------------
//#define		PWM_IMDEPENDENT_MODE		PWMCON1&=0x3F
//#define		PWM_COMPLEMENTARY_MODE	PWMCON1|=0x40;PWMCON1&=0x7F
//#define		PWM_SYNCHRONIZED_MODE		PWMCON1|=0x80;PWMCON1&=0xBF
//#define 	PWM_GP_MODE_ENABLE			PWMCON1|=0x20
//#define		PWM_GP_MODE_DISABLE			PWMCON1&=0xDF
////--------- PMW interrupt setting ------------------------------
//#define		PWM_FALLING_INT					PWMCON0&=0xF3
//#define		PWM_RISING_INT					PWMCON0|=0x04;PWMCON0&=0xF7
//#define		PWM_CENTRAL_POINT_INT		PWMCON0|=0x08;PWMCON0&=0xFB
//#define		PWM_PERIOD_END_INT			PWMCON0|=0x0C
////--------- PWM interrupt pin select ---------------------------
//#define		PWM_INT_PWM0						PWMCON0&=0xFC
//#define		PWM_INT_PWM2						PWMCON0|=0x01;PWMCON0&=0xFD
//#define		PWM_INT_PWM4						PWMCON0|=0x02;PWMCON0&=0xFE
//#define		PWM_INT_PMW6						PWMCON0|=0x03
////--------- PWM Dead time setting ------------------------------
//#define 	PWM45_DEADTIME_ENABLE			BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x04;EA=BIT_TMP
//#define 	PWM34_DEADTIME_ENABLE			BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x02;EA=BIT_TMP
//#define 	PWM01_DEADTIME_ENABLE			BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x01;EA=BIT_TMP
#endif

void Pwm_Update(uint8_t state,uint16_t pwm){
//	clr_LOAD;
	switch(state){
		case 0:
		PWM0H = (pwm>>8)&0xff;					
	    PWM0L = (pwm>>0)&0xff;
		break;
		case 1:
		PWM1H = (pwm>>8)&0xff;					
	    PWM1L = (pwm>>0)&0xff;
		break;
		case 2:
		PWM2H = (pwm>>8)&0xff;					
	    PWM2L = (pwm>>0)&0xff;
		break;
		case 3:
		PWM3H = (pwm>>8)&0xff;					
	    PWM3L = (pwm>>0)&0xff;
		break;
		case 4:
		set_SFRPAGE;
		PWM4H = (pwm>>8)&0xff;					
	    PWM4L = (pwm>>0)&0xff;
		clr_SFRPAGE;
		break;
		case 5:
		set_SFRPAGE;
		PWM5H = (pwm>>8)&0xff;					
	    PWM5L = (pwm>>0)&0xff;
		clr_SFRPAGE;
		break;
		default:break;
	}
	set_LOAD;	
}

void Pwm_Init(void)
{	
	PWM0_P12_OUTPUT_ENABLE;
	PWM1_P11_OUTPUT_ENABLE;
	PWM2_P10_OUTPUT_ENABLE;
	PWM3_P00_OUTPUT_ENABLE;
	PWM4_P01_OUTPUT_ENABLE;
	PWM5_P03_OUTPUT_ENABLE;

	PWM_IMDEPENDENT_MODE;

	//PWM_CLOCK_DIV_8;
	PWMPH = (PWM_MAX>>8)&0xff;
	PWMPL = (PWM_MAX>>0)&0xff;

	/**********************************************************************
	PWM frequency = Fpwm/((PWMPH,PWMPL) + 1) <Fpwm = Fsys/PWM_CLOCK_DIV> 
					= (16MHz/8)/(0x7CF + 1)
					= 1KHz (1ms)
	***********************************************************************/
	/**********************************************************************
	Special care about the PWM4H/PWM4L PWM5H/PWM5L register 
	in SFR page1
	***********************************************************************/
		
	Pwm_Update(0,PWM_INIT);
	Pwm_Update(1,PWM_INIT);
	Pwm_Update(2,PWM_INIT);
	Pwm_Update(3,PWM_INIT);
	Pwm_Update(4,PWM_INIT);
	Pwm_Update(5,PWM_INIT);											
	// PWM output inversly enable 
	//PWM2_OUTPUT_INVERSE;
	
	//-------- PWM start run--------------	
	set_PWMRUN;

	P12_PushPull_Mode;
	P11_PushPull_Mode;
	P10_PushPull_Mode;
	P00_PushPull_Mode;
	P01_PushPull_Mode;
	P03_PushPull_Mode;
}

