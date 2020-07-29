#include <bits/stdc++.h>
using namespace std;
#define MAX_V 400005
vector<vector<pair<int, int>>> v; // aresta[no a] = {no b, indice aresta}
vector<int> aresta;				  // arestas (-1 = ponte)
int entry[MAX_V];
int low[MAX_V];
bool vis[MAX_V];
int at = 1;
vector<pair<int, int>> res;
void dfs(int no, int p)
{
	entry[no] = low[no] = at++;
	for (auto i : v[no])
	{
		if (i.first == p)
			continue;
		if (!entry[i.first])
		{
			dfs(i.first, no);
			low[no] = min(low[i.first], low[no]);
			if (low[i.first] > entry[no])
				aresta[i.second] = -1; //marca como ponte
		}
		low[no] = min(low[no], entry[i.first]);
	}
}
int dfs(int no)
{
	vis[no] = 1;
	int r = 1;
	for (auto i : v[no])
	{
		if (vis[i.first] || aresta[i.second] == -1)
			continue;
		r += dfs(i.first);
	}
	return r;
}
void solve(int no, int p)
{
	vis[no] = 1;
	for (auto i : v[no])
	{
		if (aresta[i.second] >= 1)
			continue;
		if (aresta[i.second] == -1)
		{
			aresta[i.second] = 2;
			res[i.second] = {i.first + 1, no + 1};
		}
		else
		{
			aresta[i.second] == 1;
			res[i.second] = {no + 1, i.first + 1};
		}
		if (!vis[i.first])
			solve(i.first, no);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	v.resize(n);
	aresta.resize(m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back({b - 1, i});
		v[b - 1].push_back({a - 1, i});
	}
	dfs(0, -1);
	res.resize(m);
	int t = 0, id = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		if (!vis[i] && (x = dfs(i)) > t)
		{
			t = x;
			id = i;
		}
	}
	memset(vis, 0, sizeof vis);
	solve(id, -1);
	cout << t << endl;
	for (auto i : res)
		cout << i.first << " " << i.second << endl;
}