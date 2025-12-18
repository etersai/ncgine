#ifndef NCGINE_PLATFORM_H_
#define NCGINE_PLATFORM_H_

#if defined(__linux__) 
    #pragma message("Compiling Linux platform layer")
#elif defined(_WIN32)
    #pragma message("Compiling Windows platform layer")
#else
    #error "Unsupported platform!"
#endif

double platform_get_time(void);

#endif /*NCGINE_PLATFORM_H_*/
