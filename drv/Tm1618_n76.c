/**********************************************************************************/
#include "main.h"
 //WIFI-DMX.COM
xdata SEG_TypeDef SEGMenu_Buf={
		LED__,LED__,LED__,LED__,LED_PN,0,1,   
};
xdata SEG_TypeDef SEGMenu_aBuf={
		LED_off,LED_off,LED_off,LED_off,LED_PN,1,1,   
};
pSEG_TypeDef pSEG=&SEGMenu_Buf;

/* E DCBA	 HG	F
0001 1111  0011 1000
*/
uint8_t code TM1618_[][2]=
{
/*0，        1，         2，         3，        4，         5，         6，         7，         8，          9           LED_off    LED_point   */
{0x1f,0x08},{0x06,0x00},{0x1b,0x10},{0x0f,0x10},{0x06,0x18},{0x0d,0x18},{0x1d,0x18},{0x07,0x00},{0x1f,0x18},{0x0f,0x18},{0x00,0x00},{0x00,0x20},
/*A ,        u,          t           o           -           d           r           g           b,           W          S            L         */
{0x17,0x18},{0x1c,0x00},{0x18,0x18},{0x1c,0x10},{0x00,0x10},{0x1e,0x10},{0x10,0x10},{0x0f,0x18},{0x1c,0x18},{0x1E,0x08},{0x0d,0x18},{0x18,0x08},
/*C,         e           U           n           F  ,        p           I          O            h          H           N.         */
{0x19,0x08},{0x19,0x18},{0x1E,0x08},{0x14,0x10},{0x11,0x18},{0x13,0x18},{0x06,0x00},{0x1f,0x08},{0x14,0x18},{0x16,0x18},{0x17,0x08},
/*a           E           c,           N,          Y,          度*/
{0x1f,0x10},{0x19,0x18},{0x19,0x08},{0x17,0x08},{0x0E,0x18},{0x03,0x18},
}; 
//4位8段模式下，共阴数码管0-9的编码
xdata uint8_t TM1618_KEY[3]={0}; 

void TM1618_KeyInit(void){

}

/*********I2C延时***********/
void TM1618_Wait(uint8_t xdata nCount){	  
	for(; nCount != 0; nCount--);
}

/**************************************************************/
//功能：向TM1618发送8位数据
/**************************************************************/
void TM1618_Send8bit(uint8_t ByteData)
{
	uint8_t idata i;
	for(i=0;i<8;i++){
		if(ByteData&0x01){
			TM1618_DIO_SET;
		}
		else{
			TM1618_DIO_CLR;
		}
		TM1618_CLK_CLR;
		TM1618_Wait(1);
		TM1618_CLK_SET;
		ByteData=ByteData>>1;
	}
	TM1618_Wait(1);
}
/**************************************************************/
//功能：向TM1618发送命令
/**************************************************************/
void TM1618_SendCmd(uint8_t ByteData)
{
	TM1618_STB_SET;
	TM1618_Wait(10);
	TM1618_STB_CLR;
	TM1618_Wait(10);
	TM1618_Send8bit(ByteData);
	TM1618_Wait(10);
}
/**************************************************************/
//功能：读取按键值并存入KEY[]数组，从低字节开始，从低位开始
/**************************************************************/
void TM1618_ReadKey(void)
{
	uint8_t idata i,j;
	TM1618_SendCmd(0x42); 
	TM1618_DIO_SET; 
	for(j=0;j<2;j++){
		for(i=0;i<8;i++){
			TM1618_KEY[j]=TM1618_KEY[j]>>1;
			TM1618_CLK_CLR;
			TM1618_CLK_SET;
			if(TM1618_DIO_READ){
				TM1618_KEY[j]=TM1618_KEY[j]|0X80;
			}
		}
	}
	TM1618_STB_SET;
}

void TM1618_DisplayOFF(void){
	TM1618_SendCmd(0x00); 
	TM1618_SendCmd(0x40);
	TM1618_SendCmd(0xc0); 
	TM1618_Send8bit(TM1618_[LED_off][0]); 	
	TM1618_Send8bit(TM1618_[LED_off][1]);
	TM1618_Send8bit(TM1618_[LED_off][0]);
	TM1618_Send8bit(TM1618_[LED_off][1]);
	TM1618_Send8bit(TM1618_[LED_off][0]);
	TM1618_Send8bit(TM1618_[LED_off][1]);
	TM1618_Send8bit(TM1618_[LED_off][0]);
	TM1618_Send8bit(TM1618_[LED_off][1]);
	TM1618_SendCmd(0x8A); 
	TM1618_STB_SET;
}

void TM1618_Display(void){
	if(LCDDisplight == 0){
		TM1618_DisplayOFF();
		return;
	}
	TM1618_SendCmd(0x00); 
	TM1618_SendCmd(0x40);
	TM1618_SendCmd(0xc0); 
	TM1618_Send8bit(TM1618_[pSEG->data1][0]);
	if(pSEG->Point&LED_P1){
		TM1618_Send8bit(TM1618_[pSEG->data1][1]|0x20);
	}
	else{
		TM1618_Send8bit(TM1618_[pSEG->data1][1]);
	}
	TM1618_Send8bit(TM1618_[pSEG->data2][0]);
	if(pSEG->Point&LED_P2){
		TM1618_Send8bit(TM1618_[pSEG->data2][1]|0x20);
	}
	else{
		TM1618_Send8bit(TM1618_[pSEG->data2][1]);
	}
	
	TM1618_Send8bit(TM1618_[pSEG->data3][0]);
	if(pSEG->Point&LED_P3){
		TM1618_Send8bit(TM1618_[pSEG->data3][1]|0x20);
	}
	else{
		TM1618_Send8bit(TM1618_[pSEG->data3][1]);
	}
	
	TM1618_Send8bit(TM1618_[pSEG->data4][0]);
	if(pSEG->Point&LED_P4){
		TM1618_Send8bit(TM1618_[pSEG->data4][1]|0x20);
	}
	else{
		TM1618_Send8bit(TM1618_[pSEG->data4][1]);
	}	 
	
	TM1618_SendCmd(0x8A);
	TM1618_STB_SET;
}	

void TM1618_Update(uint8_t xdata ByteData1,uint8_t xdata ByteData2,uint8_t xdata ByteData3,uint8_t xdata ByteData4,uint8_t xdata ByteDataP){
	pSEG->data1=ByteData1;
	pSEG->data2=ByteData2;
	pSEG->data3=ByteData3;
	pSEG->data4=ByteData4;
	pSEG->Point=ByteDataP;

	TM1618_Display();
}

/******************* (C) COPYRIGHT 2013 *****END OF FILE****/
