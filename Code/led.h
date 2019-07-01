#ifndef _LED_H
#define	_LED_H
#include "Common.h"
 //WIFI-DMX.COM
#define LED_TOTAL (6)

#define COLOR_0                 ((uint16_t)0x0001)  
#define COLOR_1                 ((uint16_t)0x0002)  
#define COLOR_2                 ((uint16_t)0x0004)  
#define COLOR_3                 ((uint16_t)0x0008)  
#define COLOR_4                 ((uint16_t)0x0010)  
#define COLOR_5                 ((uint16_t)0x0020)  
#define COLOR_6                 ((uint16_t)0x0040) 
#define COLOR_7                 ((uint16_t)0x0080) 
#define COLOR_8                 ((uint16_t)0x0100)  
#define COLOR_9                 ((uint16_t)0x0200)  
#define COLOR_10                ((uint16_t)0x0400)  
#define COLOR_11                ((uint16_t)0x0800)  
#define COLOR_12                ((uint16_t)0x1000)  
#define COLOR_13                ((uint16_t)0x2000)  
#define COLOR_14                ((uint16_t)0x4000) 
#define COLOR_15                ((uint16_t)0x8000)  
#define LED_All                 ((uint16_t)0xFFFF)  

typedef struct 
{
uint8_t
	ChaseValue,
	LedStobState,
	HclValue,
	FadeValue,
	ChangValue,	
	NowHclColorValue[4],
	cDriverValue[LED_TOTAL];	
uint16_t	
	StobValue,				  
	RedLumValue,
	GreenLumValue,
	BlueLumValue,
	WhiteLumValue,
	YellowLumValue,
	PurpleLumValue;
uint16_t
	SumValue,
	AllLumValue;								
}LED_TypeDef;
extern xdata LED_TypeDef LED_RegStructure;

//typedef struct{
//	unsigned char  DMXHclState;
//	unsigned char  LedStobState;
//	unsigned char  LedFadeState;
//	unsigned char  FadePwmValue_8;
//	unsigned int   FadePwmValue_16;
//	unsigned int   ChaseState;
//	unsigned int   LEDStobValueBuf;
//	unsigned int   LEDFadeValueBuf;
//	unsigned int   HclValuebuf;
//	unsigned int   HclValuebuf_j;
//	unsigned int   ChaseValuebuf;
//	unsigned int   ChaseValuebuf_j;
//	unsigned int   StobValuebuf;
//	unsigned int   StobValuebuf_j;
//	unsigned int   LocalTime_Stob;
//	unsigned int   LocalTime_Fade;
//	unsigned int   LTime_Stob;
//	unsigned int   SumValue;
//	unsigned int   Color;
//	unsigned char  cDriverValue[LED_TOTAL];
//}LED_Type;
//extern xdata LED_Type Led;

void Led_Init(void);
void LedRedValueUpdate(uint8_t ByteData);
void LedGreenValueUpdate(uint8_t ByteData);
void LedBlueValueUpdate(uint8_t ByteData);
void LedWhiteValueUpdate(uint8_t ByteData);
void LedYellowValueUpdate(uint8_t ByteData);
void LedPurpleValueUpdate(uint8_t ByteData);

void LedStobValueUpdate(uint8_t ByteData);

void LedDMXDataCmd(void);

#endif /* _LED_H */
