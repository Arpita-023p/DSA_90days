class Solution {
public:
    string removeDuplicates(string s) {
      string ans="";//this will act as a stack
      for(int i=0;i<s.length();i++){
        //if the current charchater matches and the last charcher is ans
        if(ans.length()>0 && ans.back()==s[i]){
            ans.pop_back();//remove all duplicate
        }
        else{
            ans.push_back(s[i]);
        }
      } 
      return ans; 
    }
};