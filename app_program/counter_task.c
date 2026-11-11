#include <tk/tkernel.h>
#include <tm/tmonitor.h>

EXPORT UW time_us(void)
{
	return in_w(TIMER_TIMERAWL);
}

EXPORT void counter_task(INT stacd, void *exinf) 
{
    (void)stacd;
    (void)exinf;

    UW start_time = time_us();
    UW counts = 0;

    while(1) {
        counts++;
        
        // Read the hardware timer
        UW current_time = time_us();
        
        // Check if 1,000,000 microseconds (1 second) have elapsed
        if (current_time - start_time >= 1000000) {
            
            tm_printf("1 second in %d ticks;\n", counts);
            
            counts = 0;
            start_time = current_time;
        }

        tk_dly_tsk(100);
    }
}