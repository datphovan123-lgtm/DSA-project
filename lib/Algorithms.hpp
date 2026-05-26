#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <functional>

// Hoan doi hai phan tu
template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// =====================================================
// BUBBLE SORT
// =====================================================

// Sap xep noi bot
template <typename T, typename Comp = std::less<T>>
void bubbleSort(T arr[], int n, Comp cmp = Comp()) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cmp(arr[j + 1], arr[j])) {
                mySwap(arr[j], arr[j + 1]);
            }
        }
    }
}

// =====================================================
// SELECTION SORT
// =====================================================

// Sap xep chon
template <typename T, typename Comp = std::less<T>>
void selectionSort(T arr[], int n, Comp cmp = Comp()) {
    for (int i = 0; i < n - 1; i++) {
        int best = i;

        for (int j = i + 1; j < n; j++) {
            if (cmp(arr[j], arr[best])) {
                best = j;
            }
        }

        mySwap(arr[i], arr[best]);
    }
}

// =====================================================
// INSERTION SORT
// =====================================================

// Sap xep chen
template <typename T, typename Comp = std::less<T>>
void insertionSort(T arr[], int n, Comp cmp = Comp()) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && cmp(key, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// =====================================================
// HEAP SORT
// =====================================================

// Ham ho tro vun dong
template <typename T, typename Comp>
void heapify(T arr[], int n, int i, Comp cmp) {
    int best = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && cmp(arr[best], arr[left])) {
        best = left;
    }

    if (right < n && cmp(arr[best], arr[right])) {
        best = right;
    }

    if (best != i) {
        mySwap(arr[i], arr[best]);
        heapify(arr, n, best, cmp);
    }
}

// Sap xep vun dong
template <typename T, typename Comp = std::less<T>>
void heapSort(T arr[], int n, Comp cmp = Comp()) {

    // Tao heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, cmp);
    }

    // Dua phan tu lon nhat ve cuoi
    for (int i = n - 1; i > 0; i--) {
        mySwap(arr[0], arr[i]);
        heapify(arr, i, 0, cmp);
    }
}

// =====================================================
// QUICK SORT
// =====================================================

// Ham phan hoach cho quick sort
template <typename T, typename Comp>
int partition(T arr[], int lo, int hi, Comp cmp) {

    T pivot = arr[hi];
    int i = lo - 1;

    for (int j = lo; j < hi; j++) {

        if (cmp(arr[j], pivot)) {
            i++;
            mySwap(arr[i], arr[j]);
        }
    }

    mySwap(arr[i + 1], arr[hi]);

    return i + 1;
}

// Sap xep nhanh
template <typename T, typename Comp = std::less<T>>
void quickSort(T arr[], int lo, int hi, Comp cmp = Comp()) {

    if (lo < hi) {

        int pivotIndex = partition(arr, lo, hi, cmp);

        quickSort(arr, lo, pivotIndex - 1, cmp);
        quickSort(arr, pivotIndex + 1, hi, cmp);
    }
}

// =====================================================
// MERGE SORT
// =====================================================

// Ham tron hai mang da sap xep
template <typename T, typename Comp>
void merge(T arr[], int left, int mid, int right, Comp cmp) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {

        if (!cmp(R[j], L[i])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Ham de quy merge sort
template <typename T, typename Comp>
void mergeSortHelper(T arr[], int left, int right, Comp cmp) {

    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSortHelper(arr, left, mid, cmp);
    mergeSortHelper(arr, mid + 1, right, cmp);

    merge(arr, left, mid, right, cmp);
}

// Sap xep tron
template <typename T, typename Comp = std::less<T>>
void mergeSort(T arr[], int n, Comp cmp = Comp()) {
    mergeSortHelper(arr, 0, n - 1, cmp);
}

// =====================================================
// SEARCHING ALGORITHMS
// =====================================================

// Tim kiem tuyen tinh
template <typename T>
int linearSearch(T arr[], int n, const T& key) {

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

// Tim kiem nhi phan
template <typename T>
int binarySearch(T arr[], int n, const T& key) {

    int left = 0;
    int right = n - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

#endif