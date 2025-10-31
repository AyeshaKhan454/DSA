#include<iostream>
#include<string>
using namespace std;

int find_largest(int size, int arr[]) {
    int largest = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int numberofdigits(int largest) {
    int count = 0;
    while(largest > 0) {
        largest = largest / 10;
        count++;
    }
    return count;
}

int numberof0(int Tcount, int index, int arr[]) {
    int count = 0;
    int number = arr[index];
    while(number > 0) {
        number = number / 10;
        count++;
    }
    return Tcount - count;
}

string with0s(int index, int arr[], int numberof0s[]) {
    string st = to_string(arr[index]);
    while(numberof0s[index] > 0) {
        st = '0' + st;
        numberof0s[index]--;
    }
    return st;
}

void radixSort(int size, string arr2[], int TdigitCount) {
    for(int j = TdigitCount - 1; j >= 0; j--) {
        string temp[size];
        int count[10] = {0};
        
        for(int i = 0; i < size; i++) {
            //char - '0' converts into int
            count[arr2[i][j] - '0']++;
        }
        
        for(int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        for(int i = size - 1; i >= 0; i--) {
            temp[--count[arr2[i][j] - '0']] = arr2[i];
        }
        
        for(int i = 0; i < size; i++) {
            arr2[i] = temp[i];
        }
    }
}

int main() {
    int size = 10;
    int arr[size] = {15, 1, 321, 10, 802, 2, 123, 90, 109, 11};
    int largest = find_largest(size, arr);
    int TdigitCount = numberofdigits(largest);
    int numberof0s[size];
    
    for(int i = 0; i < size; i++) {
        numberof0s[i] = numberof0(TdigitCount, i, arr);
    }
    
    string arr2[size];
    for(int j = 0; j < size; j++) {
        arr2[j] = with0s(j, arr, numberof0s);
    }
    
    radixSort(size, arr2, TdigitCount);
    
    for(int j = 0; j < size; j++) {
        cout << stoi(arr2[j]) << endl;
    }
}
