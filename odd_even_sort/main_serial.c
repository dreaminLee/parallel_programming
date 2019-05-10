#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "serial_sort.h"
#include "timer.h"

/*
    output:
    <bubble_sort_time>
    <odd_even_sort_time>
*/
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: program <filename>\n");
        exit(1);
    }
    char *filename = argv[1];
    int n = 0;
    int *rand_array1 = read_rand_array_from_file(filename, &n);
    int *rand_array1_copy1 = create_array(n);
    copy_array(rand_array1, rand_array1_copy1, n);
    int *rand_array1_copy2 = create_array(n);
    copy_array(rand_array1, rand_array1_copy2, n);

    double start, finish;
    GET_TIME(start);
    bubble_sort(rand_array1_copy1, n);
    GET_TIME(finish);
    printf("%f\n", finish - start);

    GET_TIME(start);
    odd_even_sort(rand_array1_copy2, n);
    GET_TIME(finish);
    printf("%f\n", finish - start);

    free(rand_array1);
    free(rand_array1_copy1);
    free(rand_array1_copy2);
    return 0;
}
