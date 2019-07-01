#include "main.h"
/*
STM32 T-0002 
PB1-MENU PC13-UP PC14-DOWM PC15-ENTER
*/
#if LCM_SEG_ENABLE
/*
STM32 T-0002 
PB1-MENU PC13-UP PC14-DOWM PC15-ENTER
*/
 //WIFI-DMX.COM

uint8_t code Number_Char[]={"0123456789 .C"}; 	


#define TM_KEY1	 0x01
#define TM_KEY2	 0x08
#define TM_KEY3	 0x02
#define TM_KEY4	 0x10



//按键属性
#define     KEY_DOWN        0x00   
#define     KEY_LONG        0x0A   
#define     KEY_LIAN        0x0B   
#define     KEY_UP          0x0C   

#define	UpLONG	    (Up|KEY_LONG)	                    						   
#define DownLONG    (Down|KEY_LONG)                      
#define EscLONG     (Esc|KEY_LONG)                      
#define EnterLONG   (Enter|KEY_LONG)                      

xdata uint8_t KeyDowmMark =0;
xdata uint8_t KeyUPMark =0;
xdata uint8_t LongMark=0;
xdata uint8_t LongKeyUPMark=0;

xdata uint8_t
PurpleLumValue=0,
YellowLumValue=0,
WhiteLumValue=0,
BlueLumValue=0,
GreenLumValue=0,
RedLumValue=0,
Memory_Stob;

xdata int8_t  DisplayStart     = 0; 			     
xdata int8_t  UserChoose       = 0; 				 
xdata int8_t  DisplayPoint     = 0; 				  
xdata int8_t  MaxItems         = 0;  			  
xdata int8_t  Option		   = 0; 
xdata int8_t  Option1		   = 0;    
xdata int8_t  Option2		   = 0;    
           

void MenuKeyInit(void){
}
/********************************************************************************************************/
struct  Menu_TypeDef{ 	
	uint8_t 	            Menulayer; 
	int8_t 	                MenuCount;      
//	uint8_t	            	*DisplayString;   
//	uint8_t	            	*DisplayStrCN; 
	LED_Display				DisplayLED[4];
	void                    (*Subs)();         
	struct  Menu_TypeDef 	*ChildrenMenus;
	struct  Menu_TypeDef 	*ParentMenus;  
	MenuDataUpdate_Type     MenuType;		
	Menu_Type FlashMark;
}; 

/********************************************************************************/
static void NullSubs(void) 					   	   
{ 				  } 
struct Menu_TypeDef code Menu_Null;
struct Menu_TypeDef code MainMenu[];
struct Menu_TypeDef code Auto_Children[];
struct Menu_TypeDef code LED_Children[];
struct Menu_TypeDef code Manu_Children[];
struct Menu_TypeDef code Fun_Children[]; 
struct Menu_TypeDef code Run_Children[]; 
struct Menu_TypeDef code Calibrations_Children[];


/*******Auto自走参数设置******************************/
struct Menu_TypeDef code Auto_HclUpdate[1] =	  
{					    
		{4,1,/*"Coch    ","        ",*/LED_C,LED_1,LED_2,LED_3,Update_AutoHclFunction,&Menu_Null,Auto_Children,_MenuDataUpdate_Hcl,_FlashMode},
};
//struct Menu_TypeDef code Auto_StobUpdate[1] =	   
//{					    
//		{4,1,/*"Stob    ","        ",*/LED_S,LED_1,LED_2,LED_3,Update_AutoStobFunction,&Menu_Null,Auto_Children,_MenuDataUpdate_Stob,_FlashMode},
//};

/***********************************************************/
/********RGBW 参数0~255***********************/
struct Menu_TypeDef code Manu_RedUpdate[1] =	  
{					    
		{4,1,/*" Red    ","        ",*/LED_r,LED_e,LED_d,LED_off,Update_ManuFunction,Manu_Children,Manu_Children,_MenuDataUpdate_Red,_FlashMode},
};
struct Menu_TypeDef code Manu_GrnUpdate[1] =	  
{					    
		{4,1,/*" Green  ","        ",*/LED_g,LED_r,LED_e,LED_e,Update_ManuFunction,Manu_Children,Manu_Children,_MenuDataUpdate_Grn,_FlashMode},
};
struct Menu_TypeDef code Manu_BluUpdate[1] =	  
{					    
		{4,1,/*" Blue   ","        ",*/LED_b,LED_L,LED_u,LED_e,Update_ManuFunction,Manu_Children,Manu_Children,_MenuDataUpdate_Blu,_FlashMode},
};
struct Menu_TypeDef code Manu_WhiUpdate[1] =	   
{					    
		{4,1,/*" White  ","        ",*/LED_U,LED_h,LED_I,LED_t,Update_ManuFunction,Manu_Children,Manu_Children,_MenuDataUpdate_Whi,_FlashMode},
};

struct Menu_TypeDef code Manu_YelUpdate[1] =	  
{					    
		{4,1,/*" Yellow ","        ",*/LED_Y,LED_e,LED_L,LED_off,Update_ManuFunction,Manu_Children,Manu_Children,_MenuDataUpdate_Yel,_FlashMode},
};
struct Menu_TypeDef code Manu_PurpleUpdate[1] =	   
{					    
		{4,1,/*" Purple ","        ",*/LED_P,LED_u,LED_r,LED_off,Update_ManuFunction,Manu_Children,Manu_Children,_MenuDataUpdate_Purple,_FlashMode},
};

struct Menu_TypeDef code Manu_StrobeUpdate[1] =	   
{					    
		{4,1,/*"Strobe  ","        ",*/LED_S,LED_1,LED_2,LED_3,Update_ManuFunction,Manu_Children,Manu_Children,_MenuDataUpdate_Stob,_FlashMode},
};

struct Menu_TypeDef code Calibrations_RedUpdate[1] =	 
{					    
		{4,1,/*" Red    ","        ",*/LED_r,LED_e,LED_d,LED_off,Update_ManuFunction,Calibrations_Children,Calibrations_Children,_MenuDataUpdate_CalibrationsRed,_FlashMode},
};
struct Menu_TypeDef code Calibrations_GreenUpdate[1] =	 
{					    
		{4,1,/*" Green  ","        ",*/LED_g,LED_r,LED_e,LED_e,Update_ManuFunction,Calibrations_Children,Calibrations_Children,_MenuDataUpdate_CalibrationsGreen,_FlashMode},
};
struct Menu_TypeDef code Calibrations_BlueUpdate[1] =	 
{					    
		{4,1,/*" Blue  ","        ",*/LED_b,LED_L,LED_u,LED_e,Update_ManuFunction,Calibrations_Children,Calibrations_Children,_MenuDataUpdate_CalibrationsBlue,_FlashMode},
};
struct Menu_TypeDef code Calibrations_WhiteUpdate[1] =	 
{					    
		{4,1,/*" White  ","        ",*/LED_U,LED_h,LED_I,LED_t,Update_ManuFunction,Calibrations_Children,Calibrations_Children,_MenuDataUpdate_CalibrationsWhite,_FlashMode},
};	  
#if COLOR_6_ENABLE
struct Menu_TypeDef code Calibrations_YellowUpdate[1] =	 
{					    
		{4,1,/*" Yellow ","        ",*/LED_Y,LED_e,LED_L,LED_off,Update_ManuFunction,Calibrations_Children,Calibrations_Children,_MenuDataUpdate_CalibrationsYellow,_FlashMode},
};
struct Menu_TypeDef code Calibrations_PurpleUpdate[1] =	 
{					    
		{4,1,/*" Purple ","        ",*/LED_P,LED_u,LED_r,LED_off,Update_ManuFunction,Calibrations_Children,Calibrations_Children,_MenuDataUpdate_CalibrationsPurple,_FlashMode},
};
#endif
//struct Menu_TypeDef code Dimmer_Children[4] =	 
//{
//		{3,4,/*"Dimmer  ","Square  ",*/LED_C,LED_u,LED__,LED_1,Update_Dimmer0,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//		{3,4,/*"Dimmer  ","Linear  ",*/LED_C,LED_u,LED__,LED_2,Update_Dimmer1,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//		{3,4,/*"Dimmer  ","S-Curve ",*/LED_C,LED_u,LED__,LED_3,Update_Dimmer2,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//		{3,4,/*"Dimmer  ","InSquare",*/LED_C,LED_u,LED__,LED_4,Update_Dimmer3,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//};
//struct Menu_TypeDef code HZ_Children[4] =	 
//{
//		{3,4,/*"Refresh "," 600HZ  ",*/LED_H,LED__,LED_0,LED_6,Update_RefreshRate0,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//		{3,4,/*"Refresh "," 1200HZ ",*/LED_H,LED__,LED_1,LED_2,Update_RefreshRate1,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//		{3,4,/*"Refresh "," 2400HZ ",*/LED_H,LED__,LED_2,LED_4,Update_RefreshRate2,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//		{3,4,/*"Refresh "," 4800HZ ",*/LED_H,LED__,LED_4,LED_8,Update_RefreshRate3,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//};
//struct Menu_TypeDef code Smooth_Children[3] =	 
//{
//		{3,3,/*"Dimmer  "," Smooth1",*/LED_S,LED_N,LED_o,LED_1,Update_Smooth0,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//		{3,3,/*"Dimmer  "," Smooth2",*/LED_S,LED_N,LED_o,LED_2,Update_Smooth1,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//		{3,3,/*"Dimmer  "," Smooth3",*/LED_S,LED_N,LED_o,LED_3,Update_Smooth2,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
//};

struct Menu_TypeDef code NoDMXStatus_Children[2] =	 
{					    
		{3,2,/*"DMX Fail"," Off    ",*/LED_o,LED_F,LED_F,LED_off,Update_NoDMXStatusClose,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
		{3,2,/*"DMX Fail"," Hold   ",*/LED_H,LED_o,LED_L,LED_d,Update_NoDMXStatusHold,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
};
struct Menu_TypeDef code LED_Children[2] =	   
{					    
		{3,2,/*" Light  ","  On    ",*/LED_o,LED_n,LED_off,LED_off,Update_BackLEDOn,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
		{3,2,/*" Light  ","  Off   ",*/LED_o,LED_F,LED_F,LED_off,Update_BackLEDOff,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
};
struct Menu_TypeDef code Reset_Children[2] =	 
{					    
		{3,2,/*" Reset  ","  Yes   ",*/LED_Y,LED_e,LED_S,LED_off,Update_ResetYes,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
		{3,2,/*" Reset  ","  No    ",*/LED_n,LED_o,LED_off,LED_off,Update_ResetNo,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
};
struct Menu_TypeDef code Factory_Children[2] =	 
{					    
		{3,2,/*"Factory ","  Yes   ",*/LED_Y,LED_e,LED_S,LED_off,Update_FactoryYes,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
		{3,2,/*"Factory ","  No    ",*/LED_n,LED_o,LED_off,LED_off,Update_FactoryNo,Fun_Children,Fun_Children,_MenuDataUpdate_None,_FlashMode1},
};
#if COLOR_6_ENABLE
struct Menu_TypeDef code Calibrations_Children[7] =	 
{					    	
		{3,7,/*"Calibrat"," Red    ",*/LED_r,LED_e,LED_d,LED_off,&NullSubs,Calibrations_RedUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{3,7,/*"Calibrat"," Green  ",*/LED_g,LED_r,LED_e,LED_e,&NullSubs,Calibrations_GreenUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{3,7,/*"Calibrat"," Blue   ",*/LED_b,LED_L,LED_u,LED_off,&NullSubs,Calibrations_BlueUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},				
		{3,7,/*"Calibrat"," White  ",*/LED_U,LED_h,LED_I,LED_t,&NullSubs,Calibrations_WhiteUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{3,7,/*"Calibrat"," Yellow ",*/LED_Y,LED_e,LED_L,LED_off,&NullSubs,Calibrations_YellowUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},				
		{3,7,/*"Calibrat"," Purple ",*/LED_P,LED_u,LED_r,LED_off,&NullSubs,Calibrations_PurpleUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{3,7,/*"Calibrat","Default ",*/LED_d,LED_e,LED_F,LED_a,Update_CalibrationsDefaultFunction,Calibrations_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},
};
#else
struct Menu_TypeDef code Calibrations_Children[5] =	 
{					    	
		{3,5,/*"Calibrat"," Red    ",*/LED_r,LED_e,LED_d,LED_off,&NullSubs,Calibrations_RedUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{3,5,/*"Calibrat"," Green  ",*/LED_g,LED_r,LED_e,LED_e,&NullSubs,Calibrations_GreenUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{3,5,/*"Calibrat"," Blue   ",*/LED_b,LED_L,LED_u,LED_off,&NullSubs,Calibrations_BlueUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},				
		{3,5,/*"Calibrat"," White  ",*/LED_U,LED_h,LED_I,LED_t,&NullSubs,Calibrations_WhiteUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{3,5,/*"Calibrat","Default ",*/LED_d,LED_e,LED_F,LED_a,Update_CalibrationsDefaultFunction,Calibrations_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},
};
#endif
/******************************************************************************************************************/
struct Menu_TypeDef code Fade_Children[1] =	
{					    
        {4,1,/*"ShowSpeed","        ",*/LED_S,LED_P,LED_E,LED_d,Update_AutoFadeFunction,Run_Children,Run_Children,_MenuDataUpdate_Fade,_FlashMode},
}; 
struct Menu_TypeDef code Auto_Children[1] =	
{					    
        {3,1,/*"ShowMode","        ",*/LED_A,LED_u,LED_t,LED_o,Update_AutoHclFunction,Fade_Children,MainMenu,_MenuDataUpdate_Hcl,_StaticMode},
}; 
struct Menu_TypeDef code Nors_Children[1] =	  
{					    
		{3,1,/*" Slave  "," Slave1 ",*/LED_S,LED_L,LED_A,LED_1,Update_Slave1Mode,Run_Children,Run_Children,_MenuDataUpdate_None,_StaticMode},
//		{3,2,/*" Slave  "," Slave2 ",*/LED_S,LED_L,LED_A,LED_2,Update_Slave2Mode,MainMenu,MainMenu,_MenuDataUpdate_None,_StaticMode},
};
struct Menu_TypeDef code Sond_SoseUpdate[1] =	
{
        {3,1,/*" Sens   ","        ",*/LED_0,LED_1,LED_2,LED_3,Update_SoundSose,Run_Children,Run_Children,_MenuDataUpdate_Sose,_FlashMode},
};

#if COLOR_6_ENABLE
struct Menu_TypeDef code Manu_Children[7] =	 
{					    
		{3,7,/*"Manual  "," Strobe ",*/LED_S,LED_t,LED_r,LED_o,&NullSubs,Manu_StrobeUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},	
		{3,7,/*"Manual  "," Red    ",*/LED_r,LED_e,LED_d,LED_off,&NullSubs,Manu_RedUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
		{3,7,/*"Manual  "," Green  ",*/LED_g,LED_r,LED_e,LED_e,&NullSubs,Manu_GrnUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
		{3,7,/*"Manual  "," Blue   ",*/LED_b,LED_L,LED_u,LED_off,&NullSubs,Manu_BluUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
		{3,7,/*"Manual  "," White  ",*/LED_U,LED_h,LED_I,LED_t,&NullSubs,Manu_WhiUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
		{3,7,/*"Manual  "," Yellow ",*/LED_Y,LED_e,LED_L,LED_off,&NullSubs,Manu_YelUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
		{3,7,/*"Manual  "," Purple ",*/LED_P,LED_u,LED_r,LED_off,&NullSubs,Manu_PurpleUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
};
#else
struct Menu_TypeDef code Manu_Children[5] =	 
{					    
		{3,5,/*"Manual  "," Strobe ",*/LED_S,LED_t,LED_r,LED_o,&NullSubs,Manu_StrobeUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},	
		{3,5,/*"Manual  "," Red    ",*/LED_r,LED_e,LED_d,LED_off,&NullSubs,Manu_RedUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
		{3,5,/*"Manual  "," Green  ",*/LED_g,LED_r,LED_e,LED_e,&NullSubs,Manu_GrnUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
		{3,5,/*"Manual  "," Blue   ",*/LED_b,LED_L,LED_u,LED_off,&NullSubs,Manu_BluUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
		{3,5,/*"Manual  "," White  ",*/LED_U,LED_h,LED_I,LED_t,&NullSubs,Manu_WhiUpdate,Run_Children,_MenuDataUpdate_None,_StaticMode},
};
#endif

struct Menu_TypeDef code Addr_Children[1] =	 
{
		{2,1,/*"Address ","        ",*/LED_A,LED__,LED__,LED__,UpdateDmxAddress,MainMenu,MainMenu,_MenuDataUpdate_Addr,_FlashMode},
};
struct Menu_TypeDef code Run_Children[5] =	 
{					    
		{2,5,/*"Run Mode"," DMX    ",*/LED_A,LED_d,LED_d,LED_r,Enter_AddrFunction,Addr_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{2,5,/*"Run Mode"," Auto   ",*/LED_A,LED_u,LED_t,LED_o,Enter_AutoFunction,Auto_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},	
		{2,5,/*"Run Mode"," Slave  ",*/LED_S,LED_L,LED_A,LED_u,Update_Slave1Mode,Nors_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{2,5,/*"Run Mode"," Sound  ",*/LED_S,LED_o,LED_u,LED_d,Update_SoundOn,Sond_SoseUpdate,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{2,5,/*"Run Mode"," Manual ",*/LED_N,LED_A,LED_n,LED_u,Enter_ManuFunction,Manu_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},	
};
struct Menu_TypeDef code Fun_Children[3] =	 
{					    
//		{2,6,/*"Dimmer  "," Curve  ",*/LED_C,LED_u,LED_r,LED__,&NullSubs,Dimmer_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},
//		{2,6,/*"Refresh "," Rate   ",*/LED_H,LED__,LED__,LED__,&NullSubs,HZ_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},
//		{2,6,/*"Dimmer  "," Smooth ",*/LED_S,LED_N,LED_o,LED_o,&NullSubs,Smooth_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},			
		{2,3,/*" DMX    "," Fail   ",*/LED_F,LED_A,LED_I,LED_L,&NullSubs,NoDMXStatus_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{2,3,/*" Back   "," Light  ",*/LED_L,LED_E,LED_d,LED_off,&NullSubs,LED_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{2,3,/*"Factory "," Sets   ",*/LED_F,LED_A,LED_C,LED_t,&NullSubs,Factory_Children,MainMenu,_MenuDataUpdate_None,_StaticMode},
};
struct Menu_TypeDef code Chan_Children[2] =	 
{
		{2,2,/*"Channel ","Channel ",*/Chan_11,Chan_12,LED_c,LED_h,UpdateChannel1,MainMenu,MainMenu,_MenuDataUpdate_None,_StaticMode},
		{2,2,/*"Channel ","Channel ",*/Chan_21,Chan_22,LED_c,LED_h,UpdateChannel2,MainMenu,MainMenu,_MenuDataUpdate_None,_StaticMode},
//		{2,3,/*"Channel ","Channel ",*/Chan_31,Chan_32,LED_c,LED_h,UpdateChannel3,MainMenu,MainMenu,_MenuDataUpdate_None,_StaticMode},
};
struct Menu_TypeDef code Ver_Children[2] =	 
{					    
		{2,2,/*"Version "," Beam   ",*/LED_0,LED_1,LED_2,LED_3,&NullSubs,MainMenu,MainMenu,_MenuDataUpdate_Ver,_StaticMode},
		{2,2,/*"Version "," Beam   ",*/LED_0,LED_1,LED_2,LED_3,&NullSubs,MainMenu,MainMenu,_MenuDataUpdate_Temp,_StaticMode},
};
struct Menu_TypeDef (*MenuPoint) = MainMenu; 
struct Menu_TypeDef code MainMenu[6] =	  
{
		{1,6,/*"  DMX   ","Address ",*/LED_A,LED_d,LED_d,LED_r,Enter_AddrFunction,Addr_Children,&Menu_Null,_MenuDataUpdate_None,_StaticMode},
		{1,6,/*"Channel "," Mode   ",*/LED_C,LED_h,LED_A,LED_n,&NullSubs,Chan_Children,&Menu_Null,_MenuDataUpdate_None,_StaticMode},
		{1,6,/*"  Run   ","  Mode  ",*/LED_N,LED_o,LED_d,LED_E,&NullSubs,Run_Children,&Menu_Null,_MenuDataUpdate_None,_StaticMode},
		{1,6,/*"Settings","        ",*/LED_S,LED_E,LED_t,LED_off,&NullSubs,Fun_Children,&Menu_Null,_MenuDataUpdate_None,_StaticMode},
		{1,6,/*"Calibrat","ions    ",*/LED_C,LED_A,LED_L,LED_I,&NullSubs,Calibrations_Children,&Menu_Null,_MenuDataUpdate_None,_StaticMode},
		{1,6,/*"Version ","        ",*/LED_I,LED_n,LED_F,LED_o,&NullSubs,Ver_Children,&Menu_Null,_MenuDataUpdate_None,_StaticMode},
};


uint8_t key_scan(void)
{
    static xdata uint8_t  KeyState   = 0;       
    static xdata uint8_t  KeyDelay   = 0;       
    static xdata uint8_t  KeyBuf     = 0;      

    xdata uint8_t KeyPress  = NO_KEY;         
    xdata uint8_t KeyReturn = NO_KEY;          
    //SEG_Key();
//	KeyPress =((pSEG->KeyBuf)&0xF000);	
	TM1618_ReadKey();
	KeyPress = (uint8_t)((TM1618_KEY[0]>>1)|TM1618_KEY[1]);
	switch(KeyPress)
	{
	  case TM_KEY1:
	       KeyPress=Esc;    //TM1618_Update(&SEGMenu_Buf,LED_1,LED_1,LED_1,LED_1,LED_PN);
	  break;
	  case TM_KEY2:
	       KeyPress=Up;     //TM1618_Update(&SEGMenu_Buf,LED_2,LED_2,LED_2,LED_2,LED_PN);
	  break;			  
	  case TM_KEY3:
	       KeyPress=Down;   //TM1618_Update(&SEGMenu_Buf,LED_3,LED_3,LED_3,LED_3,LED_PN);
	  break;
	  case TM_KEY4:
	       KeyPress=Enter;  
		   //KeyPress=NO_KEY;
		   //TM1618_Update(&SEGMenu_Buf,LED_4,LED_4,LED_4,LED_4,LED_PN);
	  break;
	  default:KeyPress=NO_KEY;break;
	}	

    switch(KeyState){
        case 0:     
            if( KeyPress !=NO_KEY ){
                KeyState = 1;
                KeyBuf   = KeyPress;  
            }
            break;  
        case 1:
            if( KeyPress !=NO_KEY  ){         
                if(KeyBuf  != KeyPress){
                    KeyState  = 0;	
                }
                else{
                    KeyState  = 2;
                    KeyReturn = NO_KEY;//KEY_DOWN | KeyBuf;        
                }
            }
            else{
                KeyState = 0;
            }
            break;      
        case 2:            
            if( KeyPress !=NO_KEY ){
                KeyDelay++;
                if(KeyDelay>KEY_LongPress) {
				  KeyState   = 3;
				  KeyDelay   = 0;
                }
				else if((KeyDelay>KEY_LongPress/2)&&(MenuPoint[UserChoose].ChildrenMenus != Fun_Children)){
				  KeyState   = 3;
				  KeyDelay   = 0;
                }
			break;
			}
	    case 3:
		    if( KeyPress !=NO_KEY ){					 
					if((MenuPoint[UserChoose].ChildrenMenus == Fun_Children)||(MenuPoint[UserChoose].FlashMark==_FlashMode)||(MenuPoint[DisplayPoint].MenuType==_MenuDataUpdate_Password)){KeyReturn  = KEY_LONG | KeyBuf; LongKeyUPMark=1;}      
            break;        
            }   
        case 4:
            if(KeyPress == NO_KEY ){
                KeyState   = 0;
				if(!LongKeyUPMark){
                  KeyReturn  = KEY_UP | KeyBuf;           
				  //KeyUPMark=1;
				} 
				KeyUPMark=1;
				LongKeyUPMark=0;
				KeyDelay   = 0;
            }   
            break;
        default :break;
    }	    
    return KeyReturn;
}

void MenuChar(uint16_t dat,uint8_t M)
{
	SEGMenu_Buf.data1 = 10;
	if(M>1){
		SEGMenu_Buf.data2 =10;
	}
	else{
		SEGMenu_Buf.data2 = (uint8_t)(dat % 1000 / 100);
	}
	SEGMenu_Buf.data3 = (uint8_t)(dat % 100 / 10);
	SEGMenu_Buf.data4 = (uint8_t)(dat % 10);
}
/*
void SystemShowDMX(void)
{
	if((DMX_RegStructure.DMX_SIGNAL_MARK>300)||(SYS_State==SYS_Slave)){
		//LCM_Write_string(0,0,"DMX FAIL");	
		//if(SYS_StateBuf==SYS_Dmx){LCM_LIGHT_ON;}
	}
	else{
		//LCM_Write_string(0,0,"DMX");
	}
	
	MenuChar(Memory_Struct.Memory_Addr,0);
	SEGMenu_Buf.data1=LED_A;
}


void SystemShow(void)
{
	SEGMenu_Buf.Point=LED_PN;
	if((SYS_StateBuf==SYS_Dmx)){
		SystemShowDMX();
	}
	else{	 	
	switch(SYS_State){
		case SYS_Colo:
		TM1618_Update(&SEGMenu_Buf,LED_N,LED_A,LED_n,LED_u,LED_PN);
		break;
		case SYS_Dmx:
		MenuChar(Memory_Struct.Memory_Addr,0);
		SEGMenu_Buf.data1=LED_A;
		break;
		case SYS_Auto:
		MenuChar(Memory_Struct.Memory_Hcl,2);
		SEGMenu_Buf.data1=LED_A;
		SEGMenu_Buf.data2=LED_u;
		break;
		case SYS_Soud:
		TM1618_Update(&SEGMenu_Buf,LED_S,LED_o,LED_u,LED_d,LED_PN);
		break;
		case SYS_Slave:
		if(Memory_Struct.Memory_Mode == _SlaveMode1){
			TM1618_Update(&SEGMenu_Buf,LED_S,LED_L,LED_A,LED_1,LED_PN);
		}
		else{
			TM1618_Update(&SEGMenu_Buf,LED_S,LED_L,LED_A,LED_2,LED_PN);		
		}
		break;
		default:break;
	}	
	}
	TempDispMark=1;
}
*/
//*------------------------------------------------------------------------------
//*显示函数
//*------------------------------------------------------------------------------
void MenuShow(void){
		pSEG=&SEGMenu_Buf;
		MaxItems = MenuPoint[0].MenuCount; 
		DisplayPoint = DisplayStart;
	    SEGMenu_Buf.Point=LED_PN;

	 switch (MenuPoint[DisplayPoint].MenuType)
		  {
		case _MenuDataUpdate_Addr: 
			  MenuChar(Memory_Struct.Memory_Addr,0);
			  SEGMenu_Buf.data1=LED_A;
			  break; 
	    case _MenuDataUpdate_Hcl:
			  MenuChar(Memory_Struct.Memory_Hcl,2);
			  SEGMenu_Buf.data1=LED_A;
			  SEGMenu_Buf.data2=LED_u;
		      break;
		case _MenuDataUpdate_Stob:
			  MenuChar(Memory_Struct.Memory_Stob,0);
		      break; 
		case _MenuDataUpdate_Fade:
			  MenuChar(Memory_Struct.Memory_Fade,0);
			  SEGMenu_Buf.data1=LED_S;
			  SEGMenu_Buf.data2=LED_P;
		      break;
		case _MenuDataUpdate_Red:
			  MenuChar(LED_RegStructure.RedLumValue,0);
		      break;
		case _MenuDataUpdate_Grn:
			  MenuChar(LED_RegStructure.GreenLumValue,0);
			  break;
	    case _MenuDataUpdate_Blu:
			  MenuChar(LED_RegStructure.BlueLumValue,0);
		      break;
		case _MenuDataUpdate_Whi:
			  MenuChar(LED_RegStructure.WhiteLumValue,0);
		      break;
#if COLOR_6_ENABLE
		case _MenuDataUpdate_Yel:
			  MenuChar(LED_RegStructure.YellowLumValue,0);
		      break;
		case _MenuDataUpdate_Purple:
			  MenuChar(LED_RegStructure.PurpleLumValue,0);
		      break;
#endif
		case _MenuDataUpdate_CalibrationsRed:
			  MenuChar(Memory_Struct.Memory_CalibrationsRed,0);
		      break;
		case _MenuDataUpdate_CalibrationsGreen:
			  MenuChar(Memory_Struct.Memory_CalibrationsGreen,0);
		      break;
		case _MenuDataUpdate_CalibrationsBlue:
			  MenuChar(Memory_Struct.Memory_CalibrationsBlue,0);
		      break;
		case _MenuDataUpdate_CalibrationsWhite:
			  MenuChar(Memory_Struct.Memory_CalibrationsWhite,0);
		      break;	
#if COLOR_6_ENABLE
		case _MenuDataUpdate_CalibrationsYellow:
			  MenuChar(Memory_Struct.Memory_CalibrationsYellow,0);
		      break;
		case _MenuDataUpdate_CalibrationsPurple:
			  MenuChar(Memory_Struct.Memory_CalibrationsPurple,0);
#endif
		      break;
		case _MenuDataUpdate_Temp:	
			 MenuChar(Temperature,2);
		     SEGMenu_Buf.data1=SEGMenu_Buf.data3;
			 SEGMenu_Buf.data2=SEGMenu_Buf.data4;
			 SEGMenu_Buf.data3=LED_Du;
			 SEGMenu_Buf.data4=LED_C;
			 break;	
		case _MenuDataUpdate_Ver:
		     SEGMenu_Buf.data1=LED_u;
			 SEGMenu_Buf.data2=Ver_No1;
			 SEGMenu_Buf.data3=Ver_No2;
			 SEGMenu_Buf.data4=Ver_No3;
			 SEGMenu_Buf.Point|=LED_P2;
			 break;
		case _MenuDataUpdate_Sose:
			 MenuChar(Memory_Struct.Memory_Sose,0);
		     break;
		case _MenuDataUpdate_LED:
			 MenuChar(Memory_Struct.Memory_BACKLED,2);
		     break;
		case _MenuDataUpdate_None:
			 SEGMenu_Buf.data1 = MenuPoint[DisplayPoint].DisplayLED[0];
             SEGMenu_Buf.data2 = MenuPoint[DisplayPoint].DisplayLED[1];
             SEGMenu_Buf.data3 = MenuPoint[DisplayPoint].DisplayLED[2];
             SEGMenu_Buf.data4 = MenuPoint[DisplayPoint].DisplayLED[3];			 
			 break;
		default :break;
		  }	
		  
	TM1618_Display();		  
}

//*------------------------------------------------------------------------------
//*菜单执行函数
//*------------------------------------------------------------------------------
/*
void MenuGetAdd(uint8_t* Bytedata,uint8_t max,uint8_t min,uint8_t ENLong){ 
	if((LongMark)&&(ENLong)){
		* Bytedata=(* Bytedata<max)?* Bytedata+10:min;
		if(* Bytedata>max)* Bytedata=max;
	}
	else{
		* Bytedata=(* Bytedata<max)?* Bytedata+1:min;			 
	}
	if(* Bytedata==max){
		KeyUPMark=0;
	}
}
void MenuGetDec(uint8_t* Bytedata,uint8_t max,uint8_t min,uint8_t ENLong)
{ 
	if((LongMark)&&(ENLong)){
		* Bytedata=(* Bytedata>min)?* Bytedata-10:max;
		if(* Bytedata>max)* Bytedata=max;
	}
	else{
		* Bytedata=(* Bytedata>min)?* Bytedata-1:max;			 
	}
	if(* Bytedata==min){
		KeyUPMark=0;
	}
}
*/
void GetAddDec(uint16_t* Bytedata,uint16_t xdata max,uint8_t xdata min,uint8_t xdata adddec){ 
	if(adddec){
		if((LongMark)&&(1)){
			* Bytedata=(* Bytedata<max)?* Bytedata+10:min;
			if(* Bytedata>max)* Bytedata=max;
		}
		else{
			* Bytedata=(* Bytedata<max)?* Bytedata+1:min;			 
		}
		if(* Bytedata==max){
			KeyUPMark=0;
		}	
	}
	else{
		if((LongMark)&&(1)){
			* Bytedata=(* Bytedata>min)?* Bytedata-10:max;
			if(* Bytedata>max)* Bytedata=max;
		}
		else{
			* Bytedata=(* Bytedata>min)?* Bytedata-1:max;			 
		}
		if(* Bytedata==min){
			KeyUPMark=0;
		}	
	}

}

uint8_t MenuAddDec(uint8_t adddec)
{
  switch (MenuPoint[DisplayPoint].MenuType)
  {
		case _MenuDataUpdate_Addr:	
			 GetAddDec(&Memory_Struct.Memory_Addr,512,1,adddec);
		break;
		case _MenuDataUpdate_Hcl:
			 GetAddDec(&Memory_Struct.Memory_Hcl,8,1,adddec);
			 Task_Sys_i=0;
		     LED_RegStructure.HclValue=0;		   
		break;
		case _MenuDataUpdate_Stob:
			 GetAddDec(&Memory_Struct.Memory_Stob,255,0,adddec);
			 LedStobValueUpdate(Memory_Struct.Memory_Stob);
			 Memory_Stob=Memory_Struct.Memory_Stob;
		break;
		case _MenuDataUpdate_Fade:
			 GetAddDec(&Memory_Struct.Memory_Fade,50,0,adddec);
		break;
		case _MenuDataUpdate_Red:
			 GetAddDec(&LED_RegStructure.RedLumValue,255,0,adddec);
			 LedRedValueUpdate(LED_RegStructure.RedLumValue);
			 RedLumValue=LED_RegStructure.RedLumValue;
		break;
		case _MenuDataUpdate_Grn:
		     GetAddDec(&LED_RegStructure.GreenLumValue,255,0,adddec);
			 LedGreenValueUpdate(LED_RegStructure.GreenLumValue);
			 GreenLumValue=LED_RegStructure.GreenLumValue;
		break;
		case _MenuDataUpdate_Blu:
		     GetAddDec(&LED_RegStructure.BlueLumValue,255,0,adddec);
			 LedBlueValueUpdate(LED_RegStructure.BlueLumValue);
			 BlueLumValue=LED_RegStructure.BlueLumValue;
		break;
		case _MenuDataUpdate_Whi:
		     GetAddDec(&LED_RegStructure.WhiteLumValue,255,0,adddec);
			 LedWhiteValueUpdate(LED_RegStructure.WhiteLumValue);
			 WhiteLumValue=LED_RegStructure.WhiteLumValue;
		break;
#if COLOR_6_ENABLE
		case _MenuDataUpdate_Yel:
		     GetAddDec(&LED_RegStructure.YellowLumValue,255,0,adddec);
			 LedYellowValueUpdate(LED_RegStructure.YellowLumValue);
			 YellowLumValue=LED_RegStructure.YellowLumValue;
		break;
		case _MenuDataUpdate_Purple:
		     GetAddDec(&LED_RegStructure.PurpleLumValue,255,0,adddec);
			 LedPurpleValueUpdate(LED_RegStructure.PurpleLumValue);
			 PurpleLumValue=LED_RegStructure.PurpleLumValue;
#endif
		break;
		case _MenuDataUpdate_Sose:
			 GetAddDec(&Memory_Struct.Memory_Sose,255,0,adddec);	 
		break;
		case _MenuDataUpdate_LED:
			 GetAddDec(&Memory_Struct.Memory_BACKLED,10,1,adddec);	 
		break;			 
		case _MenuDataUpdate_CalibrationsRed:
			 GetAddDec(&Memory_Struct.Memory_CalibrationsRed,255,Calibrations_Min,adddec);
		break;
		case _MenuDataUpdate_CalibrationsGreen:
			 GetAddDec(&Memory_Struct.Memory_CalibrationsGreen,255,Calibrations_Min,adddec);
		break;
		case _MenuDataUpdate_CalibrationsBlue:
			 GetAddDec(&Memory_Struct.Memory_CalibrationsBlue,255,Calibrations_Min,adddec);
		break;
		case _MenuDataUpdate_CalibrationsWhite:
			 GetAddDec(&Memory_Struct.Memory_CalibrationsWhite,255,Calibrations_Min,adddec);
		break;				
#if COLOR_6_ENABLE
		case _MenuDataUpdate_CalibrationsYellow:
			 GetAddDec(&Memory_Struct.Memory_CalibrationsYellow,255,Calibrations_Min,adddec);
		break;
		case _MenuDataUpdate_CalibrationsPurple:
			 GetAddDec(&Memory_Struct.Memory_CalibrationsPurple,255,Calibrations_Min,adddec);
		break;
#endif
		case _MenuDataUpdate_Password:
			 GetAddDec(&Memory_Struct.Memory_Password,255,0,adddec);
		break;
		default :return	0;
 }
return 1;
}

void MenuDisplayStart2(uint8_t xdata a,uint8_t xdata b){
	MenuPoint = MenuPoint[UserChoose].ChildrenMenus;
	if(a == b){
		UserChoose   = 0; 
		DisplayStart = 0; 
	}
	else{
		UserChoose   = 1; 
		DisplayStart = 1; 
	}									
}
void MenuDisplayStart5(uint8_t xdata a)
{
	MenuPoint = MenuPoint[UserChoose].ChildrenMenus;
	switch(a){
	case 0:
		UserChoose   = 0; 
		DisplayStart = 0; 
	break;
	case 1:
		UserChoose   = 1; 
		DisplayStart = 1; 
	break;
	case 2:
		UserChoose   = 2; 
		DisplayStart = 2; 
	break;
	case 3:
		UserChoose   = 3; 
		DisplayStart = 3; 
	break;
	case 4:
		UserChoose   = 4; 
		DisplayStart = 4; 
	break;
	default:break;
	}										
}

void MenuDisplayStart5_(uint8_t xdata a)
{
	MenuPoint = MenuPoint[UserChoose].ChildrenMenus;
	switch(a){
	case _1channel:
		UserChoose   = 0; 
		DisplayStart = 0; 
	break;
	case _2channel:
		UserChoose   = 1; 
		DisplayStart = 1; 
	break;
	case _3channel:
		UserChoose   = 2; 
		DisplayStart = 2; 
	break;
	case _4channel:
		UserChoose   = 3; 
		DisplayStart = 3; 
	break;
	default:break;
	}										
}

void MenuChoose(void){
	if(MenuPoint[0].Menulayer==3){
		if(MenuPoint[0].MenuCount>Option2)UserChoose =Option2;
	}
	else if(MenuPoint[0].Menulayer==2){
		if(MenuPoint[0].MenuCount>Option1)UserChoose =Option1;
	}
	else{
		if(MenuPoint[0].MenuCount>Option)UserChoose =Option;
	}
}

void Menulayer_Choose(void){	
	if(MenuPoint[0].Menulayer==3) {
		Option2 = UserChoose;
	}
	else if(MenuPoint[0].Menulayer==2) {
		Option1 = UserChoose;
	}
	else {
		Option = UserChoose;
	}
}

void SYS_MenuInit(void){
	Option=2;
	Option1=2;
	MenuPoint=Run_Children; 
	switch(SYS_State){
	case SYS_Dmx:
		UserChoose   = 0; 
		DisplayStart = 0; 
	break;
	case SYS_Auto:
		UserChoose   = 1; 
		DisplayStart = 1; 
	break;
	case SYS_Slave:
		UserChoose   = 2; 
		DisplayStart = 2; 
	break;
	case SYS_Soud:
		UserChoose   = 3; 
		DisplayStart = 3; 
	break;
	case SYS_Colo:
		UserChoose   = 4; 
		DisplayStart = 4; 
	break;
	default:break;
	}
}

//*------------------------------------------------------------------------------
//*菜单执行函数
//*------------------------------------------------------------------------------
void MenuChange(void)
{ 
xdata uint8_t GetKeyNum;
	   static xdata uint16_t EscLongNum=0,DmxMark=0,FlashNum=0;
		GetKeyNum = key_scan();

		DmxMark=DmxMark;
		MaxItems = MenuPoint[0].MenuCount;        //获取当前菜单的条目数
		if (GetKeyNum != NO_KEY)
		{         	//确定有功能按键被按下的情况下才执行其功能
			TempDispMark = 0;
			pSEG=&SEGMenu_Buf;
			BackLightNum=1;
			FlashNum=1;
			DmxMark=0;
			if(LCDDisplight == 0){
				MenuShow();
				SystemNum=1;
				LCM_LIGHT_ON ;
				return ;
			}
			LCM_LIGHT_ON ;
			SystemNum=1;
			switch (GetKeyNum)
			{
				case Up|KEY_UP:	        
					   if(!MenuAddDec(1)){
					    UserChoose--;			//用户菜单的选择
					    if(UserChoose < 0)
					      {
						    UserChoose = MaxItems - 1;
						  }
					    }  
					break;
				case Down|KEY_UP:
				       if(!MenuAddDec(0)){
					    UserChoose++;
					    if(UserChoose == MaxItems)
					      {
						   UserChoose = 0;
					      }
					   }
					break;
				case UpLONG: 
				    if(KeyUPMark){
				      if(!MenuAddDec(1))
					  {
					   	return ;
					  }
					}
					else{
					   return ;
					}
					break;
				case DownLONG:
				    if(KeyUPMark){ 
					  if(!MenuAddDec(0)){
					   	return ;
					  }
					}
					else{
					   return ;
					}
					break;
				case Enter|KEY_UP:
/**********************************************************************************************/
					
					if ((MenuPoint[UserChoose].Subs) != NullSubs){ 
		                (*MenuPoint[UserChoose].Subs)(); 		  
		            } 
					if((MenuPoint[UserChoose].FlashMark == _FlashMode)||(MenuPoint[UserChoose].FlashMark == _FlashMode1)){
					   FlashNum=0;
			           MenuPoint = MenuPoint[0].ParentMenus; 		
			           UserChoose 	 = 0; 
			           DisplayStart  = 0; 
			           MenuChoose();
					}
					else if (MenuPoint[UserChoose].ChildrenMenus != &Menu_Null){ 
		                if(MenuPoint[UserChoose].ChildrenMenus != MainMenu){
			              Menulayer_Choose();
						  if(MenuPoint[UserChoose].ChildrenMenus==Run_Children){
						    MenuDisplayStart5(SYS_State);					
						  }
						  else 
						  if(MenuPoint[UserChoose].ChildrenMenus==Chan_Children){
		 					MenuDisplayStart5_(Memory_Struct.Memory_Chan);							
						  }
//						  else if(MenuPoint[UserChoose].ChildrenMenus==Dimmer_Children){
//		 					MenuDisplayStart5(Memory_Struct.Memory_Dimmer);							
//						  }
//						  else if(MenuPoint[UserChoose].ChildrenMenus==HZ_Children){
//		 					MenuDisplayStart5(Memory_Struct.Memory_RefreshRate);							
//						  }
//						  else if(MenuPoint[UserChoose].ChildrenMenus==Smooth_Children){
//		 					MenuDisplayStart5(Memory_Struct.Memory_Smooth);							
//						  }
//						  else if(MenuPoint[UserChoose].ChildrenMenus==Nors_Children) 
//						  {
//							MenuDisplayStart2(Memory_Struct.Memory_Mode,_SlaveMode1);					
//						  }
//						  else if(MenuPoint[UserChoose].ChildrenMenus==Sond_Children){
//							MenuDisplayStart2(Memory_Struct.Memory_Soud,1);					
//						  }
						  else if(MenuPoint[UserChoose].ChildrenMenus==NoDMXStatus_Children){
		 					MenuDisplayStart5(Memory_Struct.Memory_NoDMXStatus);							
						  }
						  else if(MenuPoint[UserChoose].ChildrenMenus==LED_Children){
	   					    MenuDisplayStart2(Memory_Struct.Memory_LED,1);						
						  }
						  else{
						    MenuPoint = MenuPoint[UserChoose].ChildrenMenus; 
							UserChoose   = 0; 
		                    DisplayStart = 0; 
						  }	                
		            	}
						else{
						  MenuPoint = MenuPoint[0].ParentMenus; 			
			              UserChoose 	 = 0; 
			              DisplayStart = 0; 
			              MenuChoose(); 
						}
					}  
					if(RUN_State==RUN_Reset)return ;
					
					/*
					if ((MenuPoint[UserChoose].Subs) != NullSubs)
					{ 
		                (*MenuPoint[UserChoose].Subs)(); 		   //指向执行函数
		            } 
		            if (MenuPoint[UserChoose].ChildrenMenus != &Menu_Null)
					{ 
		                MenuPoint    = MenuPoint[UserChoose].ChildrenMenus;  //指向子菜单 
						Option		 = UserChoose;
		                UserChoose 	 = 0; 
		                DisplayStart = 0; 
		            } 
					*/
                 	break;
				case Enter|KEY_LONG:	
				    if(MenuPoint[UserChoose].ChildrenMenus == Fun_Children){
			           //Menulayer_Choose();
					   //MenuPoint = Password_Update; 			
			           //UserChoose 	 = 0; 
			           //DisplayStart  = 0; 
				    }
					else return ;
				break;
				case Esc|KEY_UP:
/*********************************************************************************************/
					if(RUN_State==RUN_AutoTest)break;
					if(MenuPoint[UserChoose].FlashMark==_FlashMode){
					   //LCM_Clr();
					}
					if (MenuPoint[0].ParentMenus != &Menu_Null){ 				 
			            MenuPoint = MenuPoint[0].ParentMenus; 		
			            UserChoose 	 = 0; 
			            DisplayStart = 0; 
			            MenuChoose();
		            }
					else{
						UserChoose++;
					    if (UserChoose == MaxItems){
						   UserChoose = 0;
					    }
					}  
                 	break;
			    case EscLONG:
					   EscLongNum=EscLongNum;
					   return ;	
			default :return ; 				
			} 

		  if(MenuPoint[0].MenuCount<UserChoose)UserChoose =0;

		  if((UserChoose <DisplayStart) || (UserChoose >(DisplayStart + (LCD1602MaxDisplaYLinE-1) ))){
			   DisplayStart = UserChoose;
			}
		   
		   MenuShow();		
		}
		
		else if((MenuPoint[UserChoose].FlashMark == _FlashMode))
		{
		  if(FlashNum++<BackMenuTime){
			 if((MenuPoint[UserChoose].FlashMark == _FlashMode)){ 		  
			  switch(DmxMark++)
		      {
		       case 20:
		       pSEG=&SEGMenu_Buf;
			   break;
		       case 40:
		       DmxMark=0;
			   pSEG=&SEGMenu_aBuf;
		       break;
		       default:break;
		      }			  
			 }
		  } 
		  else if(RUN_State==RUN_Normal){
		  	FlashNum=0;
			if (MenuPoint[0].ParentMenus != &Menu_Null){ 				 
			           MenuPoint = MenuPoint[0].ParentMenus; 		
			           UserChoose 	 = 0; 
			           DisplayStart = 0; 
			           Menulayer_Choose();
					   DisplayStart = UserChoose; 	
		    }
			else{
			  MenuPoint = MainMenu; 
			} 
			
		    if ((UserChoose <DisplayStart) || (UserChoose >(DisplayStart + (LCD1602MaxDisplaYLinE-1) ))){
			   DisplayStart = UserChoose;
			}
			//SystemShow();
			MenuShow();
		  } 		
		}
		else if(0 == Memory_Struct.Memory_LED){
		  if(BackLightNum){
		    if(BackLightNum++>BackLightTime){ //5S=20MS*
		      BackLightNum=0;
//			  if((DMX_RegStructure.DMX_SIGNAL_MARK>300)&&(SYS_StateBuf==SYS_Dmx)){LCM_LIGHT_ON;}
//			  else if((SYS_StateBuf==SYS_Dmx)&&(SYS_State==SYS_Slave)){LCM_LIGHT_ON;}
//			  else 
			  {
			  	LCM_LIGHT_OFF;
			  }
		    }
		  }	
		}
		if((SystemNum)&&(RUN_State==RUN_Normal)){
		  if(SystemNum++>BackSystemTime*2/3){			 
			 SystemNum=0;	
			 if(MenuPoint[0].MenuCount<UserChoose)UserChoose =0;

		  	 if ((UserChoose <DisplayStart) || (UserChoose >(DisplayStart + (LCD1602MaxDisplaYLinE-1) ))){
			   DisplayStart = UserChoose;
			 }
		   
		     MenuShow();
		  }
		}
		
		
}
uint8_t MainNormal(void){
	if(MenuPoint == &MainMenu){
		return 1;
	}
return 0;
}


#endif
