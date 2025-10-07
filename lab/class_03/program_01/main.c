// Selection Sort

#include <stdio.h>

void SelectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    if (i != minIndex) {
      int temp = arr[minIndex];
      arr[minIndex] = arr[i];
      arr[i] = temp;
    }
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
  SelectionSort(arr, n);
  display(arr, n);

  return 0;
}

/*OUTPUT
Enter number of elements: 5
Enter the elements:
1 8 3 5 6
The sorted array...
1 3 5 6 8
*/