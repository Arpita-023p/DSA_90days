class Solution {
public:
    string reverseWords(string s) {
       int n = s.size();
       int left = 0, right = n - 1;

       // 1. Remove leading and trailing spaces
       while(left <= right && s[left] == ' ') left++;
       while(left <= right && s[right] == ' ') right--;

       // 2. Clean internal multiple spaces into 'temp'
       string temp = "";
       while(left <= right){
        if(s[left] != ' '){
            temp += s[left];
        }
        else if(temp.back() != ' '){
            temp += s[left];
        }
        left++;
       }

       // 3. REVERSE THE CLEANED STRING 'temp' (not 's'!)
       reverse(temp.begin(), temp.end());

       // 4. Reverse individual words in 'temp'
       int start = 0;
       int temp_n = temp.size(); // Use the size of the cleaned string
       for(int end = 0; end <= temp_n; end++){
        if(end == temp_n || temp[end] == ' '){
           reverse(temp.begin() + start, temp.begin() + end);
            start = end + 1;
        }
       }
       return temp; // Return the cleaned and reversed string
    }
};