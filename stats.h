/*
 * stats.h
 *
 * Function declarations for embedded programming course, week 1 exercise
 *
 *
 * Author: Anthony Turvey
 * Date:   Sunday Jun 18, 2017
 *
 */

#ifndef __STATS_H__
#define __STATS_H__


/*
 * Function: print_array  
 *
 * Description: provide formatted output of an unsigned char array
 *
 * Input Parameters: 
 *     unsigned char *array           pointer to array of unsigned char
 *     int length                     length of array
 * 
 * Returns:  
 *     void                            
 */
void print_array(unsigned char *array, int length); 


/*
 * Function: find_mean
 *
 * Description: calculate statistical mean of array elements
 *
 * Input Parameters: 
 *     unsigned char *array           pointer to array of unsigned char
 *     int length                     length of array
 * 
 * Returns:  
 *     unsigned char                  statistical mean
 */
unsigned char find_mean(unsigned char *array, int length); 


#endif /* __STATS_H__ */
