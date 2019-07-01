#ifndef __CONFIG_H
#define __CONFIG_H
 //WIFI-DMX.COM
// T-0002C-S

//#define USE_AD_4_7K_enable (1)

#define Ver_No1 1
#define Ver_No2 0
#define Ver_No3 0
					
#define Ver_UP        "  Reset "
#define Ver_DOWM      "  V1.00 "
#define Ver_Child     "Version "

#define Chan_11        LED_off
#define Chan_12        LED_4
#define Chan_21        LED_off
#define Chan_22        LED_8
#define Chan_31        LED_1
#define Chan_32        LED_4

#define Chan_1	 "  4Ch   "
#define Chan_2	 "  8Ch   "
#define Chan_3	 "  14Ch  "
#define ShowChan_1    "4Ch"
#define ShowChan_2    "8Ch"
#define ShowChan_3    "14Ch"

#define CHINESE_CH1_1 HZ_1
#define CHINESE_CH1_2 HZ_3
#define CHINESE_CH2_1 HZ_1
#define CHINESE_CH2_2 HZ_6

#define CHINESE_CH3_1 HZ_1
#define CHINESE_CH3_2 HZ_8
#define CHINESE_CH4_1 HZ_1
#define CHINESE_CH4_2 HZ_9

//#define USE_FULL_NULL    1
#define USE_FULL_ZOOM    1
#define USE_FULL_ROTA    1

#define	BackLightTime	1000//20MS*300=6S

#ifdef  USE_FULL_ZOOM
#define Manu_Show2Z     "Zoom    "
#define Manu_Show1Z     "[Zoom]  "
#endif
#ifdef  USE_FULL_ROTA
#define Manu_Show2R     "Rota    "  
#define Manu_Show1R     "[Rota]  " 
#endif
typedef enum
{
 _1channel	  =((uint8_t)4),
 _2channel	  =((uint8_t)8),
 _3channel	  =((uint8_t)14),
 _4channel	  =((uint8_t)43),
}Channel_Type;



#endif /* __CONFIG_H */
