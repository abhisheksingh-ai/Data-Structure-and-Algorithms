// yaha mid , quotient ki tarah behave kar rha hai baki if(divisor* mid <= dividend){ store the answer ans = mid, or aage jao} ye important hai


#include<iostream>
using namespace std;

double quotientWithoutPrecision(int dividend,int divisor){
    int s = 0;
    int e = dividend;
    int ans = -1;

    while(s <= e){
        int mid = s + ( e -s)/2;

        if(divisor* mid <= dividend){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
    }
    return ans;
        
}

double myQuotientWithPrecision(int dividend,int divisor){
    int precision = 4;
    double step =0.1;
    double quotient = quotientWithoutPrecision(dividend,divisor);

    for(int i = 0 ; i < precision; i++){
        double j = quotient;

        while(divisor * j <= dividend){
            quotient = j;
            j+= step;
        }
        step /=10;
    }

    return quotient;
}

int main(){

    int dividend = 29;
    int divisor = 7;

    double ans = myQuotientWithPrecision(dividend,divisor);

    cout<<"29/7 is: "<<ans<<endl;

    return 0;
}