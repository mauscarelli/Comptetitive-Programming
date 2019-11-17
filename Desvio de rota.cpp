#include<bits/stdc++.h>
#define MAX_V 500
#define MAX_A 250000
using namespace std;

vector< pair<int,int> > envio[MAX_V]; // envio[cidade origem] <cidade destino , tempo necessario> 
int grau[MAX_V];
int d[MAX_V]; //d[i] armazena a distância até o vértice i, e as
//estimativas durante as iterações
int p[MAX_V]; //armazena o predecessor de cada vértice

void Dijkstra(int inicial, int vertices,int c){
	priority_queue< pair<int, int> > heap; //distância, vértice
 	int s, t, peso, rota;

 	for(int i = 0; i < vertices; i++)
 		d[i] = INT_MAX;
	memset(p, -1, sizeof(p));

 	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
 		s = heap.top().second;
 		heap.pop();
 		if(s<c) rota=1;
 		else rota = 0;
 		for(int i = 0; i < grau[s]; i++){
 				t = envio[s][i].first;
 				peso = envio[s][i].second;
 			if((rota && t == s+1) || !rota){
 				if (d[s] + peso < d[t]){
					d[t] = d[s] + peso;
 					p[t] = s;
 					heap.push(make_pair(-d[t], t));
 				}
 			}
 		}
	}
}

void limpa(int n){
	for(int i=0;i<n;i++){
		envio[i].clear();
	}
	memset(grau,0,sizeof(grau));
}

void criaAresta(int u, int v,int p){
	envio[u].push_back(make_pair(v,p));
	envio[v].push_back(make_pair(u,p));
	grau[u] ++;
	grau[v] ++;
}

main(){
	int n,m,c,k,u,v,p;
	while(cin >> n >> m >> c >> k, n && m && c && k){
		limpa(n);
		for(int i=0;i<m;i++){
			cin >> u >> v >> p;
			criaAresta(u,v,p);
		}
		Dijkstra(k,n,c);
		cout << d[c-1] <<endl;
	}
}
