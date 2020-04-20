#include<bits/stdc++.h>

using namespace std;


int main(){

    int t,n,s,e,m;
    vector<pair<int,int> > at;
    cin >> t;
    while(t--){
        m=0;
        at.clear();
        cin >> n;
        for(int i=0; i<n;i++){
            cin >> s >> e;
            at.push_back(make_pair(e,s));
        }
        sort(at.begin(),at.end());
        e=0;
        for(int i=0; i<n;i++){
            if(at[i].second >= e){
                m++;
                e= at[i].first;
            }
        }
        cout << m <<endl;
    }
    return 0;
}