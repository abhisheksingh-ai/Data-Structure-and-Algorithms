#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {4,2,3,1,-5,6};
    int size = 6;
    int prfxSum[size];
    int l = 2;
    int r =  4;

    prfxSum[0] = arr[0];
    for(int i=1 ; i<size; i++){
        prfxSum[i] = arr[i] + prfxSum[i-1]; 
    }

    // ?LR

    cout<<"? LR: "<<prfxSum[r] - prfxSum[l-1]<<endl;

    return 0;
}