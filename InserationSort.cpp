#include<iostream>
#include<vector>
using namespace std;
void inserationSort(int n,vector<int> &arr){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}
int main(){
vector<int> arr={10,7,32,56,21,9,80};
int n=arr.size();
cout<<"Before sorting "<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
inserationSort(n,arr);
cout<<"After insetation sort "<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}