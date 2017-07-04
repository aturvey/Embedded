/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "course1.h"
#include "data.h"
#include <stdio.h>
#include <stddef.h>

/* A pretty boring main file */
int main(void) {

    course1();

    /* int32_t iTest=4096, base=2; */
    /* uint8_t sTest1[40]; */
    /* uint8_t sTest2[40] = "1010"; */
    /* uint8_t digits; */
    /*  */
    /* if ( (digits = my_itoa(iTest,sTest1,base)) )  */
    /*     printf("Integer %d converted to string %s with %d digits in base %d\n", iTest, sTest1, digits, base); */
    /* else  */
    /*     printf("%s: Error, cannot do this integer to ASCII conversion\n", __func__); */
    /*  */
    /*  */
    /* printf("String %s in base %d ", sTest2, base); */
    /* digits = 4; */
    /* iTest = my_atoi(sTest2, digits, base); */
    /* printf("converted to integer %d\n", iTest); */
 
    return 0;
}

