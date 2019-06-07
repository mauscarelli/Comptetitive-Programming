#include<bits/stdc++.h>
#define QtdV 10001
#define ESQUERDA 0
#define DIREITA 1
using namespace std;

vector<int> arvore[QtdV];
int maxE=0, maxD=0;

int nivelMaximo(int ind,int nivel){
	int nM = ++nivel;
	for(int i=0;i<arvore[ind].size();i++)
		nM = max(nM,nivelMaximo(arvore[ind][i],nivel));
	return nM;
}

void bfs(){
	queue<int> fila;
	int at, n;
	for(int i =0; i < arvore[1].size();i++)	fila.push(arvore[1][i]);
	while(!fila.empty()){
		at = fila.front();
		fila.pop();
		n = nivelMaximo(at,0);
		if(maxE > maxD) maxD = max(maxD, n);
		else maxE = max(maxE,n);
	}
}

main(){
	int u, v, n;
	cin >> n;
	for(int i = 1;i<n;i++){
		cin >> u >> v;
		arvore[u].push_back(v);
	}
	bfs();
	cout << maxE + maxD <<endl;
}
