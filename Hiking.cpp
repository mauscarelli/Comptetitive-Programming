#include<bits/stdc++.h>
using namespace std;
int mx = 1;
int main(){
    int n,x,v;
    cin >> n >> x;
    vector<int> m;
    for(int i =0;i<n;i++){
        cin >> v; 
        m.push_back(v);
    }
    v=1;
    for(int i =0;i<n-1;i++){
        if(m[i+1]-m[i] <= x)
            v++;
        else
            v=1;
        mx = max(mx,v);
    }
    cout << mx << endl;

    return 0;
}