#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n) {
    // i tracks the number of passes
    for(int i = 1; i < n; i++) {
        // j compares adjacent elements
        // As i increases, the end of the array gets sorted, so we check fewer elements
        for(int j = 0; j < n - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // 1. Initialize the vector with test data
    vector<int> arr = {10, 1, 7, 6, 14, 9};
    int n = arr.size();

    cout << "Before Sorting: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2. Call the function
    bubbleSort(arr, n);

    // 3. Print the sorted results
    cout << "After Bubble Sort: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}