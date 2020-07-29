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
 * @file stats.c
 * @brief Displays statistics for an array of data
 *
 * Analyze an array of unsigned char data items and report analytics on the 
 * maximum, minimum, mean, and median of the data set. In addition is 
 * reordered this data set from large to small. All statistics are rounded down
 * to the nearest integer. After analysis and sorting is done, the data is 
 * printed to the screen in nicely formatted presentation.
 *
 * @author Juan Perez
 * @date   2020-07-29
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  unsigned char * ptr = test;
  unsigned char median;
  unsigned char mean;
  unsigned char max;
  unsigned char min;

  // Print the original array
  printf("\t======== Original Array =======\n"); 
  print_array(ptr, SIZE);

  // Reorded array in ascending order
  sort_array(ptr, SIZE);

  // Obtain statistics
  min    = find_minimum(ptr, SIZE);
  max    = find_maximum(ptr, SIZE);
  mean   = find_mean(ptr, SIZE);
  median = find_median(ptr, SIZE);

  // Print statistics
  print_statistics(min, max, mean, median);

  // Print the ordered array to the screen
  printf( "\t========= Ordered Array =======\n" ); 
  print_array(ptr, SIZE);

}

/* Prints de array in the screen */

void print_array(unsigned char * ptr, int size) {
  for ( int i=0; i < size; i++ ) {
    if ( i == 0 )
      printf( "\t" );
    else if ( i % 8 == 0 )
      printf( "\n\t" );
    printf( "%3d ", ptr[i] );
  }
  printf( "\n" );
}

/* Prints statistics  */

void print_statistics(unsigned char minimum, unsigned char maximum, 
		      unsigned char mean, unsigned char median) {
  printf( "\n");
  printf( "\t========== Statistics =========\n");
  printf( "\t Minimum Maximum  Mean  Median\n");
  printf( "\t ======= ======= ====== ======\n");
  printf( "\t   %3d     %3d     %3d    %3d\n", minimum, maximum, mean, median );
  printf( "\n" ); 
}

/* Obtain minimum */

unsigned char find_minimum(unsigned char * ptr, int size) {
  unsigned char minimum = 0xff;
  for ( int i=0; i < size; i++ ) {
    if ( ptr[i] < minimum )
      minimum = ptr[i];
  }
  return minimum;
}

/* Obtain maximum */

unsigned char find_maximum(unsigned char * ptr, int size) {
  unsigned char maximum = 0x00;
  for ( int i=0; i < size; i++ ) {
    if ( ptr[i] > maximum )
      maximum = ptr[i];
  }
  return maximum;
}

/* Obtain mean */

unsigned char find_mean(unsigned char * ptr, int size) {
  unsigned int sum = 0;
  unsigned char mean = 0;
  for ( int i=0; i < size; i++ ) {
      sum += ptr[i];
  }
  mean = sum / size;
  return mean;
}

/* Obtain median */
//  Conventionally, the values are listed in ascending order.
//  In the case where the total number of values in a data sample is odd, the
//  median is simply the number in the middle of the list of all values. When 
//  the data sample contains an even number of values, the median is the mean 
//  of the two middle values. 

unsigned char find_median(unsigned char * ptr, int size) {
  unsigned int middle = (size / 2) - 1;
  unsigned int sum = 0;
  unsigned char median = 0;

  // Even number of values so we get two values for the calculation
  sum = ptr[middle] + ptr[middle + 1];
  median = sum / 2;
  return median;
}

/* Sort array descending */

void sort_array(unsigned char * ptr, int size) {
  unsigned char aux = 0;
    
  for ( int i = 0; i < size; i++ ) {
    for ( int j = i+1; j < size; j++ ) {
      if ( ptr[i] < ptr[j] ) {
        aux = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = aux;
      }
    }
  }
}


