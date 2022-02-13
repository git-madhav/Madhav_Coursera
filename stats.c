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
 * @brief Function definitions and main.
 *
 * This file calculates the basic statistics of a given data and prints on to the screen.
 *
 * @author Madhav Gentela
 * @date 02/13/2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() 
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char meanValue, medianValue;
  unsigned char minValue, maxValue;
  unsigned char test_sorted[SIZE];
  int i;

  printf("Hello\n");
  
  /* Statistics and Printing Functions Go Here */

  /* Sort the data */
  for (i = 0; i < SIZE; i++)
      test_sorted[i] = test[i];
  sort_array(test_sorted, SIZE);
  
  /* Get median Value and send the sorted array*/
  medianValue = find_median(test_sorted, SIZE);
  
  /* Get mean Value */
  meanValue = find_mean(test, SIZE);
  
  /* Get max Value */
  maxValue = find_maximum(test, SIZE);
  
  /* Get min Value */
  minValue = find_minimum(test, SIZE);
  
  /* Print the statistical values of the data*/
  print_statistics(meanValue, medianValue, minValue, maxValue);
  
  /* Print the Data Array*/
  print_array(test, SIZE);
  
  /* Print the sorted Data Array */
  print_array(test_sorted, SIZE);

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char meanValue, unsigned char medianValue, unsigned char minValue, unsigned char maxValue)
{
    printf("Mean Value   : %u \n", meanValue);
    printf("Median Value : %u \n", medianValue);
    printf("Minimum Value: %u \n", minValue);
    printf("Maximum Value: %u \n", maxValue);
}

void print_array(unsigned char *data, unsigned int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%u \t", data[i] );
        if ((i+1)%10 == 0) printf("\n");
    }
    printf("\n");
}

unsigned char find_median(unsigned char *sorted_data, unsigned int size)
{
    float a, b;
    unsigned char medianValue;
    
    if (size <= 0)
        return 0;
    
    if (size%2 == 0 )
    {
        a = sorted_data[(size/2)-1];
        b = sorted_data[(size/2)];
        medianValue = (unsigned char) (a+b)/2.0;
    }
    else
    {
        medianValue = sorted_data[(size)/2];
    }
    return medianValue;
}

unsigned char find_mean(unsigned char *data, unsigned int size)
{
    if (size <= 0)
        return 0;
    
    float meanValue = 0;
    for(int i = 0; i < size; i++)
        meanValue += data[i];

    meanValue = meanValue / size;
    return (unsigned char) meanValue;
}

unsigned char find_maximum(unsigned char *data, unsigned int size)
{
    if (size <= 0)
        return 0;
    
    unsigned char maxValue = 0;
    for(int i = 0; i < size; i++)
    {
        if ( data[i] > maxValue )
            maxValue = data[i];
    }
    return maxValue;
}

unsigned char find_minimum(unsigned char *data, unsigned int size)
{
    if (size <= 0)
        return 255;
    
    unsigned char minValue = 255;
    for(int i = 0; i < size; i++)
    {
        if ( data[i] < minValue )
            minValue = data[i];
    }
    return minValue;
}

void sort_array(unsigned char *data, unsigned int size)
{
    unsigned char temp;
    int i;
    for(i = 1; i < size; i++)
    {
        if (data[i-1] < data[i])
        {
            temp = data[i];
            data[i] = data[i-1];
            data[i-1] = temp;
            if (i > 1)
                i = i - 2;
        }
    }
}

