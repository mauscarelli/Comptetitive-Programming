#include<iostream>
#include<bits/stdc++.h>
#define MAX 41
using namespace std;
int mapa[MAX][MAX] = {{0}};
int n, m;
vector< pair<int,int > > visitado;

int backtracking(int l,int c, int al, int ac, int s,int ms){
	if(find(visitado.begin(),visitado.end(), make_pair(l,c)) != visitado.end()){
		return 0;
	}
	visitado.push_back(make_pair(l,c));
	if(!mapa[l][c])
		return 0;
	else if(mapa[l][c] == 3){
			return 1;
	}else if(mapa[l][c] == 2){
		s++;
		if(s*2>ms)
			return 0;
	} 
	if(c+1 <= m &&  (c+1 != ac) ){ //direita, somar coluna
		if(backtracking(l,c+1,l,c,s,ms))
			return 1;
	}
	if(l-1 >0 && (l-1 != al) ){ //cima, !soma linha
		if(backtracking(l-1,c,l,c,s,ms))
			return 1;
	}
	if(c-1 > 0 && (c-1 != ac) ){ //esquerda, !soma coluna
		if(backtracking(l,c-1,l,c,s,ms))
			return 1;
	}
	if(l+1 <=n && (l+1 != al) ){ //cima, !soma linha
		if(backtracking(l+1,c,l,c,s,ms))
			return 1;
	}
	visitado.pop_back();
	return 0;
	
}

main(){
	int j;
	char sim;
	cin >> n >> m >> j;
	int el, ec;
	for(int l=1; l<=n;l++){
		for(int c=1;c<=m;c++){
			cin >> sim;
			if(sim == '.')
				mapa[l][c] = 1;
			else if(sim == 's')
				mapa[l][c] = 2;
			else if(sim == 'x')
				mapa[l][c] = 3;
			else if(sim == '@'){
				mapa[l][c] = 1;
				el=l; ec = c;	
			}
		}
	}
	if(backtracking(el,ec,el,ec,0,j))
		cout << "SUCCESS" <<endl;
	else
		cout <<"IMPOSSIBLE" <<endl;
	return 0;
}
