#include<iostream>
#include<queue>
using namespace std;

void solve(priority_queue<int> &maxi,priority_queue<int, vector<int>, greater<int>> &mini,int element, double &median){
    //ab hamare pas 3 case hai to make size diff between maxi and min atmost 1
    if(maxi.size()==mini.size()){
        //till now length was same but now it will be odd
        if(element>median){
            mini.push(element);
            median = mini.top();
        }
        else{
            //element < median
            maxi.push(element);
            median = maxi.top();
        }
    }
    else if(maxi.size()==mini.size()+1){
        if(element<median){
            int temp = maxi.top();
            maxi.pop();
            mini.push(temp);
            maxi.push(element);
        }
        else{
            //element>median
            mini.push(element);
        }
        median = (mini.top()+maxi.top())/2.0;
    }
    else if(mini.size()==maxi.size()+1){
        if(element>median){
            int temp = mini.top();
            mini.pop();
            maxi.push(temp);
            mini.push(element);
        }
        else{
            maxi.push(element);
        }
        median = (mini.top()+maxi.top())/2.0;
    }
}

int main(){
    int nums[] ={ 5, 13, 1, 3, 2, 8};
    int n = 6;
    double median = 0;

    //creating max heap and min heap
    priority_queue<int>maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    for(int i = 0 ; i < n; i++){
        int element = nums[i];
        solve(maxi,mini,element,median);
        cout<<"printing median "<<median<<endl;
    }
    return 0;
}