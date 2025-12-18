#include "platform.h"

#include <time.h>

double linux_get_time(void)
{
    struct timespec ts;    
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)(ts.tv_sec + ts.tv_nsec / 1e9);
}
