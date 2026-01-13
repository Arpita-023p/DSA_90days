#include<iostream>
using namespace std;
void printArray(int arr[], int size){

}
int main(){
    int third[15]={2,6};
    int n=15;
   printArray(third,15);
   //size of the array
   int thirdSize=sizeof(third)/sizeof(int);
   cout<<"sie of array is "<<thirdSize<<endl;
   char ch[5]={'a','s','j','m','r'};
   cout<<ch[3]<<endl;
       cout<<"Printing an array"<<endl;
     for(int i=0;i<5;i++){
        cout<<ch[i]<<" ";
     }
     cout<<"printing DONE"<<endl;
       return 0;
}