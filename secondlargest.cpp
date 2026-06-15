#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={10,30,25};
    int n=sizeof(arr)/sizeof(arr[0]);
    int largest=INT_MIN;
    int secondlargest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondlargest=largest;
            largest=arr[i];
        }
        if(arr[i]>secondlargest && arr[i]!=largest){
            secondlargest=arr[i];
        }
    }
    cout<<"The second largest number is "<<secondlargest<<endl;
    return 0;

}