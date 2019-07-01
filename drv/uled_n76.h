#ifndef _ULED_N76_H
#define	_ULED_N76_H
 //WIFI-DMX.COM
#include "Common.h"

typedef struct
{
	uint32_t SetPosition;
	uint32_t ActualPosition;
	uint32_t err;
	uint32_t err_next;
	uint32_t err_last;
	uint32_t kp,ki,kd;
	uint32_t incrementPosition;
}p_position;

extern uint32_t p_Runposition(p_position xdata *p,uint32_t xdata position);

void LedDrive(void);

#endif
