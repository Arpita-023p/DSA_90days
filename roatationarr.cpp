#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp=arr[0];
    //there is a index 5 if i do i<5 there is a promblem so boundary shold be i<4
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
       }
        //1 will be not there the reperion of 5,5 so
        arr[n-1]=temp;
        //print arr
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        return 0;
}