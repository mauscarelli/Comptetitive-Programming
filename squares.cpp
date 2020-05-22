#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

int pd[MAX];

int main(){
    int t,n;
    memset(pd,0,MAX);
    for(int i=1;i<MAX;i++){
        int s = sqrt(i);
        if(s*s == i)
            pd[i] = 1;
        else
            pd[i] = INT_MAX;
    }

    for(int i=2;i<MAX;i++){
        if(pd[i] == INT_MAX)
            for(int j=1; j*j<i;j++)
                pd[i] = min(pd[i],pd[i-j*j] + 1);
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << pd[n] << endl;
    };


    return 0;
}