#include "ncgine.h"

#include <stddef.h>
#include <assert.h>

#include "platform/platform.h"

int ncgine_init(NCgine* ncgine)
{
    assert(ncgine != NULL && "Not expecting NULL pointer!"); 

    ncgine->platform_get_time = platform_get_time;

    return 0;
}
 


    
