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
 * @brief Function declerations.
 *
 * This file describes all the functions needed in stats.c for the assignment. 
 *
 * @author Madhav Gentela
 * @date 02/13/2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief print_staticstics()
 *
 * Prints the given statistics to the screen
 *
 * @param meanValue Mean Value of the data array
 * @param medianValue Median Value of the data array
 * @param maxValue Maximum Value of the data array
 * @param minValue Minimum Value of the data array
 *
 * @return None
 */
void print_statistics(unsigned char meanValue, unsigned char medianValue, unsigned char minValue, unsigned char maxValue);

/**
 * @brief print_array()
 *
 * Prints the data in the array.
 *
 * @param data Input data array
 * @param SIZE Input data array size
 *
 * @return None
 */
void print_array(unsigned char *data, unsigned int size);

/**
 * @brief find_median()
 *
 * Find Median Value of the input data array (expects sorted data)
 *
 * @param data Input data array
 * @param SIZE Input data array size
 *
 * @return medianValue Return Median Value
 */
unsigned char find_median(unsigned char *sorted_data, unsigned int size);

/**
 * @brief find_mean()
 *
 * Find Mean Value of the input data array
 *
 * @param data Input data array
 * @param SIZE Input data array size
 *
 * @return meanValue Return Mean Value
 */
unsigned char find_mean(unsigned char *data, unsigned int size);

/**
 * @brief find_maximum()
 *
 * Find Maximum Value of the input data array
 *
 * @param data Input data array
 * @param SIZE Input data array size
 *
 * @return maxValue Return Maximum Value
 */
unsigned char find_maximum(unsigned char *data, unsigned int size);

/**
 * @brief find_minimum()
 *
 * Find Minimum Value of the input data array
 *
 * @param data Input data array
 * @param SIZE Input data array size
 *
 * @return minValue Return Minimum Value
 */
unsigned char find_minimum(unsigned char *data, unsigned int size);

/**
 * @brief sort_array()
 *
 * Sorts the data in the array from large to small
 *
 * @param data Input data array
 * @param SIZE Input data array size
 *
 * @return SortedData Return Median Value
 */
void sort_array(unsigned char *data, unsigned int size);

#endif /* __STATS_H__ */
