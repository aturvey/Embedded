/*
 * stats.c
 *
 * Embedded programming course, week 1 exercise. Calculate statistics of an array
 * of small integers.
 *
 * Author: Anthony Turvey
 * Date:   Sunday Jun 18, 2017
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


unsigned char mean; 
int i;


void main() {

    unsigned char my_array[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                    114, 88,   45,  76, 123,  87,  25,  23,
                                    200, 122, 150, 90,   92,  87, 177, 244,
                                    201,   6,  12,  60,   8,   2,   5,  67,
                                      7,  87, 250, 230,  99,   3, 100,  90};

    print_array(my_array,SIZE);
    printf("  main: find_mean returned %d\n", find_mean(my_array,SIZE));

}


unsigned char find_mean(unsigned char *array, int length) { 
  
    // forget overflow  checking for today
    int sum = 0;
    float mean;

    for ( i=0; i<length; ++i) 
        sum += array[i];

    printf("  find_mean: max index finished at %d\n", i);
    printf("  find_mean: sum was %d\n", sum);

    mean = (float)sum / (float)i;

    printf("  find_mean: calculated mean was %f\n", mean);

    return( (unsigned char)mean );

}

void print_array(unsigned char *array, int length) {

    int i;

    printf("\n");

    // forget about bounds checking... it is Sunday after all
    for ( i=0; i<length; ++i ) {
        printf("  Index: %03d    %03d\n", i, array[i]);
    }

    printf("Array Length: %03d\n\n", i+1);

}
