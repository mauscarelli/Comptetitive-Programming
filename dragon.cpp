#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m,n && m){
        priority_queue<int> d;
        priority_queue<int> h;
        int c;
        for(int i=0;i<n;i++){
            cin >> c;
            d.push(-c);
        }
        for(int i=0;i<m;i++){
            cin >> c;
            h.push(-c);
        }
        long long int cost= 0;
        while(!h.empty() && !d.empty()){
            if(-h.top() >= -d.top()){
                d.pop();
                cost += -h.top();
            }
            h.pop();
        }
        if(d.size()) cout << "Loowater is doomed!" <<endl;
        else cout << cost <<endl;
    }
    return 0;
}