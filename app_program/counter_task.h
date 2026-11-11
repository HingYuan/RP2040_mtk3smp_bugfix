#ifndef COUNTER_TASK_H
#define COUNTER_TASK_H

#include <tk/tkernel.h>

IMPORT UW time_us(void);
IMPORT void counter_task(INT stacd, void *exinf);

#endif