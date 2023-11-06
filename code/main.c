#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "get_time.c"

int main(int argc, char *argv[])
{
    int require_length;
    if (argc <= 1)
    {
        require_length = 1000000;
    }
    else
    {
        // Convert the first command-line argument to an integer
        require_length = atoi(argv[1]);
    }
    printf("the first argument argc = %d \n", argc);
    // handle command-line arguments
    double *my_array;
    // allocate memory
    my_array = (double *)malloc(require_length * sizeof(double));

    // initialize memory, measure time
    double start, end, perf, perf_M, perf_G;
    start = get_time();
    for (int i = 0; i < require_length; i++)
    {
        my_array[i] = 0.0;
    }

    // calculate bandwidth and output results
    end = get_time();
    int size;
    size = argc * sizeof(double);
    perf = size / (end - start);
    perf_M = perf / 1000;
    perf_G = perf_M / 1000;
    printf("The expected performance %f bytes/second.\n", perf);
    printf("The expected performance %f Mbytes/second.\n", perf_M);
    printf("The expected performance %f Gbytes/second.\n", perf_G);

    // free dynamically allocated memory
    free(my_array);
}