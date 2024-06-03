#include<iostream>
using namespace std;

class Heap{
    public:

    int* arr;
    int size;
    int capacity;

    Heap(int capacity){
        arr = new int[capacity];
        this->size = 0;
        this-> capacity = capacity;
    }

    void insertInHeap(int val){
        if(size == capacity){
            cout<<"Heap Overfolw"<<endl;
        }

        size++;
        int index = size;
        arr[index] = val;

        //heapificatopn karenge to put into correct position
        while(index > 1){
            int parentkaIndex = index /2 ;

            if(arr[parentkaIndex]<arr[index]){
                swap(arr[parentkaIndex],arr[index]);
                index = parentkaIndex;
            }
            //ye case bhul gya tha
            else{
                break;
            }
        }

    }

    int deleteFromHeap(){
        int ans = arr[1]; //ye root hai ise delete karna hai return kar dunga
        arr[1] = arr[size];
        size--;

        int index = 1;
        while(index < size){
            int leftKaIndex = 2 * index;
            int rightKaIndex = 2 * index + 1;
            int largestKaIndex = index;

            //checking who is maximum among all three
            if(leftKaIndex <= size && arr[leftKaIndex]>arr[index]){
                largestKaIndex = leftKaIndex;
            }
            if(rightKaIndex <= size && arr[rightKaIndex]>arr[largestKaIndex]){ //very important
                largestKaIndex = rightKaIndex;
            }

            if(index == largestKaIndex){
                break;
            }
            else{
                swap(arr[largestKaIndex],arr[index]);
                index = largestKaIndex;
            }
        }
        return ans;
    }

    //1 based indexing
    void printHeap(){
        for(int i = 1 ; i <= size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main (){
    Heap h1(20); //here 20 is capacity
    h1.insertInHeap(10);
    h1.insertInHeap(20);
    h1.insertInHeap(5);
    h1.insertInHeap(11);
    h1.insertInHeap(6);

    // cout<<"Printig the Heap content"<<endl;
    // h1.printHeap();

    cout<<"Printing before deletion"<<endl;
    h1.printHeap();

    h1.deleteFromHeap();

    cout<<"Printing After deletion"<<endl;
    h1.printHeap();

    return 0;
}

