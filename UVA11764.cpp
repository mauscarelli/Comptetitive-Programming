#include<bits/stdc++.h>

using namespace std;


int main(){
    int t,n,x,last;
    cin>>t;
    for(int test=1;test<=t;test++){
        cin >> n;
        int hj = 0, lj = 0;
        last = -1;
        for(int i=0;i<n;i++){
            cin >> x;
            if(last == -1){
                last = x; continue;
            }
            if(x>last) hj++;
            else if(x<last) lj++;
            last =x;
        }
        printf("Case %d: %d %d\n",test,hj,lj);
    }

    
    return 0;
}