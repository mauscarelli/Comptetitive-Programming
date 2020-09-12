#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

/*
programação dinâmica em 2d
soma máxima
*/

int dp[MAX], lin[MAX], col[MAX], r, c;

int solve(int i, int n, int *x)
{
    if (i >= n)
        return 0;
    if (dp[i])
        return dp[i];
    return dp[i] = max(x[i] + solve(i + 2, n, x), solve(i + 1, n, x));
}

int main()
{
    int m, n;
    while (scanf("%d%d",&m,&n)==2 && (n || m))
    {
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
                scanf("%d",&lin[i]);
            fill(dp,dp+n,0);
            col[j] = solve(0,n,lin);
        }
        fill(dp,dp+m,0);
        printf("%d\n",solve(0,m,col));
    }
    return 0;
}