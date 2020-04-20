#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e5;
int dsu[MAX];

int find(int x){
    if(dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}

void join(int a, int b){
    int aset = find(a);
    int bset = find(b);
    if(aset != bset)
        dsu[aset] = bset;
}

int main(){
    
    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<n+1;i++){
        dsu[i]=i;
    }
    for(int i=0;i<m;i++){
        cin >> u >> v;
        
    }

    return 0;
}