#include<iostream>
#include<vector>
using namespace std;
int reverseArrr(vector<int>& arr){
int n=arr.size();
int i=0;
for(int j=1;j<n;j++){
    if(arr[i]!=arr[j]){
        i++;
        arr[i]=arr[j];
    }
    return i+1;
}
}
int main(){
   vector<int> arr={10,20,30,23,40,30};
    int uniqueelemet=reverseArrr(arr);
    cout<<"The duplicate element are "<<uniqueelemet<<endl;
    return 0;
}
