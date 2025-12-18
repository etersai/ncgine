#include "platform.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdbool.h>
#include <assert.h>

double platform_get_time(void)
{
    static double freq = 0.0;

    if (freq == 0.0) {
        LARGE_INTEGER pf;
        if (!QueryPerformanceFrequency(&pf)) {
            assert(0 && "Installed hardware does not support a high-resolution performance counter!"); // TODO somehow handle this gracefully.
        }
        freq = pf.QuadPart;
    }

    LARGE_INTEGER pc;
    QueryPerformanceCounter(&pc);

    return (double)pc.QuadPart / freq;
}
