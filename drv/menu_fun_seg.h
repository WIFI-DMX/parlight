#ifndef	_Menu_FUN_H_
#define _Menu_FUN_H_
#include "config.h"
 //WIFI-DMX.COM
typedef enum
{
	_SlaveMode1	  =((uint8_t)0),
	_SlaveMode2	  =((uint8_t)1),
}Mode_Type;
typedef enum
{
	_StaticMode	  =((uint8_t)0),
	_FlashMode	  =((uint8_t)1),
	_FlashMode1	  =((uint8_t)2),
}Menu_Type;
typedef enum
{
	_Chinese	  =((uint8_t)0),
	_English	  =((uint8_t)1),
}Language_Type;
typedef enum
{
	_Normal	      =((uint8_t)0),
	_Rotate180	  =((uint8_t)1),
	_Auto_On  	  =((uint8_t)2),
	_Auto_Off  	  =((uint8_t)3),
}Rota_Type;
/********************************************************************************************************/
//菜单类型：正常菜单，选项型菜单（返回一数值），显示信息型菜单（显示一定信息）
typedef enum
{
	_MenuDataUpdate_None    =(uint8_t)0, 
	_MenuDataUpdate_Addr	=(uint8_t)1,
	_MenuDataUpdate_Hcl	    =(uint8_t)2,
	_MenuDataUpdate_Stob	=(uint8_t)3,
	_MenuDataUpdate_Fade    =(uint8_t)4,
	_MenuDataUpdate_Red	    =(uint8_t)5,
	_MenuDataUpdate_Grn	    =(uint8_t)6,
	_MenuDataUpdate_Blu	    =(uint8_t)7,
	_MenuDataUpdate_Bred	=(uint8_t)8,
	_MenuDataUpdate_Bgrn	=(uint8_t)9,
	_MenuDataUpdate_Bblu	=(uint8_t)10,
	_MenuDataUpdate_Temp	=(uint8_t)11,
	_MenuDataUpdate_Ver  	=(uint8_t)12,
	_MenuDataUpdate_MotoY	=(uint8_t)13,
	_MenuDataUpdate_Whi	    =(uint8_t)14,
	_MenuDataUpdate_Yel	    =(uint8_t)15,
	_MenuDataUpdate_Sose	=(uint8_t)16,
	_MenuDataUpdate_Pan	    =(uint8_t)17,
	_MenuDataUpdate_Tilt	=(uint8_t)18,
	_MenuDataUpdate_LED 	=(uint8_t)19,
	_MenuDataUpdate_RedA	=(uint8_t)20,
	_MenuDataUpdate_GrnA	=(uint8_t)21,
	_MenuDataUpdate_BluA	=(uint8_t)22,
	_MenuDataUpdate_Zoom	=(uint8_t)23,

	_MenuDataUpdate_IP1	    =(uint8_t)24,
	_MenuDataUpdate_IP2	    =(uint8_t)25,
	_MenuDataUpdate_IP3	    =(uint8_t)26,
	_MenuDataUpdate_IP4	    =(uint8_t)27,
	_MenuDataUpdate_Mask1	=(uint8_t)28,
	_MenuDataUpdate_Mask2	=(uint8_t)29,
	_MenuDataUpdate_Mask3	=(uint8_t)30,
	_MenuDataUpdate_Mask4	=(uint8_t)31,
	_MenuDataUpdate_Net	    =(uint8_t)32,
	_MenuDataUpdate_Sub_Uni	=(uint8_t)33,
	_MenuDataUpdate_ArtAddr	=(uint8_t)34,
	_MenuDataUpdate_Purple	=(uint8_t)35,
	_MenuDataUpdate_CalibrationsRed	    =(uint8_t)36,
	_MenuDataUpdate_CalibrationsGreen	=(uint8_t)37,
	_MenuDataUpdate_Rota	            =(uint8_t)38,
	_MenuDataUpdate_CalibrationsBlue	=(uint8_t)39,
	_MenuDataUpdate_CalibrationsWhite	=(uint8_t)40,
	_MenuDataUpdate_Password		    =(uint8_t)41,
	_MenuDataUpdate_CalibrationsYellow  =(uint8_t)42,
	_MenuDataUpdate_CalibrationsPurple	=(uint8_t)43,
   
}MenuDataUpdate_Type;

typedef struct 	  //要更改的数据结构
{ 		
uint16_t
	  Memory_MoveBlack,
	  Memory_Password,
	  Memory_CalibrationsRed, //换色速度SP00~SP50
      Memory_CalibrationsGreen,
	  Memory_CalibrationsBlue,
	  Memory_CalibrationsWhite,
	  Memory_CalibrationsYellow,
	  Memory_CalibrationsPurple,

	  Memory_ArtNet,
	  Memory_Hcl, //换色速度SP00~SP50
      Memory_Stob,//频闪速度SP00~SP50
	  Memory_Fade,//渐变速度SP00~SP50
	  Memory_Mode, //工作模式 主从
	  Memory_LED,//背光
	  Memory_BACKLED,//背光
	  Memory_Sose,//声控灵敏度
	  Memory_Soud;//是否开声控
Channel_Type	  	   
	  Memory_Chan; //通道
uint16_t
      Memory_Addr,//地址码A001~A512
	  Memory_ArtAddr;//地址码A001~A512
uint8_t
	  Memory_Dimmer,
	  Memory_RefreshRate,
	  Memory_Smooth,
	  Memory_Degree,
	  Memory_NoDMXStatus;
Language_Type
	  Memory_Language;
Rota_Type
	  Memory_Rota,
	  Memory_RAuto;
}Memory_TypeDef;

extern xdata Memory_TypeDef Memory_Struct;

typedef struct 	  //LED数据结构
{ 		
   uint8_t 
    data1,//第一位数码管显示数据
    data2,
    data3,
    data4;   
}LEDSEG_TypeDef;

extern xdata LEDSEG_TypeDef LEDMenu_Buf;
extern xdata LEDSEG_TypeDef LEDTemp_Buf;

void Update_Clear(void);
void UpdateExitMain(void);
void UpdateDmxAddress(void);
void UpdateChannel1(void);
void UpdateChannel2(void);
void UpdateChannel3(void);
//void UpdateChannel4(void);
void Update_Slave1Mode(void);
//void Update_Slave2Mode(void);
void Update_SoundOn(void);
void Update_ResetYes(void);
void Update_ResetNo(void);
void Update_FactoryYes(void);
void Update_FactoryNo(void);
//void Update_PanInverseYes(void);
//void Update_PanInverseNo(void);
//void Update_TiltInverseYes(void);
//void Update_TiltInverseNo(void);
void Update_NoDMXStatusClose(void);
void Update_NoDMXStatusHold(void);
//void Update_NoDMXStatusAuto(void);
//void Update_NoDMXStatusSound(void);
//void Update_FeedbackYes(void);
//void Update_FeedbackNo(void);
//void Update_Dimmer0(void);
//void Update_Dimmer1(void);
//void Update_Dimmer2(void);
//void Update_Dimmer3(void);
//void Update_RefreshRate0(void);
//void Update_RefreshRate1(void);
//void Update_RefreshRate2(void);
//void Update_RefreshRate3(void);
//void Update_Smooth0(void);
//void Update_Smooth1(void);
//void Update_Smooth2(void);
//void Update_Degree1(void);
//void Update_Degree2(void);
//void Update_Chinese(void);
//void Update_English(void);
//void Update_RotaN(void);
//void Update_RotaR(void);
//void Update_RotaA(void);
//void Update_SoundOff(void);
void Update_SoundSose(void);
void Update_BackLEDOn(void);
void Update_BackLED(void);
void Update_BackLEDOff(void);
void Update_ManuFunction(void);
void Update_CalibrationsDefaultFunction(void);
void Enter_AddrFunction(void);
void Enter_ManuFunction(void);
void Enter_AutoFunction(void);
void Update_AutoHclFunction(void);
void Update_AutoFadeFunction(void);

#endif
