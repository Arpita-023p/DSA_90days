#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={12, 5, 6, 4, 289, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int minval=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
           if(arr[i]<minval){
            minval=arr[i];
           }
        }
    }
    if(minval==INT_MAX){
        cout<<"No odd number found "<<endl;
    }
    else{
        cout<<"smallest odd number is "<<minval<<endl;
    }
    return 0;
}