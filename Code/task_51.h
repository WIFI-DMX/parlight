#ifndef __TASK_ST__H
#define __TASK_ST__H
 //WIFI-DMX.COM
void Task_Clear(void);
void Task_Colo(void);

void Task_TempUpdate(void);
void Task_LedAutoStob(void);
void Task_LedStob(void);
void Task_LedHcl(void);
void Task_LedFade(void);
void Task_LedDMXFade(void);
void Task_Menu(void);
void Task_DMXUpdate(void);
void Task_MotoXUpdate(void);
void Task_MotoYUpdate(void);
void Task_MotoZUpdate(void);

void Task_MotoY(void);
void Task_MotoZ(void);

void SysTasksInit(void);

#endif /* __TASK__H */
