#include<bits/stdc++.h>
#define MAXV 10001

using namespace std;

vector<int> cor[MAXV];

bool find(int a,int b){
    vector<int>::iterator it;
    while(a!=b){
        it = find(cor[a].begin(),cor[a].end(),a+1);
        if(it != cor[a].end()) a++;
        else return false;
    }
    return true;
}

int main(){
    int r,c,q,a,b;
    while(cin >> r >> c >> q, r){
        for(int i=1;i<=r;i++)
            cor[i].clear();
        for(int i=0;i<c;i++){
            cin >> a >> b;
            cor[a].push_back(b);
            cor[b].push_back(a);
        }
        for(int i=0;i<q;i++){
            cin >> a >> b;
            if(find(a,b)) cout << "Y" <<endl;
            else cout << "N" << endl;
        }
        cout << "-" <<endl;
    }

    return 0;
}