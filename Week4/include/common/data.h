
/**
 * @file data.h
 * @brief Abstraction of data conversion utilities
 *
 * This header file provides an abstraction for the
 * final assessment data conversion utility functions
 *
 * @author Anthony Turvey
 * @date July 3, 2017
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base); 

#endif /* __DATA_H__ */
