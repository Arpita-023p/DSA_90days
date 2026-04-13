class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = -1;
        int secondLargest = -1;

        for (int x : arr) {
            // If current element is larger than the largest found so far
            if (x > largest) {
                secondLargest = largest;
                largest = x;
            }
            // If current element is between largest and secondLargest
            else if (x < largest && x > secondLargest) {
                secondLargest = x;
            }
        }

        return secondLargest;
    }
};