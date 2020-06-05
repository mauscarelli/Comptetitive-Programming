#include <bits/stdc++.h>
#define MAX_V 10010
#define MAX_A 100010
using namespace std;

typedef struct
{
	int u, v, w;
} TAdj;

TAdj adj[MAX_A];
TAdj mst[MAX_A]; //armazena a MST
int p[MAX_V];
int nro_arestas, total, posMst;

void aresta(int u, int v, int w)
{
	adj[nro_arestas].u = u;
	adj[nro_arestas].v = v;
	adj[nro_arestas].w = w;
	nro_arestas++;
}

int cmp(const void *a, const void *b)
{
	TAdj *x, *y;
	x = (TAdj *)a;
	y = (TAdj *)b;
	if (x->w < y->w)
		return -1;
	if (x->w > y->w)
		return 1;
	return 0;
}

int findSet(int x)
{
	if (x != p[x])
		p[x] = findSet(p[x]);
	return p[x];
}

void kruskal()
{
	int u, v, u_set, v_set;
	posMst = 0;
	total = 0;
	for (int i = 0; i < MAX_V; i++) // todos v?rtices
		p[i] = i;
	qsort(adj, nro_arestas, sizeof(TAdj), cmp);
	for (int i = 0; i < nro_arestas; i++)
	{
		u = adj[i].u;
		v = adj[i].v;
		u_set = findSet(u);
		v_set = findSet(v);
		if (u_set != v_set)
		{
			p[v_set] = p[u_set];
			mst[posMst++] = adj[i];
			total += adj[i].w;
		}
	}
}

int main()
{
	map<string, int> c;
	int t, n, m, i, w,node;
	string u,v,s;
	cin >> t;
	while (t--)
	{
		c.clear();
        cin >> ws;
		cin >> n >> m >> ws;
		nro_arestas = 0;
		node = 0;
		for (i = 0; i < m; i++)
		{
			getline(cin,s);
            int sp=0;
            sp = s.find(' ');
            u = s.substr(0,sp);
            s.erase(0,sp+1);
            sp = s.find(' ');
            v = s.substr(0,sp);
            s.erase(0,sp+1);
            w = stoi(s);
			if(c.find(u) == c.end())
				c[u] = node++;
			if(c.find(v) == c.end())
				c[v] = node++;
			aresta(c[u],c[v] , w);
		}
		kruskal();
		cout << total << endl;
        if(t)
            cout <<endl;
	}
}