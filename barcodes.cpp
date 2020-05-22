#include <bits/stdc++.h>
#define MAX 51
using namespace std;

long long pd[MAX][MAX];

int main()
{

    int n, k, m;

    while (cin >> n >> k >> m)
    {
        memset(pd, 0, sizeof(pd));

        for (int i = 1; i <= n && i <= m; i++)
            pd[1][i] = 1;

        for (int b = 2; b <= k; b++)
            for (int i = b; i <= n; i++)
                for (int l = 1; l <= m && i > l; l++)
                    pd[b][i] += pd[b - 1][i - l];

        cout << pd[k][n] << endl;
    }
}