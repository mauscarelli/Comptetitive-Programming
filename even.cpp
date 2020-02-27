#include<bits/stdc++.h>

using namespace std;

main(){
    int n,a,res;
    cin >> n;
    while(n--){
        cin >> a;
        res = 0;
        if(a%2)
            res = a;
        else
            while(a){
                res = res << 1;
                res = res|(a&1);
                a = a >>1;
            }
        cout << res <<endl;
    }

}