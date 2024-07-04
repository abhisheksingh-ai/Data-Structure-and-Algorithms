#include<iostream>
#include<algorithm>
using namespace std;

int lower_bound(int arr[], int size, int target){
    /*Lower bound:- Smalllest Index that satisfy arr[index] >= target.  Target is that
    value, for which we are trying to find lower bound
    */

   int ans = size; //default answer of lower bound is size of array 

   int start = 0;
   int end = size-1;
   int index = start + (end - start)/2;

   while(start <= end){
        if(arr[index] >= target){
            ans = index; //store and check for lower if possible
            end = index - 1;
        }else{
            start = index + 1;
        }
        index = start + (end - start)/2;
    }//O(log(N)) Time Complexity
    return ans;
}

int main(){
    int arr[]={15,30,30,50,60,71,72,74,80,96};
    int size = 10;
    int target = 30;
    int ans = lower_bound(arr,size,target);
    cout<<"Lower bound for element "<<target<<": "<<ans<<endl;
    return 0;
}