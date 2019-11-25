#include<bits/stdc++.h>

using namespace std;

main(){
    int x,f;
    long long n;
    cin >> x;
    for(int i =0;i<x;i++){
        cin >> n;
        f = ( (long long)(sqrt(8*n + 1)) - 1)/2;
        cout << f <<endl;
    }
}

