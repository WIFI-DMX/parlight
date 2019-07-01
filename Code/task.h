/*******************************************************************************/
#ifndef _TASK_H
#define _TASK_H

#define TLedStob    0
#define TLedHcl     1
#define TLedFade	2
#define TLedDMXFade	3

#define TMenu   	4
#define TDMXUpdate	5

#define TTempUpdate	6
#define TLedFading	7

#define TMotoX      7
#define TMotoY	    8
#define TMotoZ	    9


typedef enum
{
	TaskDisable  =  ((unsigned char)0),
	TaskEnable   =  !TaskDisable,
}TASK_CmdTypeDef;

typedef struct 
{
	void (*fpTask)();
	unsigned long  uiTimeCount,
                   uiTimeBuf;
}TASK; 
extern xdata TASK Task_st[];
extern void Task_Init(void); 
extern void Task_Null(void);
extern void Task_Run(TASK*p,void (*fpNull)(),volatile unsigned char *uiPriority);  
extern void Tasks_Init(TASK *pTasks,void (*fpTask)(),volatile unsigned int uiTimeCount,volatile unsigned int uiTimeBuf);
extern void Task_Cmd(TASK *pTasks,void (*fpTask)(),TASK_CmdTypeDef bTaskCmd,void (*fpNull)()); 
#endif
 //WIFI-DMX.COM
/*******************************************************************************************************
					endfile!!!
********************************************************************************************************/
