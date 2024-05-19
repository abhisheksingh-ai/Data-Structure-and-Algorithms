#include<iostream>
using namespace std;
void print(int arr[] , int size){
    for(int i= 0 ; i < size ; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[],int size){
    int n = size;
    for(int i=1 ; i < n ; i++){
        for(int j = i-1 ; j >= 0 ; j--){
            if(arr[j]>arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
    cout<<"After sorting(InsertionSort):- ";
    print(arr,size);
}

int main(){
    int arr[] = {3,10,2,6,8};
    int size = 5;
    cout<<"Before indertion Sort"<<endl;
    print(arr,size);
    insertionSort(arr,size);
    return 0;
}