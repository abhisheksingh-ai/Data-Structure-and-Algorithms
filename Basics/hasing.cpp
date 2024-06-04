#include<iostream>
using namespace std;

void hashing(int arr[] , int size){
    //pehle ek hash array banaunga , maximum number present in array k size ka 
    int hash[9]={0};

    for(int i=0 ; i < size; i++){
        hash[arr[i]]++;
    }
    // yaha tak mene prefetching kar di hai

    cout<<"Which Elemnt's ferequency you want to check"<<endl;

    cout<<"How many times 5 comes "<<hash[5];
    cout<<endl;
    cout<<"How many times 6 comes "<<hash[6];


}

int main(){
    int arr[]={1,2,5,6,1,5,9};
    //given hai array me , maximum nuber 9 hai
    int size = 7;

    hashing(arr , size );

    return 0;
}