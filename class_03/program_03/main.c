// Merge Sort

#include <stdio.h>

void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int B[h + 1];

    while (i <= mid && j <= h) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++) B[k++] = A[i];
    for (; j <= h; j++) B[k++] = A[j];

    for (i = l; i <= h; i++) A[i] = B[i];
}

void MergeSort(int A[], int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
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
1
7
3
5
4
The sorted array...
1 3 4 5 7
*/