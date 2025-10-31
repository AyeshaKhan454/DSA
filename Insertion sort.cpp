#include <iostream>
using namespace std;

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
    cout<<endl;
    cout<<"Before:";
    for(int r = 0; r < size; r++)
    {
      cout<<arr[r]<<" ";
    }
    cout<<endl;
    int temp = 0;
    int j = 0;
    for (int i = 1; i < size; i++) {
        temp = arr[i]; 
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; 
    }
    cout << "Sorted array: ";
    for (int k = 0; k < size; k++) 
    {
        cout << arr[k] << " ";
    }
    cout << endl;
    return 0;
}
