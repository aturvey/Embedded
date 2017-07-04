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
 *     unsigned char *array            pointer to array of unsigned char
 *     int length                     length of array
 * 
 * Returns:  
 *     void                            
 */
void print_array(unsigned char *array, int length); 


/*
 * Function: stats_min
 *
 * Description: find minimum valued element of array and return it
 *
 * Input Parameters: 
 *     unsigned char *array           pointer to array of unsigned char
 *     int length                     length of array
 * 
 * Returns:  
 *     unsigned char                  minimum value
 */
unsigned char stats_min(unsigned char *array, int length); 



/*
 * Function: stats_max
 *
 * Description: find maximum valued element of array and return it
 *
 * Input Parameters: 
 *     unsigned char *array           pointer to array of unsigned char
 *     int length                     length of array
 * 
 * Returns:  
 *     unsigned char                  maximum value
 */
unsigned char stats_max(unsigned char *array, int length); 


/*
 * Function: stats_median
 *
 * Description: calculate statistical median of array elements
 *
 * Input Parameters: 
 *     unsigned char *array           pointer to array of unsigned char
 *     int length                     length of array
 * 
 * Returns:  
 *     unsigned char                  statistical median
 */
unsigned char stats_median(unsigned char *array, int length); 


/*
 * Function: stats_mean
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
unsigned char stats_mean(unsigned char *array, int length); 

/*
 * Function: sort_array
 *
 * Description: Sort elements of array from low to high
 *
 * Input Parameters: 
 *     unsigned char *array           pointer to array of unsigned char
 *     int length                     length of array
 * 
 * Returns:  
 *     void
 */
void sort_array(unsigned char *array, int length); 

#endif /* __STATS_H__ */
