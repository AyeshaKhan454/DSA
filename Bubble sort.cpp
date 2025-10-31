#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements for array:"<<endl;
    for(int k = 0; k < n; k++)
    {
        cin>>arr[k];
    }
    cout<<endl;
    cout<<"Before:";
    for(int r = 0; r < n; r++)
    {
      cout<<arr[r]<<" ";
    }
    cout<<endl;
    int temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            }
        }
    }
    cout<<"After:";
    for(int h = 0; h < n; h++)
    {
      cout<<arr[h]<<" ";
    }
    
}