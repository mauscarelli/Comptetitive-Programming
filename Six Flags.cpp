#include<bits/stdc++.h>

using namespace std;

int PD[601]; //pontos
vector< pair<int,int> > atracao; // duracao,pontos

int limpa(){
	atracao.clear();
	memset(PD,0,sizeof(PD));
}

bool compare(pair<int,int> i1,pair<int,int> i2){
	return (i1.first < i2.first);
}

int resolve(int tempo){
	if(PD[tempo]) return PD[tempo];
	for(int i=0;i<atracao.size();i++){
		if(tempo - atracao[i].first >= 0) PD[tempo] = max(PD[tempo],atracao[i].second + resolve(tempo-atracao[i].first));
	}
	return PD[tempo];
}
void printaPD(int tempo){
	for(int i=0;i<=tempo;i++){
		cout << i << "  " << PD[i] <<endl; 
	}
	cout <<endl;
}
int main(){
	int n,t,d,p,inst = 1;
	while(cin >> n >> t, n ){
		limpa();
		for(int i=0;i<n;i++){
			cin >> d  >> p;
			atracao.push_back(make_pair(d,p));
		}
		sort(atracao.begin(),atracao.end(),compare);
		cout << "Instancia " << inst++ <<endl;
		cout << resolve(t) << endl <<endl;
		//printaPD(t);
		
	}
}
