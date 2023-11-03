#include <time.h>
#include <sys/time.h>
#include "func.h"

double get_time(void) {
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    double t = (double) a.tv_nsec / (1000.0*1000.0*1000.0) + (double) a.tv_sec;
    return t;
}
