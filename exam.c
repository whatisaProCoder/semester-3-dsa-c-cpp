/*
[5,2,10,7,9,3,4,1]

Question 1
Take this array and perform selection sort on the left portion [index-0,3] and
insertion sort on the right portion [index-4,7]. Then merge the two parts (using
merge function from merge sort) to give the final sorted array.
*/

#include<stdio.h>

void selection_sort(int a[], int left, int right) {
    int size = right - left + 1;
    for(int i = left; i < right; i++) {
        int min_index = i;
        for(int j = i+1; j <= right; j++) {
            if(a[min_index] > a[j]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = a[min_index];
            a[min_index] = a[i];
            a[i] = temp;
        }
    }
}

void insertion_sort(int a[], int left, int right) {
    int size = right - left + 1;
    for(int i = left+1; i <= right; i++) {
        int temp = a[i];
        int j = i - 1;
        while(j >= left && a[j] > temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void merge(int a[], int left, int mid, int right) {
    int i = left;
    int j = mid;
    int size = right - left + 1;
    int b[size];
    int k = 0;
    while(i < mid && j <= right) {
        if(a[i] < a[j]) {
            b[k++] = a[i++];;
        } else {
            b[k++] = a[j++];
        }
    }
    while(i < mid) {
        b[k++] = a[i++];
    }
    while(j <= right) {
        b[k++] = a[j++];
    }
    for(int i = 0; i < size; i++) {
        a[i] = b[i];
    }
}

void display(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {5,2,10,7,9,3,4,1};

    selection_sort(a, 0, 3);
    insertion_sort(a, 4, 7);

    display(a, 8);

    merge(a, 0, 4, 7);

    display(a, 8);
}
