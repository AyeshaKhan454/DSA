#include<iostream>
using namespace std;
int main()
{
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
    for(int i = 0; i < size; i++)
    {
        int minIndex = i;
        for(int j = i; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    cout<<endl<<"The sorted array is:";
    for(int k = 0; k < size; k++)
    {
        cout<<arr[k]<<" ";
    }
}
