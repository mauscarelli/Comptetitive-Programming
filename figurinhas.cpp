#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
if (a == 0)
return b;
return gcd(b % a, a);
}

int main(){
    int n, f1,f2;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> f1 >> f2;
        cout << gcd(f1,f2) <<endl;    
    }
    return 0;
}