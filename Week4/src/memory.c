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
#include <stdint.h>
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
    return NULL;
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length) {
    return NULL;
}

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value) {
    return NULL;
}

uint8_t *my_memzero(uint8_t *src, size_t length) {
    return NULL;
}

uint8_t *my_reverse(uint8_t *src, size_t length) {
    return NULL;
}

int32_t *reserve_words(size_t length) {
    return NULL;
}

void free_words(int32_t *src) {
}


