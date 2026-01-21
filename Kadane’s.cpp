#include <iostream>
using namespace std;
int maxSubArray(int nums[], int n)
{
    int maxSum = nums[0];
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        for(int i = 0; i < n; i++) {
        currentSum += nums[i];
        if (currentSum > maxSum) maxSum = currentSum;
        if (currentSum < 0) currentSum = 0;
    }
    }
    return maxSum;
}
int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"The value is "<<maxSubArray(arr,n)<<endl;
}
