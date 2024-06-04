#include<iostream>
using namespace std;

void charHasing(char arr[] , int size){
    int hashArray[25]={0};
    //mujhe char array k element ko index me convert karna hai
    for(int i=0 ; i < size; i++){
        int index = arr[i] - 'a';
        hashArray[index]++;
    }
    //yaha mera array me values aa gyi hai

    cout<<"How may times 'a' comes: "<<hashArray['a'-'a'];
    cout<<endl;
    cout<<"How may times 'y' comes: "<<hashArray['y'-'a'];
    cout<<endl;
    cout<<"How may times 'p' comes: "<<hashArray['p'-'a'];
}

int main(){
    char arr [] = {'a','e','q','a','y','e'};
    int size = 6;

    charHasing(arr, size);
    return 0;
}