#include<bits/stdc++.h>
#define MAX 4001
using namespace std;

int main(){

    int n;
    int c[3];
    int dp[MAX];
    memset(dp,0,sizeof(dp));
    cin >> n >> c[0] >> c[1] >> c[2];
    sort(c,c+3);
    dp[c[0]] = 1;
    dp[c[1]] = 1;
    dp[c[2]] = 1;
    int x,y,z;
    for(int i=c[0]+1;i<=n;i++){
        x = y = z =0;
        
        if(dp[i-c[0]]>0)
            x= dp[i-c[0]]+1;
        
        if(i>=c[1])
            if(dp[i-c[1]]>0)
                y = dp[i-c[1]]+1;
        
        if(i>=c[2])
            if(dp[i-c[2]]>0)
                z = dp[i-c[2]]+1;
        
        dp[i] = max(x,max(y,max(z,dp[i])));
    }
    cout << dp[n] <<endl;
}