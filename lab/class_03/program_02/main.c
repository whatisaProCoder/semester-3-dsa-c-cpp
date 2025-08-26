// Quicksort Sort (Wrong)

#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int l, int h) {
  int pivot = arr[l];
  int i = l, j = h;

  do {
    do {
      i++;
    } while (arr[i] <= pivot);
    do {
      j--;
    } while (arr[j] > pivot);

    if (i < j) swap(&arr[i], &arr[j]);
  } while (i < j);

  swap(&arr[l], &arr[j]);
  return j;
}

void QuickSort(int arr[], int l, int h) {
  int j;
  if (l < h) {
    j = partition(arr, l, h);
    QuickSort(arr, l, j);
    QuickSort(arr, j + 1, h);
  }
}

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
  QuickSort(arr, 0, n - 1);
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