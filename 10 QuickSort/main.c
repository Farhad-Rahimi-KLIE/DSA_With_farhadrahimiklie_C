#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int low, int high){
    int pivot = arr[high];
    int index = low-1;
    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivot)
        {
            index++;
            Swap(&arr[index], &arr[i]);
        }  
    }
    Swap(&arr[index+1], &arr[high]);
    return index +1; // index +1
}

void QuickSort(int arr[], int start, int end){
    if (start < end)
    {
        int Pivot = Partition(arr, start, end);
        QuickSort(arr, start, Pivot-1);
        QuickSort(arr, Pivot+1, end);
    }
}

int main(){
    int Array[] = {8, 3, 1, 7, 0, 10, 2};
    int size_of_Array = sizeof(Array) / sizeof(int);
    printf("Before Sorting \n");
    for (int i = 0; i < size_of_Array; i++)
    {
        printf("Index: %d -> Values: %d \n", i, Array[i]);
    }

    QuickSort(Array, 0, size_of_Array);

    printf("After Sorting \n");
    for (int i = 0; i < size_of_Array; i++)
    {
        printf("Index: %d -> Values: %d \n", i, Array[i]);
    }
    return 0;
}