/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of
 * manipulating memory via function calls. 
 *
 * @author Anthony Turvey
 * @date July 3, 2017
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include "memory.h"

/***********************************************************
 Global Variables
***********************************************************/
char buffer[MAX_LENGTH];

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/***********************************************************
 New functions added by ATurvey for Final Assessment 
***********************************************************/
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length) {

    unsigned int i;

    if ( src < dst )
        for (i=0; i<length; i++)
            *(dst+length-i-1) = *(src+length-i-1);
    else if ( src > dst )
        for (i=0; i<length; i++)
            *(dst+i) = *(src+i);
    
    return dst;
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length) {

    unsigned int i;

    for (i=0; i<length; i++)
        *(dst+i) = *(src+i);

    return dst;
}

uint8_t *my_memset(uint8_t *dst, size_t length, uint8_t value) {

    unsigned int i;
    
    for (i=0; i<length; i++)
        *(dst+i) = value;

    return dst;
}

uint8_t *my_memzero(uint8_t *dst, size_t length) {

    unsigned int i;

    for (i=0; i<length; i++)
        *(dst+i) = 0;

    return dst;
}

uint8_t *my_reverse(uint8_t *dst, size_t length) {

    uint8_t tmp;
    uint8_t *top, *bot;

    top = dst;
    /* printf("  %s: top = %p\n", __func__, top); */
    bot = dst+length-1;
    /* printf("  %s: bot = %p\n", __func__, bot); */

    while ( bot > top ) {
        tmp = *top;
        *top = *bot;
        *bot = tmp;
        top += 1;
        bot -= 1;
    }

    return dst;
}

uint32_t *reserve_words(size_t length) {

    uint32_t *dst;

    if (( dst = malloc( length * sizeof(int32_t) ) ) == NULL ) 
        printf("%s: Error, malloc failed to allocate memory block of size %d words (%d bytes)\n", __func__, (int)length, (int)(length*sizeof(int32_t)));

    return dst;
}

void free_words(uint32_t *dst) {

    free(dst);
}



