#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

main(){
    int altura[MAX];
    int a,c,x, m,r,mini;
    while(cin >> a >> c, a && c){
        mini = INT_MAX;
        r = 0;
        for(int i =0;i<c;i++)
            cin >> altura[i];
        m = altura[0];
        int f = 0;
        for(int i = 0; i<c-1;i++){
            mini = min(mini,altura[i]);
            if(altura[i+1] > altura[i]){
                f=1;
            }else{
                if(f)
            }
        }
        //mini = min(mini,altura[c-1]);
        cout << r <<endl;
    }
}