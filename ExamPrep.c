void BubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void InsertionSort(int arr[], int n) {
  int key, j;
  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int BinarySearch(int arr[], int n, int key) {
  int l = 0, h = n - 1, m;
  while (l <= h) {
    m = (l + h) / 2;
    if (arr[m] == key) {
      return m + 1;
    } else if (arr[m] > key) {
      h = m - 1;
    } else if (arr[m] < key) {
      l = m + 1;
    }
  }
  return -1;
}

void SelectionSort(int arr[], int n) {
  int i, j, k;
  for (i = 0; i < n - 1; i++) {
    k = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[k]) k = j;
    }
    if (i != k) {
      int temp = arr[i];
      arr[i] = arr[k];
      arr[k] = temp;
    }
  }
}

// QuickSort

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void QuickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
  }
}