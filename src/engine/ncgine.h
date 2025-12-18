#ifndef NCGINE_H_
#define NCGINE_H_

#include <stdbool.h>

typedef struct {
    
    double (*platform_get_time)(void);
    // platform_load_dynamic_lib();
    
    bool running;

} NCgine;

int ncgine_init(NCgine* ncgine);


#endif /*NCGINE_H_*/
