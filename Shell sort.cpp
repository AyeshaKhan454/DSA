#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{    
    int size;
    cout<<"Enter the size of array:";
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" elements for array:"<<endl;
    for(int k = 0; k < size; k++)
    {
        cin>>arr[k];
    }
    cout<<endl;
    cout<<"Before:";
    for(int r = 0; r < size; r++)
    {
      cout<<arr[r]<<" ";
    }
    cout<<endl;
   for(int gap = size/2 ; gap > 0; gap = gap/2)
   {
    for(int i = gap; i < size; i++)
    {
        int j = i;
        while(j >= gap && arr[j - gap] > arr[j])
        {
            swap(arr[j-gap], arr[j]);
            j -= gap;
        }
    }
   }
   cout<<"After:";
   for(int j = 0; j < size; j++)
   {
    cout<<arr[j]<<" ";
   }
}
