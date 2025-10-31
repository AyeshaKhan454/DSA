#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct buckets {
    vector<double> bucket;
};
// Insertion sort function
void insertion_sort(vector<double>& arr, int size) {
    for (int i = 1; i < size; i++) {
        double comparison = arr[i];
        int j = i - 1;
        while (j >= 0 && comparison < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = comparison;
    }
}
// Bucket sort function
void bucket_sort(double arr[], int size) {
    double min = arr[0];
    double max = arr[0];
    
    // Find the minimum value
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Find the maximum value
    for (int j = 0; j < size; j++) {
        if (arr[j] > max) {
            max = arr[j];
        }
    }

    double range = max - min;
    int total_buckets = sqrt(size);
    total_buckets = (total_buckets <= 0) ? 1 : total_buckets;

    // Formula for bucket range
    double bucket_range = range / total_buckets;
    buckets bucket[total_buckets];

    // Distribute elements into buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = floor((arr[i] - min) / bucket_range);

        if (bucket_index == total_buckets) {
            bucket_index = total_buckets - 1;
        } else {
            bucket_index = bucket_index;
        }

        bucket[bucket_index].bucket.push_back(arr[i]);
    }

    // Display the elements in the buckets
    for (int k = 0; k < total_buckets; k++) {
        for (double element : bucket[k].bucket) {
            cout << element << " ";
        }
        cout << " " << endl;
    }
    // Combine the sorted elements back into the original array
    int j = 0;
    for (int n = 0; n < total_buckets; n++) {
        if (bucket[n].bucket.size() > 1) {
            int size = bucket[n].bucket.size();
            insertion_sort(bucket[n].bucket, size);
        }
        for (double data : bucket[n].bucket) {
            arr[j++] = data;
        }
    }
}
int main() {
    int size = 8;
    double arr[size] = {0.25, 0.36, 0.58, 0.41, 0.29, 0.22, 0.43, 0.99};
    
    // Call bucket sort
    bucket_sort(arr, size);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
