class Solution {
private:
    bool checkEqual(int a[26], int b[26]) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false; // Edge case

        int count1[26] = {0};   
        for(int i = 0; i < s1.length(); i++) { // Fixed variable name
            int index = s1[i] - 'a';
            count1[index]++;
        }  

        int windowSize = s1.length(); // Fixed variable name
        int count2[26] = {0};

        // 1. Process the first window
        int i = 0;
        while(i < windowSize) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if(checkEqual(count1, count2)) return true;

        // 2. Slide the window
        while(i < s2.length()) {
            // Add new character
            int index = s2[i] - 'a';
            count2[index]++;

            // Remove old character
            char oldChar = s2[i - windowSize]; // Fixed indexing logic
            index = oldChar - 'a';
            count2[index]--;

            if(checkEqual(count1, count2)) return true;
            i++;
        }

        return false; // Moved outside the loop
    }
};