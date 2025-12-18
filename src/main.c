#include "engine/ncgine.h"

#include <stdio.h>

#define log_usage(prog_name) do { fprintf(stderr, "Usage: %s <app-to-load.dll/so>", prog_name); } while (0)
#define UNUSED(arg) (void)(arg)

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    NCgine ncgine = {0};
    ncgine_init(&ncgine);
    
    double time = ncgine.platform_get_time();
    printf("[PLATFORM AGNOSTIC TIME => %f]", time);    

    return 0;
}
