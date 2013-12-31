#include <stdio.h>
#include <stdlib.h>

// binary search
int search (int array[], int key, int n) 
{
  int min = 0;
  int max = n - 1;

  while (max >= min) 
    {
      int i = (min + max) / 2;
      if (key < array[i]) 
        max = i - 1;
      else if (key > array[i]) 
        min = i + 1;
      else 
        return i;
    }

  return -1;
}