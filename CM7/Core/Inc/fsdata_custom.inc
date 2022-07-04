#include "fs.h"

#ifndef __FSDATA_CUSTOM_H
#define __FSDATA_CUSTOM_H
const struct fsdata_file FS_ROOT [] = {
    {
        .name=(u_char *) "/index.htm",
        .data=(u_char *) "Hello",
        .len=5,
        .next=&(FS_ROOT[1])
    },
    {
        .name=(u_char *) "/404.htm",
        .data=(u_char *) "Not found",
        .len=9
    }
};

#endif // __FSDATA_CUSTOM_H
