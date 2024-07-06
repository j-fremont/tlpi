#include <time.h>
#include "tlpi_hdr.h"
#include "ugid_functions.h"

#define BUF_SIZE 1000

char *
currTime(const char *format)
{
    time_t t;
    size_t s;
    struct tm *tm;
    static char buf[1000];

    t = time(NULL);
    tm = localtime(&t);
    if (tm == NULL)
        return NULL;

    s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%c", tm);

    return (s == 0) ? NULL : buf;
}
