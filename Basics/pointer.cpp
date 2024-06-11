#include<iostream>
using namespace std;

// void solve(int *p){
//     *p   = *p +  5;
// }

// int main(){
//     int a = 5;
//     solve(&a);
//     cout<<a<<endl;
//     return 0;

// }


void solve(int *p){
    *p = *p + 15;
    cout<<"inside solve wala p ka adress "<<p<<endl;
}
int main(){
    int a = 5;
    int* p = &a;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
    solve(p);
    cout<<"After:"<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
}
