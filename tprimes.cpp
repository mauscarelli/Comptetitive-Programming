#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

set<long long> tprimes;
set<long long>::iterator it;
void Crivo(){
    bool prime[MAX];
    memset(prime,true,sizeof(prime));

    for(long long i=2;i<MAX;i++){
        if(prime[i]){
            tprimes.insert(i*i);
            
            for(long long c= i*i; c < MAX; c+=i)
                prime[c] = false;
        }
    }
}


int main(){
    Crivo();
    int n;
    long long x;
    cin >> n;
    while(n--){
        cin >> x;
        it = tprimes.find(x);
        cout << (it != tprimes.end() ? "YES": "NO") << endl;
    }
    return 0;
}