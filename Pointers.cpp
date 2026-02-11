#include<iostream>
using namespace std;
int main(){
    int num=5;
    cout<<num<<endl;
    //print the address of the operator
    cout<<"address of opertor is "<<&num<<endl;

    int *ptr=&num;
    cout<<"value is :"<<ptr<<endl;
    cout<<"value is :"<<&ptr<<endl;
    cout<<"value is :"<<*ptr<<endl;

    double d=3.4;
    double *ptr2=&d;
     cout<<"value is :"<<ptr2<<endl;
    cout<<"value is :"<<&ptr2<<endl;
    cout<<"value is :"<<*ptr2<<endl;
    
    cout<<"Size of the interger is "<<sizeof(num)<<endl;
    cout<<"Size of the pointer is "<<sizeof(*ptr2)<<endl;

  
    int a=num;
    cout<<"a before "<<num<<endl;
    a++;
    cout<<"a after"<<num<<endl;

    int *p=&num;
    cout<<"before "<<num<<endl;
    (*p)++;
    cout<<"after "<<num<<endl;

    //copying a pointer
    int *q=p;
    cout<<p<<"-"<<q<<endl;
    cout<<*p<<" - "<<*q<<endl;
      
   
    return 0;
}
