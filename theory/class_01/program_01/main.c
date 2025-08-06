// Given an array of 5 elements find the two elements which add upto a given
// number.

#include <stdio.h>

int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return 1;
        }
    }
    return 0;
}

void twoSum(int arr[], int n, int target) {
    int x, y, flag = 0;
    for (int i = 0; i < n; i++) {
        x = arr[i];
        y = target - arr[i];
        if (search(arr, n, y) && x != y) {
            printf("The two elements whose (sum : %d) => %d, %d\n", target, x,
                   y);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("No two elements exist whose sum is equal to %d.\n", target);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    twoSum(arr, n, 6);
}