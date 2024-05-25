#include<iostream>
using namespace std;

int mySqrt(int n){
    int start = 0;
    int end = n;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;

        if(mid * mid <= n){
            ans = mid;
            start = mid + 1;
        }
        else{
            //range k bahar ja rha hu
            end = mid -1;
        }
    }
    return ans;
}
double myPrecision(int n){
    double sqrt = mySqrt(n);
    int precision = 5;
    double step = 0.1;

    for(int i=0 ; i < precision; ++i){
        double j = sqrt;

        while(j * j <= n){
            sqrt = j;
            j += step;
        }

        step /=10;
    }

    return sqrt;
}

int main(){
    cout<<"I want to calculate precision of 51"<<endl;
    int n = 51;
    double ans = myPrecision(n);
    cout<<"The answer is: "<<ans<<endl;
    return ans;
}