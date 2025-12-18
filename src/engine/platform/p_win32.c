#include "platform.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdbool.h>
#include <assert.h>

static double pc_freq = 0.0;
static bool freq_set = false;
//If a stopwatch ticks 1000 times per second, and you counted 5000 ticks, how many seconds have passed?

static inline void internal_windows_get_pc_frequency(void)
{
    if (!freq_set) {
        LARGE_INTEGER pf;
        if (!QueryPerformanceFrequency(&pf)) {
            assert(0 && "Installed hardware does not support a high-resolution performance counter!"); // TODO somehow handle this gracefully.
        }
        freq = pf.QuadPart;
        freq_set = true;
    }

}

double platform_get_time(void)
{
    LARGE_INTEGER pc;
    internal_windows_get_pc_frequency();
    QueryPerformanceCounter(&pc);
    return (double)(pc.QuadPart / pc_freq);
}


//
// void StartCounter()
// {
//     LARGE_INTEGER li;
//     if(!QueryPerformanceFrequency(&li))
//     cout << "QueryPerformanceFrequency failed!\n";
//
//     PCFreq = double(li.QuadPart)/1000.0;
//
//     QueryPerformanceCounter(&li);
//     CounterStart = li.QuadPart;
// }
// double GetCounter()
// {
//     LARGE_INTEGER li;
//     QueryPerformanceCounter(&li);
//     return double(li.QuadPart-CounterStart)/PCFreq;
// }
//
// int main()
// {
//     StartCounter();
//     Sleep(1000);
//     cout << GetCounter() <<"\n";
//     return 0;
// }
// LARGE_INTEGER freq, start, end;
// QueryPerformanceFrequency(&freq);  // get counter frequency
// QueryPerformanceCounter(&start);   // get starting counter value
//
// // ... code to measure ...
//
// QueryPerformanceCounter(&end);     // get ending counter value
// double elapsedSeconds = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
//
//
//
// // Source - https://stackoverflow.com/a
// // Posted by user152949, modified by community. See post 'Timeline' for change history
// // Retrieved 2025-12-18, License - CC BY-SA 3.0
//
// /** Use to init the clock */
// #define TIMER_INIT \
//     LARGE_INTEGER frequency; \
//     LARGE_INTEGER t1,t2; \
//     double elapsedTime; \
//     QueryPerformanceFrequency(&frequency);
//
//
// /** Use to start the performance timer */
// #define TIMER_START QueryPerformanceCounter(&t1);
//
// /** Use to stop the performance timer and output the result to the standard stream. Less verbose than \c TIMER_STOP_VERBOSE */
// #define TIMER_STOP \
//     QueryPerformanceCounter(&t2); \
//     elapsedTime=(float)(t2.QuadPart-t1.QuadPart)/frequency.QuadPart; \
//     std::wcout<<elapsedTime<<L" sec"<<endl;
//

