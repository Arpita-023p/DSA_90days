#include <iostream>
using namespace std;
void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int minArrayIndex = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[minArrayIndex++];
    }
     minArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[minArrayIndex++];
    }
    // merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    minArrayIndex = start;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[minArrayIndex++] = first[index1++];
        }
        else
        {
            arr[minArrayIndex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[minArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[minArrayIndex++] = second[index2++];
    }
}
void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    // sort the left part
    mergeSort(arr, start, mid);
    // sort the right part

    mergeSort(arr, mid + 1, end);
    // merge
    merge(arr, start, end);
}
int main()
{
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;
    mergeSort(arr, 0, n - 1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}