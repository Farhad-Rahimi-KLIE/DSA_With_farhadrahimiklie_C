#include <stdio.h>

void Traversal(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    printf("Index: %d  Elements: %d \n", i, arr[i]);
  }
}

void Update(int arr[], int size, int value, int index)
{
  if (index >= 0 && index <= size - 1)
  {
    for (int i = 0; i < size; i++)
    {
      if (i == index)
      {
        arr[i] = value;
      }
    }
  }
  else
  {
    printf("Update doesn't Work Proparly \n");
  }
}

void Insert(int arr[], int *size, int value, int index)
{
  for (int i = *size; i > index; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[index] = value;
  (*size)++;
}

void Delete(int arr[], int *size, int index)
{
  for (int i = index; i < *size; i++)
  {
    arr[i] = arr[i + 1];
  }
  (*size)--;
}

int Linear_Search(int arr[], int size, int target)
{
  for (int i = 0; i < size - 1; i++)
  {
    if (arr[i] == target)
    {
      return i;
    }
  }
  return -1;
}

int Binary_Search_Iterative(int arr[], int size, int target)
{
  int start = 0, end = size - 1;

  while (start <= end)
  {
    int middle = start + (end - start) / 2;
    if (arr[middle] == target)
    {
      return middle;
    }
    else if (arr[middle] < target)
    {
      start = middle + 1;
    }
    else
    {
      end = middle - 1;
    }
  }
  return -1;
}

int Binary_Search_Recursive(int arr[], int start, int end, int target)
{
  if (start <= end)
  {
    int middle = start + (end - start) / 2;
    if (arr[middle] == target)
    {
      return middle;
    }
    else if (arr[middle] <= target)
    {
      Binary_Search_Recursive(arr, start + 1, end, target);
    }
    else
    {
      Binary_Search_Recursive(arr, start, end - 1, target);
    }
  }
  else
  {
    return -1;
  }
}

void Reverse_Array(int arr[], int size){
  int start = 0, end = size-2;

  while (start < end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
  
}

int main()
{
  int array[7] = {1, 2, 3, 4, 5, 6};
  int size = sizeof(array) / sizeof(int);
  int newElement = 100;
  int index = 2;
  int Target = 4;

  // printf("Before reverse \n");
  // Traversal(array, size);

  // Reverse_Array(array, size);

  // printf("after reverse \n");
  // Traversal(array, size);

  // int result = Binary_Search_Recursive(array, 0, size - 1, Target);
  // printf("Binary Search Recursive Result is: %d \n", result);

  // int result = Binary_Search_Iterative(array, size, Target);
  // printf("Binary Search Iterative Result is: %d \n", result);

  // int result = Linear_Search(array, size, Target);
  // printf("Linear Search Result is: %d \n", result);

  // Delete(array, &size, index);

  // Insert(array, &size, newElement, index);

  // Update(array, size, newElement, index);

  // Traversal(array, size);
  return 0;
}