#include<bits/stdc++.h>

using namespace std;

main(){
    int t, x;
    unsigned long long int money;
    while (cin >> t, t)
    {
        money = 0;
        vector<int> c(t),p(t);
        for(int i =0; i <t;i++){
            cin >> x;
            c[i] = x;
        }
        for(int i =0; i <t;i++){
            cin >> x;
            p[i] = x;
        }
        sort(c.begin(), c.end());
        sort(p.begin(),p.end(),greater<int>());
        for(int i =0;i<t;i++){
            money +=  (long long)c[i]*p[i];
        }
        cout << money <<endl;
    }
    
}