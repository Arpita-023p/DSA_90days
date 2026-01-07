#include <iostream>
using namespace std;
long long int binarySearch(int n)
{
    long long int start = 0;
    long long int end = n;
    long long int mid = start + (end - start) / 2;
    long long int ans = -1;
    while (start <= end)
    {
        long long int square = mid * mid;
        if (mid * mid == n)
        {
            return mid;
        }
        if (mid * mid < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
double morePrecision(int n, int precision, int tempsquare)
{
    double factor = 1;
    double ans = tempsquare;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;

        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number " << endl;
    cin >> n;
    int tempsquare = binarySearch(n);
    cout << "Answer is " << morePrecision(n, 3, tempsquare) << endl;
    return 0;
}
