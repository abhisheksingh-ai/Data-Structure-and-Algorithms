#include<iostream>
using namespace std;

void print(int arr[] , int size){
    for(int i= 0 ; i < size ; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort (int arr[] , int size){
    int n = size;
    for(int i=0 ; i<n;i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"printing Sorted array"<<endl;
    print(arr,size);
    cout<<endl;
}
int main(){
    
    int arr[] = {3,10,2,6,8};
    int size = 5;
    cout<<"Before Bubble Sort"<<endl;
    print(arr,size);
    bubbleSort(arr,size);
    return 0;
}