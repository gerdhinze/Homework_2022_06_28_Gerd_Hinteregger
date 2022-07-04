#include "sortalgs.h"

#include <stdio.h>
#include <stdlib.h>


//Swap Funktion
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//Bubblesort
void array_bubble_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(&data[j], &data[j + 1]);
            }
        }
    }
}

//Selection Sort
void array_selection_sort(int data[], int n)
{
    int min_idx;
 
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (int j = i+1; j < n; j++)
        {
            if (data[j] < data[min_idx])
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&data[min_idx], &data[i]);
    }
}

//Insertion Sort
void array_insertion_sort(int data[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++) 
    {
        key = data[i];
        j = i - 1;
 
        // Move elements of data[0..i-1], that are greater than key, 
        // to one position ahead of their current position 
        while (j >= 0 && data[j] > key) 
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

//Merge Sort
void merge(int data[], int l, int m, int r)
{
    printf("merge: l=%d m=%d r=%d  ", l, m, r);
    array_print(data, 6);
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays 
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; i++)
    {
        L[i] = data[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = data[m + 1 + j];
    }

    // Merge the temp arrays back into data[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            data[k] = L[i];
            i++;
        }
        else 
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[], if there are any 
    while (i < n1) 
    {
        data[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any 
    while (j < n2) 
    {
        data[k] = R[j];
        j++;
        k++;
    }
}


// l is for left index and r is right index of the sub-array of arr to be sorted 
void merge_sort(int arr[], int l, int r)
{
    if (l < r) 
    {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}


void array_merge_sort(int data[], int n)
{
    merge_sort(data, 0, n - 1);
}

//Quicksort
void quick_sort(int data[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, data[p] is now at right place 
        int pi = partition(data, low, high);
 
        // Separately sort elements before partition and after partition
        quick_sort(data, low, pi - 1);
        quick_sort(data, pi + 1, high);
    }
}

void array_quick_sort(int data[], int n)
{
    quick_sort(data, 0, n - 1);
}