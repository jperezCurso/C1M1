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
 * @file stats.h
 * @brief Header of stats.c file
 *
 * @author Juan Perez
 * @date   2020-07-29
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints statistics of an array
 *
 * Prints the statistics of an unsigned char array including minimun, maximun,
 * mean and median.
 *
 * @param unsigned char Minimum
 * @param unsigned char Maximum
 * @param unsigned char Mean
 * @param unsigned char Median
 * @return void
 */
void print_statistics(unsigned char minimum, unsigned char maximum, 
		      unsigned char mean, unsigned char median);

/**
 * @brief Prints the array to the screen
 *
 * Given an array of data and a length, prints the array to the screen.
 *
 * @param unsigned char * The array to print.
 * @param int             The length of the array.
 * @return void
 */
void print_array(unsigned char * ptr, int size);

/**
 * @brief Returns the median value of the array
 *
 * Given an array of data and a length, returns the median value.
 *
 * @param unsigned char * The array of data.
 * @param int             The length of the array.
 * @return The median calculated
 */
unsigned char find_median(unsigned char * ptr, int size);

/**
 * @brief Returns the mean value of the array
 *
 * Given an array of data and a length, returns the mean value.
 *
 * @param unsigned char * The array of data.
 * @param int             The length of the array.
 * @return The mean calculated
 */
unsigned char find_mean(unsigned char * ptr, int size);

/**
 * @brief Returns the maximum value of the array
 *
 * Given an array of data and a length, returns the maximum value.
 *
 * @param unsigned char * The array of data.
 * @param int             The length of the array.
 * @return The maximum calculated
 */
unsigned char find_maximum(unsigned char * ptr, int size);

/**
 * @brief Returns the minimum value of the array
 *
 * Given an array of data and a length, returns the minimum value.
 *
 * @param unsigned char * The array of data.
 * @param int             The length of the array.
 * @return The minimum calculated
 */
unsigned char find_minimum(unsigned char * ptr, int size);

/**
 * @brief Sorts an array 
 *
 * Given an array of data and a length, sorts the array from largest to
 * smallest. (The zeroth element should be the largest value, and the last
 * element (n-1) should be the smallest value).
 *
 * @param unsigned char * The array of data.
 * @param int             The length of the array.
 * @return void
 */
void sort_array(unsigned char * ptr, int size);


#endif /* __STATS_H__ */
