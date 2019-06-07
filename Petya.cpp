#include<bits/stdc++.h>
#define MAX_V 10000
#define MAX_A 100000

using namespace std;
	
typedef struct{
	int u, v;
	long long int w;
} TAdj;

TAdj adj[MAX_A];
TAdj mst[MAX_A]; //armazena a MST
int p[MAX_V];
int leiteiro[MAX_V];
int nro_arestas, posMst;
long long int total;
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
			if( !(leiteiro[v_set] && leiteiro[u_set])) total += adj[i].w;
			if(leiteiro[u_set]){
				p[v_set] = p[u_set];
			}
			else 
				p[u_set] = p[v_set];
			mst[posMst++] = adj[i];
		}
	}
}

int main()
{
	int n, t, m, i, u, v,l;
	long long int w;
	cin >> t;
	for(int c=0;c<t;c++){
		cin >> n >> m;
		memset(leiteiro,0,sizeof(leiteiro));
		nro_arestas = 0;
		for(i=0;i<n;i++) {
			cin >> l;
			if(l) leiteiro[i] = 1;
		}
		for(i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			aresta(u, v, w);
		}
		kruskal();
		cout << total << endl;
	}
}
