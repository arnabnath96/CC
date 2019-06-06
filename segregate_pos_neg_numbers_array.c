/******************************************************************
Given an unsorted array with both positive and negative elements. 
Segregate positive numbers from others i.e., move all non-positive 
numbers to left side.

IDEA : https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
*******************************************************************/

#include <stdio.h>

void swap(int *a, int *b)  
{  
    int temp;  
    temp = *a;  
    *a = *b;  
    *b = temp;  
}  

int segregate (int arr[], int size)  
{  
    int j = 0, i;  
    int zero = -1; // this stores the index of 'zero' in array
    for(i = 0; i < size; i++)  
    {  
        if (arr[i] <= 0)  
        {  
            if(arr[i] == 0)
                zero = j;
            swap(&arr[i], &arr[j]);  
            j++; // increment count of non-positive integers  
        }  
    }  
    if(zero !=-1)
    swap(&arr[0], &arr[zero]);  
    return j;  // returns the index of the occurance of first positive integer
}  

int main() {
	int arr[] = {-10, 10, 2, 0, -20};  
    int arr_size = sizeof(arr)/sizeof(arr[0]);  
    
    for(int i=0;i<arr_size;i++)
    printf(" %d ",arr[i]);
    
    int j = segregate(arr, arr_size);
    swap(&arr[0],&arr[j-1]);  // swap once again to bring 'zero' in middle of -ve and +ve integers
   
    printf("\n");

    for(int i=0;i<arr_size;i++)
    printf(" %d ",arr[i]);
    
	return 0;
}
