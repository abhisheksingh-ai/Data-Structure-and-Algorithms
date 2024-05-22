// We try to minimize the search space i = i * 2 ; here min(i , (n-1)) is important because if i was finding 70 then i = 16 and its not in the array


#include<iostream>
using namespace std;

int binarySearch(int a[],int s, int e, int x, int n){
    int mid = s + (e-s)/2;
    while(s<=e){
        if(a[mid]==x){
            return mid;
        }
        else if(a[mid]>x){
            e = mid -1;
        }
        else 
            s = mid + 1;
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    int a[] = {3,4,5,6,11,13,14,15,56,70};
    int n = 10;
    int target = 13;

    if(a[0]==target) return 0;
    int i=1;
    while(i<n && a[i]<=target){
        i = i * 2;
    }
    int ans =  binarySearch(a,i/2,min(i,n-1),target,n);
    cout<<"Target found at index: "<<ans<<endl;
    return 0;
}