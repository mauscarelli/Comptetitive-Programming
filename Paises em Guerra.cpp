#include<bits/stdc++.h>
#define MAX_V 500
#define MAX_A 250000
using namespace std;

vector< pair<int,int> > envio[MAX_V]; // envio[cidade origem] <cidade destino , tempo necessario> 
int grau[MAX_V];
int d[MAX_V]; //d[i] armazena a distância até o vértice i, e as
//estimativas durante as iterações
int p[MAX_V]; //armazena o predecessor de cada vértice

void Dijkstra(int inicial, int vertices){
	priority_queue< pair<int, int> > heap; //distância, vértice
 	int s, t, peso;

 	for(int i = 0; i < vertices; i++)
 		d[i] = INT_MAX;
	memset(p, -1, sizeof(p));

 	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
 		s = heap.top().second;
 		heap.pop();
 		for(int i = 0; i < grau[s]; i++){
 			t = envio[s][i].first;
 			peso = envio[s][i].second;
 			if (d[s] + peso < d[t]){
				d[t] = d[s] + peso;
 				p[t] = s;
 				heap.push(make_pair(-d[t], t));
 			}
 		}
	}
}


void verificaPais(int x,int y){ // Já adicionei x -> y preciso verificar y->x
	bool p=false;
	for(int i=0;i<envio[y-1].size();i++){
		if(envio[y-1][i].first == x-1){
			envio[y-1][i].second = 0;
			p = true;
			break;
		}
	}
	if(!p) return;
	for(int i=0;i<envio[x-1].size();i++){
		if(envio[x-1][i].first == y-1){
			envio[x-1][i].second = 0;
			return;
		}
	}
}

void criaAresta(int x,int y,int h){
	envio[x-1].push_back(make_pair(y-1,h));
	grau[x-1] ++;
}

void resetaDados(int n){
	for(int i = 0; i<n;i++){
		envio[i].clear();
		grau[i] = 0;
	}
}

int main(){
	int n,e,x,y,h,k,dist,o;
	
	while(cin >> n >> e, n){
		resetaDados(n);
		for(int i=0;i<e;i++){
			scanf("%d%d%d",&x,&y,&h);
			criaAresta(x,y,h);
			verificaPais(x,y);
		}
		scanf("%d",&k);
		o=-1;
		for(int i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			if(x != o)Dijkstra(x-1,n);
			dist = d[y-1];
			if(dist == INT_MAX) printf("Nao e possivel entregar a carta\n");
			else printf("%d\n",dist);
		}
		printf("\n");
	}
	
	
	return 0;	
}
