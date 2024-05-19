#include<iostream>
using namespace std;

void print(int arr[] , int size){
    for(int i= 0 ; i < size ; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int size){
    //task1= findMinIndex
    int n = size;
    for(int i=0 ; i < n; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[minIndex]>arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    cout<<"After sorting:- ";
    print(arr,size);
}

int main(){
    int arr[] = {44,33,55,22,11};
    int size = 5;
    cout<<"Before sorting array:- ";
    print(arr,size);
    selectionSort(arr,size);
    //Approach-> Select min index and replace with correct position
    return 0;
}