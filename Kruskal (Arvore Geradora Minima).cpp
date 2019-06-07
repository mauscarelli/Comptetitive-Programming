#include<bits/stdc++.h>
#define MAX_V 10000
#define MAX_A 100000

using namespace std;
	
typedef struct{
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
	
int cmp(const void *a, const void *b){
	TAdj *x, *y;
	x = (TAdj*)a;
	y = (TAdj*)b;
	if(x->w < y->w)
		return -1;
	if(x->w > y->w)
		return 1;
	return 0;
}
	
int findSet(int x){
	if(x != p[x])
		p[x] = findSet(p[x]);
	return p[x];
}

void kruskal(){
	int u, v, u_set, v_set;
	posMst = 0;
	total = 0;
	for(int i=0; i<MAX_V; i++) // todos v?rtices	
		p[i] = i;
	qsort(adj, nro_arestas, sizeof(TAdj), cmp);
	for(int i=0; i<nro_arestas; i++){
		u = adj[i].u; 
		v = adj[i].v;
		u_set = findSet(u);
		v_set = findSet(v);
		if(u_set != v_set){
			p[v_set] = p[u_set];
			mst[posMst++] = adj[i];
			total += adj[i].w;
		}
	}
}

int main()
{
	int n, m, i, u, v, w;
	cin >> n >> m;
	nro_arestas = 0;
	for(i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		aresta(u, v, w);
	}
	kruskal();
	cout << total << endl;
}
