#include <stdio.h>

#include "version.h"
#ifdef USE_PAGAN
#include "pagan.h"
#endif

int main(void)
{
    printf("Cmini version: %d.%d\n", cmini_VERSION_MAJOR, cmini_VERSION_MINOR);

#ifdef USE_PAGAN
    printf("Multiply: %d\n", mul(123, 5));
#endif
    return 0;
}
