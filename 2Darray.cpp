#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Edge case: If matrix is empty
    if (matrix.empty() || matrix[0].empty()) return false;

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int start = 0;
    int end = (rows * cols) - 1; // Total elements - 1
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        // The Magic Mapping: index -> [row][col]
        int rowIndex = mid / cols;
        int colIndex = mid % cols;
        int element = matrix[rowIndex][colIndex];
        
        if (element == target) {
            return true;
        }
        
        if (element < target) {
            start = mid + 1; // Look in the right half
        } else {
            end = mid - 1;   // Look in the left half
        }
    }
    return false;
}

int main() {
    // Sample 2D Matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target = 34;
    
    if (searchMatrix(matrix, target)) {
        cout << "Result: Target " << target << " found in matrix!" << endl;
    } else {
        cout << "Result: Target " << target << " not found." << endl;
    }
    
    return 0;
}