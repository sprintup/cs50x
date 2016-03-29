/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 //linear search
// bool search(int value, int values[], int n)
// {
//     // TODO: implement a searching algorithm
//     // n isn't positive
//     if (n < 1)
//     return false;
    
//     // search through values
//     for (int i = 0; i < n; i++)
//     {
//         if (values[i] == value)
//         return true;
//     }
    
//     // value not found
//     return false;
// }

//binary search
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // n isn't positive
    if (n < 1)
    return false;
    
    // search through values
    /*
        while length of list > 0
        look at middle of list
        if number found, return true
        else if number higher, search left
        else if number lower, search right
    */
    printf("before: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d",values[i]);
    }
    printf("\n");
    int s = 0;
    
    while (n > 0)
    {
        /*
            i = number of numbers to sort through
            n = number left in array
            s = starting index for search
        */
        // look at middle of list
        int i = s + (n / 2);

        printf("\n s: %d | i: %d | values[i]: %d | value: %d ",s,i,values[i],value);
        
        if (values[i] == value)
        {
            printf("It matches!!");
            return true;
        }
        else if (values[i] > value) 
        {
            /*
                search left
            */ 
            printf("\n  searching left | ");
            
            //disreguard right
            int count = 0;
            for (int j = 0; j < i; j++)
            {
                count++; 
            }
            i = count / 2; 
            
            printf("n: %d | count: %d ",n,count);
        }
        else if (values[i] < value)
        {
            /*
                search right
            */ 
            printf("\n  searching right | ");
            
            //disreguard left
            int count = 0;
            for (int j = i; j < n; j++)
            {
                count++; 
            }
            s = i; 
            i = count / 2;
            
            printf("s: %d | i: %d | count: %d ",s,i,count);
        }
        n--;
    }
    
    printf("\nafter: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d",values[i]);
    }
    printf("\n");
    
    // value not found
    return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm 
    /*
        Selection Sort
            ~ iterate over every element in array
            * j = index in unsorted array
            * x = lowest number (swapper)
            * y = number at index (swapee)
    */ 
    for (int i = 0; i < n - 1; i++)
    {
        // printf("loop %d\n",i);
        int x = values[i];
        int y = values[i]; 
        int z;
        
        // find index of element with lowest number
        for (int j = i; j < n; j ++)
        {
            // printf("\n  subloop: %d | values[j]: %d | x1: %d | ",j,values[j],x);
            
        // swap element with lowest number with next index of array
            if (values[j] <= x)
            {
                x = values[j];
                z = j;
                // printf("x2: %d | z: %d",x,z);
            }
        }
        // place smallest int at index of swappee
        values[i] = x;

        // place what was there at index of swapper 
        values[z] = y;
        // printf("\nvalues[i]: %d | x3: %d | values[z]: %d | y: %d\n",values[i],x,values[z],y);
    }
    // printf("sort function: %d", values);
    
    return;
}