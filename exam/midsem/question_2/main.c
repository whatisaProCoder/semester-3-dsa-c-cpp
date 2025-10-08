/*
Take the same array and apply quick sort. Try to find the element 8 in 
the sorted array using optimal method. If not found insert the element 
in its proper position in the sorted array.
*/

#include <stdio.h>

void swap(int a[], int index1, int index2) {
  int temp = a[index1];
  a[index1] = a[index2];
  a[index2] = temp;
}

int pivot(int a[], int pivot_index, int end_index) {
  int swap_index = pivot_index;
  for(int i = pivot_index+1; i < end_index+1; i++) {
    if (a[pivot_index] > a[i]) {
      swap_index += 1;
      swap(a, swap_index, i);
    }
  }
  swap(a, swap_index, pivot_index);
  return swap_index;
}

int* quick_sort_helper(int a[], int left, int right) {
  if(left < right) {
    int pivot_index = pivot(a, left, right);
    quick_sort_helper(a, left, pivot_index-1);
    quick_sort_helper(a, pivot_index+1, right);
  }
  return a;
}

void quick_sort(int a[], int n) {
  quick_sort_helper(a, 0, n-1);
}

int binary_search(int a[], int n, int target, int* pos) {
  int left = 0;
  int right = n-1;
  int mid;
  while(left <= right) {
    mid = (left + right) / 2;
    if(a[mid] == target) {
      return mid;
    } else if(a[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  *pos = mid;
  return -1;
}

int main() {
  int a[9] = {4, 2, 6, 5, 3, 9, 1, 7};
  int n = 8;

  quick_sort(a, n);

  int target = 8;
  int pos;
  int result = binary_search(a, n, target, &pos);

  if(result != -1) {
    printf("Element found at index %d\n", result);
  } else {
    printf("Element not found. Insert at index %d\n", pos);
    for(int i = n; i > pos; i--) {
      a[i] = a[i-1];
    }
    a[pos] = target;
    n++;
    printf("Array after insertion: ");
    for(int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  
  return 0;
}