#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "xdoj_jc3_toplev.h"

int xdoj_jc3_toplev(int argc, char** argv)
{
    /* TODO: This is only a dummy.  */
    printf("%s: dummy.\n", argv[0]);
    execl("/usr/bin/fortune", "fortune", NULL);
    return argc;
}
