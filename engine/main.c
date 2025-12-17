#include "ncgine.h"

#include <stdio.h>
#include <stdlib.h>

#define log_usage(prog_name) do { fprintf(stderr, "Usage: %s <app-to-load.dll>", prog_name); } while (0)

int main(int argc, char** argv)
{
    NCgine ncg = {0};
    ncg.running = true;
    
     

    // the enginge menu it self will be an .dll
    while (ncg.running) {
        
    }

    return 0;
}
