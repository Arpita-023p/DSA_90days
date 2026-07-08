#include<iostream>
#include<string>
using namespace std;
int main(){
  string s="go for interview";
   int n=s.length();
   string result=" ";
   for(int i=0;i<n;i++){
    if(s[i]!=' '){
        result=result+s[i];
    }
   }
    cout<<result;
return 0;
}