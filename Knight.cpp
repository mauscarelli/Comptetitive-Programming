#include<bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 1;
int pre[MAX];
int rp[MAX];

void build(int n){
    for(int i =1; i <=n;i++){
        pre[i] = i;
    }
}

int find(int x){
    if(pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}

void join(int x1, int x2){
    int f1 = find(x1);
    int f2 = find(x2);
    if(x1 > x2)
        pre[f2] = f1;
    else
        pre[f1] = f2;
}

int main(){

    int n,m, l,r,x;
    cin >> n >> m;
    build(n);
    memset(rp,0,sizeof(rp));
    for(int i =0; i < m;i++){
        cin >> l >> r >> x;
        if(find(l) == find(r))
            continue;
        for(int j=l;j<=r;j=find(j)+1){
            if(j == x) continue;
            if(!rp[j]) rp[j] = x;
            if(j != 1) join(j,j-1);
        }
    }
    for(int i = 1; i<n;i++)
        cout << rp[i] << " ";
    cout << rp[n] << endl;
    return 0;
}