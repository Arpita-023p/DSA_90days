#include<iostream>
using namespace std;
int main(){
    int arr[]={1,0,2,3,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int resSize=0;
    //loop 1
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
           arr[resSize]=arr[i];
           resSize++;
        }
    }
    //loop 2
    for(int i=resSize;i<n;i++){
        arr[i]=0;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}