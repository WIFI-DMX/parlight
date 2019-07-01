#ifndef _TM1618_H
#define _TM1618_H

 //WIFI-DMX.COM
void TM1618_KeyInit(void);
void TM1618_ReadKey(void);
extern xdata uint8_t TM1618_KEY[3]; 

typedef struct 	  
{ 		
   uint8_t 
    data1,
    data2,
    data3,
    data4,
	Point,
	State;
  uint16_t
	BackLightNum,
	SystemNum;   
}SEG_TypeDef,*pSEG_TypeDef;

void TM1618_Display(void);
void TM1618_Update(uint8_t xdata ByteData1,uint8_t xdata ByteData2,uint8_t xdata ByteData3,uint8_t xdata ByteData4,uint8_t xdata ByteDataP);	
void TM1618_DisplayOFF(void);

extern xdata SEG_TypeDef SEGMenu_Buf;
extern xdata SEG_TypeDef SEGMenu_aBuf;
extern pSEG_TypeDef pSEG;

typedef enum
{
 LED_0	  =((uint8_t)0),
 LED_1,
 LED_2,
 LED_3,
 LED_4,
 LED_5,
 LED_6,
 LED_7,
 LED_8,
 LED_9,
 LED_off,
 LED_point,
 LED_A,
 LED_u,
 LED_t,
 LED_o,
 LED__,
 LED_d,
 LED_r,
 LED_g,
 LED_b,
 LED_w,
 LED_S,
 LED_L,
 LED_C,
 LED_e,
 LED_U,
 LED_n,
 LED_F,
 LED_P,
 LED_I,
 LED_O,
 LED_h,
 LED_H,
 LED_Npoint,
 LED_a,
 LED_E,
 LED_c,
 LED_N,
 LED_Y,
 LED_Du,
}LED_Display;
typedef enum
{
 LED_PN	=((uint8_t)0x00),
 LED_P1	=((uint8_t)0x01),
 LED_P2	=((uint8_t)0x02),
 LED_P3	=((uint8_t)0x04),
 LED_P4	=((uint8_t)0x08),
 LED_PA	=((uint8_t)0x0F),
}LED_Point;

#endif /* __SPI_H */

