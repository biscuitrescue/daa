#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// 1. Binary Search
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l)/2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}

// 2. Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// 3. Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high-1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// 4. Maximum Subarray Sum
int maxCrossingSum(int arr[], int l, int m, int h) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++) {
        sum += arr[i];
        if (sum > right_sum) right_sum = sum;
    }

    return max({left_sum + right_sum, left_sum, right_sum});
}

int maxSubArraySum(int arr[], int l, int h) {
    if (l == h) return arr[l];
    int m = l + (h - l)/2;
    return max({maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m+1, h),
               maxCrossingSum(arr, l, m, h)});
}

int main() {
    // Binary Search
    int arr1[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int target = 23;
    cout << "Binary Search Result (0-based index): " 
         << binarySearch(arr1, 0, n1-1, target) << endl;

    // Merge Sort
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    mergeSort(arr2, 0, n2-1);
    cout << "Merge Sort Result: ";
    for (int i = 0; i < n2; i++) cout << arr2[i] << " ";
    cout << endl;

    // Quick Sort
    int arr3[] = {4, 2, 6, 9, 2};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    quickSort(arr3, 0, n3-1);
    cout << "Quick Sort Result: ";
    for (int i = 0; i < n3; i++) cout << arr3[i] << " ";
    cout << endl;

    // Maximum Subarray Sum
    int arr4[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    cout << "Maximum Subarray Sum: " 
         << maxSubArraySum(arr4, 0, n4-1) << endl;

    return 0;
}
