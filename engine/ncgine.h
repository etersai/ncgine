#ifndef NCGINE_H_
#define NCGINE_H_

#include <stdbool.h>

typedef struct {
    
    bool running;

    double (*ncgine_get_time)(void);
//    void (*draw_char)(int x, int y, char c);  

} NCgine;

int ncgine_init(NCgine* ncgine);



#endif /*NCGINE_H_*/
