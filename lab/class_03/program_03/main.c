// Merge Sort

#include <stdio.h>

void Merge(int A[], int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;
  int B[r + 1];

  while (i <= mid && j <= r) {
    if (A[i] < A[j])
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
  }
  for (; i <= mid; i++) B[k++] = A[i];
  for (; j <= r; j++) B[k++] = A[j];

  for (i = l; i <= r; i++) A[i] = B[i];
}

void MergeSort(int A[], int l, int r) {
  int mid;
  if (l < r) {
    mid = (l + r) / 2;
    MergeSort(A, l, mid);
    MergeSort(A, mid + 1, r);
    Merge(A, l, mid, r);
  }
}

void input(int A[], int n) {
  printf("Enter the elements: \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
}

void display(int A[], int n) {
  printf("The sorted array...\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int A[n];

  input(A, n);
  MergeSort(A, 0, n - 1);
  display(A, n);

  return 0;
}

/*OUTPUT
Enter number of elements: 5
Enter the elements:
1 8 5 7 6
The sorted array...
1 5 6 7 8
*/