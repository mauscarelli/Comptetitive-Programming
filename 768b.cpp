#include<bits/stdc++.h>

using namespace std;

int at=0, sum =0,l,r;
void divide(int n){
    if(n == 1){
        at++;
        if(at >= l && at <=r){
            sum++;
        }
    }
    else{
        divide(n/2);
        at++;
        if(n%2 == 1 && at >=l && at <= r)
            sum++;
        divide(n/2);
    }
}

int main(){
    int n;
    cin >> n >> l >> r;
    divide(n);
    cout <<sum <<endl;
    return 0;
}