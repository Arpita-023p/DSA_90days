class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long original=x;
        long long  reverseNumber=0;
        while(x>0){
            int lastdigit=x%10;
            reverseNumber=(reverseNumber*10)+lastdigit;
            x=x/10;
        }
        return (original==reverseNumber);
    }
};