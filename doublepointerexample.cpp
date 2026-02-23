#include<iostream>
using namespace std;
//  int main()
//     {
//         // float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
//         // float *ptr1 = &arr[0];
//         // float *ptr2 = ptr1 + 3;
//         // cout<<*ptr2<<" ";
//         // cout<< ptr2 - ptr1;

//         char st[] = "ABCD";
//         for(int i = 0; st[i] != '/0'; i++) {
//             cout << st[i] << *(st)+i << *(i+st) << i[st];
//         }
 int f(int x, int *py, int **ppz) {
        int y, z;
        **ppz += 1;
        z = **ppz;
        *py += 2;
        y = *py;
        x += 3;
        return x + y + z;
        
    }