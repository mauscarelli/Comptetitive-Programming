#include<bits/stdc++.h>
#define MAX_V 100
#define MAX_A 19800
using namespace std;

vector< pair<int,int> > aviao[MAX_V]; // Aviao[cidade origem] <cidade destino , dinheiro necessario>
vector< pair<int,int> > onibus[MAX_V]; // Aviao[cidade origem] <cidade destino , dinheiro necessario>
int grauA[MAX_V];
int grauO[MAX_V];
int d[MAX_V]; //d[i] armazena a preco até o vértice i, e as
//estimativas durante as iterações
int p[MAX_V]; //armazena o predecessor de cada vértice

void DijkstraA(int inicial, int vertices){
	priority_queue< pair<int, int> > heap; //distância, vértice
 	int s, t, peso;

 	for(int i = 0; i < vertices; i++)
 		d[i] = INT_MAX;
	memset(p, -1, sizeof(p));

 	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
 		s = heap.top().second;
 		heap.pop();
 		for(int i = 0; i < grauA[s]; i++){
 			t = aviao[s][i].first;
 			peso = aviao[s][i].second;
 			if (d[s] + peso < d[t]){
				d[t] = d[s] + peso;
 				p[t] = s;
 				heap.push(make_pair(-d[t], t));
 			}
 		}
	}
}

void DijkstraO(int inicial, int vertices){
	priority_queue< pair<int, int> > heap; //distância, vértice
 	int s, t, peso;

 	for(int i = 0; i < vertices; i++)
 		d[i] = INT_MAX;
	memset(p, -1, sizeof(p));

 	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
 		s = heap.top().second;
 		heap.pop();
 		for(int i = 0; i < grauO[s]; i++){
 			t = onibus[s][i].first;
 			peso = onibus[s][i].second;
 			if (d[s] + peso < d[t]){
				d[t] = d[s] + peso;
 				p[t] = s;
 				heap.push(make_pair(-d[t], t));
 			}
 		}
	}
}

void criaAresta(int a,int b,int t,int r){
	if(t){
		aviao[a-1].push_back(make_pair(b-1,r));
		grauA[a-1] ++;
	}else{
		onibus[a-1].push_back(make_pair(b-1,r));
		grauO[a-1] ++;
	}
}

void resetaDados(int n){
	for(int i = 0; i<n;i++){
		aviao[i].clear();
		onibus[i].clear();
		grauA[i] = 0;
		grauO[i] = 0;
	}
}

int main(){
	int n,m,a,b,t,r,preco;
	
	while(cin >> n >> m){
		resetaDados(n);
		for(int i=0;i<m;i++){
			cin >> a >> b >> t >> r;
			criaAresta(a,b,t,r);
		}
		DijkstraA(0,n);
		preco = d[n-1];
		DijkstraO(0,n);
		preco = min(preco,d[n-1]);
		cout << preco <<endl;
	}
	
	
	return 0;	
}
