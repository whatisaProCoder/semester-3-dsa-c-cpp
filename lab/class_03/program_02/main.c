// Quicksort Sort

#include <stdio.h>

void swap(int arr[], int index1, int index2) {
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

int pivot(int arr[], int pivotIndex, int endIndex) {
  int swapIndex = pivotIndex;
  for (int i = pivotIndex + 1; i < endIndex + 1; i++) {
    if (arr[i] < arr[pivotIndex]) {
      swapIndex += 1;
      swap(arr, i, swapIndex);
    }
  }
  swap(arr, pivotIndex, swapIndex);
  return swapIndex;
}

int* quickSortHelper(int arr[], int left, int right) {
  if (left < right) {
    int pivotIndex = pivot(arr, left, right);
    quickSortHelper(arr, left, pivotIndex - 1);
    quickSortHelper(arr, pivotIndex + 1, right);
  }
  return arr;
}

void QuickSort(int arr[], int n) { quickSortHelper(arr, 0, n - 1); }

void input(int arr[], int n) {
  printf("Enter the elements: \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
}

void display(int arr[], int n) {
  printf("The sorted array...\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[n];

  input(arr, n);
  QuickSort(arr, n);
  display(arr, n);

  return 0;
}

/*OUTPUT
Enter number of elements: 5
Enter the elements:
1 7 4 9 8
The sorted array...
1 4 7 9 8
*/