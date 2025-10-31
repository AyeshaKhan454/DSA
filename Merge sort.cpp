#include <iostream>
using namespace std;

// Function to merge two sorted subarrays
void merge(int arr[], int lb, int mid, int ub) {
    int n1 = mid - lb + 1; // Size of left subarray
    int n2 = ub - mid;     // Size of right subarray

    // Create temporary arrays
    int left[n1], right[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        left[i] = arr[lb + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[lb..ub]
    int i = 0, j = 0, k = lb;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left[], if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements of right[], if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void merge_sort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = lb + (ub - lb) / 2;
        merge_sort(arr, lb, mid);        // Sort first half
        merge_sort(arr, mid + 1, ub);   // Sort second half
        merge(arr, lb, mid, ub);        // Merge the two halves
    }
}

int main() {

    int size;
    cout<<"Enter the size of array:";
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" elements for array:"<<endl;
    for(int h = 0; h < size; h++)
    {
        cin>>arr[h];
    }
    cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform merge sort
    merge_sort(arr, 0, size - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
