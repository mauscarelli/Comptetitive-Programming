#include <bits/stdc++.h>
 
 
using namespace std;
#define MAX_V 105
#define MAXN 8000
#define INF 19203192
typedef vector<int> vi;
 
int row[MAX_V], col[MAX_V];
int used_row[MAX_V], used_col[MAX_V];
int t;
int no;
int res[MAXN][MAXN];
int vis[MAXN];
 
 
int dfs(int u, int flow)
{
	if (u == t) return flow;
	
	vis[u] = 1;
	
	for (int v = 0; v < no; ++v)
	{
		int &w = res[u][v];		
		if (w > 0 && !vis[v])
		{
			int f = dfs(v, min(flow, w));
			if (f > 0)
			{
				w -= f;
				res[v][u] += f;
				return f;
			}
		}
	}
	return 0;
}
int maxFlow()
{
	t = 1;
	int acc = 0;
	for (int f = 0;;)
	{
		memset(vis, 0, sizeof vis);
		f = dfs(0, INF);
		if (f == 0) return acc;
		acc += f;
	}
}
 
int main()
{	
	int n;
	char c;
	
	while (scanf("%d", &n) != EOF)
	{
		memset(res, 0, sizeof res);
		memset(used_row, 0, sizeof used_row);
		memset(used_col, 0, sizeof used_col);
		no = 2;
		
		for (int i = 0 ; i < n ; ++i) row[i] = no++, col[i] = no++;
		
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < n ; ++j)
			{
				scanf(" %c", &c);
				
				if (c == 'X')
				{
					if (used_row[i]) row[i] = no++;
					if (used_col[j]) col[j] = no++;
				}
				else
				{
					used_row[i] = used_col[j] = 1;
					res[0][row[i]] = 1;
					res[row[i]][col[j]] = 1;
					res[col[j]][1] = 1;
				}
			}
		}		
		int mf = maxFlow();
		printf("%dn", mf);
	}
}