#include<iostream>
#include<string>
using namespace std;
int main(){
string s="interview";
int n=s.length();
int count_vowel=0;
int count_consonet=0;
for(int i=0;i<n;i++){
   if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
        count_vowel++;
    }
    else{
        count_consonet++;
    }
}
cout<<"the vowels are "<<count_vowel<<endl;
cout<<"the consonet are "<<count_consonet<<endl;
}
