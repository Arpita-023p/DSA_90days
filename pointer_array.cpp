#include<iostream>
using namespace std;
int main(){
    int arr[10]={2,4,5,6};
    cout<<"address of first memory block "<<arr<<endl;
     cout<<"address of first memory block "<<&arr[0]<<endl;
     cout<<"address of first memory block "<<(*arr)<<endl;
     cout<<"5th index is "<<*arr+1<<endl;
     cout<<"6th index is "<<(*arr+1)<<endl;
     cout<<"7th index is "<<(*arr)+3<<endl;


     int temp[10]={1,3,4};
     cout<<sizeof(temp)<<endl;
     cout<<"1st "<<sizeof(*temp)<<endl;
     cout<<"2nd "<<sizeof(&temp)<<endl;

     int *ptr=&temp[0];
     cout<<"3rd "<<sizeof(ptr)<<endl;
     cout<<"4th "<<sizeof(*ptr)<<endl;
     cout<<"4th "<<sizeof(&ptr)<<endl;

     return 0;
}