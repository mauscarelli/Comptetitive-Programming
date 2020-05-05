#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,m,p,x;

    while(cin >> n >> m){
        bool f;
        p = 0;

        while(n--){
            f= true;
            for(int i=0;i<m;i++){
                cin >> x;
                if(!x) f=false;
            }
            if(f) p++;
        }

        cout << p <<endl;
    }

    return 0;
}