#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;     // store the index
            end = mid - 1; // keep looking left for the first occurance
        }
        else if (arr[mid] < key)
        {
            end = mid - 1; // go left
        }
        else
        {
            start = mid + 1; // go right
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int even[7] = {0, 0, 1, 1, 2, 2, 2}; // the array should be sorted order
    int result = firstOcc(even, 7, 1);
    cout << "The first occuarance of 1 at the index of " << result << endl;

    int result2 = lastOcc(even, 7, 2);
    cout << "The last ocuurance of 2 at in the index of " << result2 << endl;

    return 0;
}