// Basic Array Operations

#include <stdio.h>

void printArray(int arr[], int n) {
    printf("The Array Elements...\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printMiddleElement(int arr[], int n) {
    printf("Middle Element : %d\n", arr[n / 2]);
}

void printOddIndices(int arr[], int n) {
    printf("The Odd Indexed Array Elements...\n");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printEvenIndices(int arr[], int n) {
    printf("The Odd Indexed Array Elements...\n");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printMappedElements(int arr[], int n, int multFactor) {
    printf("Mapped Elements for multFactor : %d\n", multFactor);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i] * multFactor);
    }
    printf("\n");
}

void printIndex(int arr[], int n, int position) {
    if (position >= 1 && position <= n) {
        printf("Element at (position : %d) => %d\n", position,
               arr[position - 1]);
    } else {
        printf("Position : %d invalid", position);
    }
}

void printNegativeNumbers(int arr[], int n) {
    int flag = 0;
    printf("Negative Numbers in Array...\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            printf("%d ", arr[i]);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("null");
    }
    printf("\n");
}

void printReversedArray(int arr[], int n) {
    printf("Reversed Array...\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Summation of array elements : %d\n", sum);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(int);

    printArray(arr, n);
    printMiddleElement(arr, n);
    printOddIndices(arr, n);
    printEvenIndices(arr, n);
    printMappedElements(arr, n, 2);
    printIndex(arr, n, 2);
    printNegativeNumbers(arr, n);
    printReversedArray(arr, n);
    summation(arr, n);

    return 0;
}