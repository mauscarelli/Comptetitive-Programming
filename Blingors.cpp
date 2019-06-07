#include<bits/stdc++.h>
#define MAX_V 10000
#define MAX_A 300000
using namespace std;

typedef struct {
	int u,v,w;
} TAdj;

TAdj adj[MAX_A];
TAdj mst[MAX_A];
int p[MAX_V];
unsigned int total;
int posMst, nro_arestas;

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

void limpa(){
	nro_arestas = 0;
	total=0;
}

main(){
	int s, n, p ,ad, c;
	string nome;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;//scanf("%d",&s);
	while(s--){
		//cout << s <<endl;
		cin >> n;//scanf("%d",&n);
		limpa();
		for(int i=0;i<n;i++){
			//cout << i << "aaaa"<<endl;
			//fflush(stdin);
			cin >> nome;//scanf("%s",&nome);
			cin >> p; //scanf("%d",&p);
			for(int cont=0;cont<p;cont++){
				cin >> ad >> c;//scanf("%d%d",&ad,&c);
				aresta(i,ad-1,c);
			}
		}
		kruskal();
		//cout << nro_arestas << endl;
		cout << total <<endl;//printf("%u\n",total);
		//cout << "oi"<<endl;
	}
	return 0;
}
