#ifndef	_Menu_H_
#define _Menu_H_
#include "Common.h"
 //WIFI-DMX.COM
#define	BackMenuTime (BackLightTime*3/2)	
#define	BackSystemTime (BackMenuTime*2)	//
#define	LCD1602MaxDisplaYLinE	1         
#define KEY_LongPress    80//3s     


extern uint8_t code Number_Char[];
void Update_ResetYes(void);
void MenuShow(void);
void MenuChange(void);
void MenuKeyInit(void);
//void SystemShow(void);
uint8_t MainNormal(void);
void Update_Clear(void);
void SYS_MenuInit(void);

extern xdata uint8_t
PurpleLumValue,
YellowLumValue,
WhiteLumValue,
BlueLumValue,
GreenLumValue,
RedLumValue,
Memory_Stob;

extern xdata int8_t DisplayStart ; 			     
extern xdata int8_t UserChoose   ; 				 
extern xdata int8_t DisplayPoint ; 				  
extern xdata int8_t MaxItems     ;  			  
extern xdata int8_t Option	   ;   
extern xdata int8_t Option1	   ; 
extern xdata int8_t Option2	   ; 

		
#endif
