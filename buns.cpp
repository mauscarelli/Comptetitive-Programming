#include<bits/stdc++.h>
using namespace std;

int B[11];
int C[11];
int D[11];
int A[11];
int m;

int memo[1005][11]; // [massa][recheio]

int pd(int n, int r)
{
	if (n <= 0 || r == -1)	//A[0] = qtde de massa disponivel
		return 0;
	if (memo[n][r] != -1)
		return memo[n][r];
	int maxx = 0;
	
	if (r == 0)
	{
		maxx = (n/C[0])*D[0];
	}
	else
	{
		int i = 0;
		while(i*B[r] <= A[r] && i*C[r] <= n)
		{
			maxx = max(maxx, i*D[r] + pd(n - i*C[r], r - 1));
			i++;
		}
	}
	memo[n][r] = maxx;
	return maxx;
}

int main()
{
	int n;
	
	cin >> n >> m >> C[0] >> D[0];
	B[0] = 0;
	
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			memo[i][j] = -1;
	for(int i = 1; i <= m; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	cout << pd(n, m) << endl;
}
