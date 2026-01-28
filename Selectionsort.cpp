#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int>&arr) {
    int n=arr.size();
   for(int i=0;i<n-1;i++){
       int minIndex=i;
       for(int j=i+1;j<n;j++){
           if(arr[minIndex]>arr[j]){
               minIndex=j;
           }
       }
       swap(arr[minIndex],arr[i]);
   }
}
int main(){
    vector<int>arr={64,25,12,22,11};
    selectionSort(arr);
    cout<<"Sorted array: \n";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}