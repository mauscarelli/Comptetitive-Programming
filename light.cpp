#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    while(cin>> n,n){
        long long s = sqrt(n);
        cout << (s*s == n ? "yes": "no") <<endl;
    }
    return 0;
}