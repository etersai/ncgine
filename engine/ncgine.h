#ifndef NCGINE_H_
#define NCGINE_H_

#include <stdbool.h>

typedef struct {
    
    // Platform
    double (*ncgine_get_time)(void);
    
    bool running;

} NCgine;

int ncgine_init(NCgine* ncgine);


#endif /*NCGINE_H_*/
