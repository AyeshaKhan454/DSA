#include<iostream>
using namespace std;
int main()
{
    int size = 9;
    int arr[size] = {1,3,2,3,4,1,6,4,3};
    int max = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    max = max + 1;
    int arrt[max];
    for(int l = 0; l < max; l++)
    {
        arrt[l] = 0;
    }

    for(int i = 0; i < max; i++)
    {
        for(int j = 0; j < size; j++){
        if(arr[j] == i)
        {
            arrt[i]++;
        }
        }
    }
    for(int s = 1; s < max; s++)
    {
         arrt[s] = arrt[s-1] + arrt[s];
    }
    int arrf[size];
    for(int e = size - 1; e >= 0; e--)
    {
      int num = arr[e];
      arrt[num]--;
      int inx = arrt[num];
      arrf[inx] = arr[e];
    }
    for(int k = 0; k < size; k++)
    {
        cout<<arrf[k]<<" ";
    }
    
}
