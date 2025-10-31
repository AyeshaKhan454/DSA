#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
   int temp = a;
   a = b;
   b = temp;
}

int partition(int arr[], int st, int end)
{
     int pivot = arr[end];
     int idex = st - 1;
     for(int i = st; i < end ; i++ )
     {
        if(arr[i] <= pivot)
        {
            idex++;
            swap(arr[i], arr[idex]);
        }
     }
        idex++;
        swap(arr[end], arr[idex]);
        return idex;
}
void quick_sort(int arr[], int st, int end)
{
    if(st < end){
   int pivot_index = partition(arr, st, end);
   quick_sort(arr, 0, pivot_index - 1);
   quick_sort(arr, pivot_index + 1, end);
   }
}
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

    quick_sort(arr, 0, size);

    cout<<"After:";
    for(int r = 0; r < size; r++)
    {
      cout<<arr[r]<<" ";
    }
    cout<<endl;
}
