// g++ -static -O2 -lm
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, p, q,c,posi,pilhai, minimo;
	vector<int> pilhas[1000];
	while(cin >> n >> p, n && p){
		
		for(int i = 0;i<n;i++)
			pilhas[i].clear();
			
		for(int i=0;i<p;i++){
			cin >> q;
			for(int cont=0;cont<q;cont++){
				cin >> c;
				pilhas[i].push_back(c);
				if(c == 1){ 
					posi = pilhas[i].size() - 1;
					pilhai = i;
				}
			}
		}
		
		int soma=0;
		minimo = INT_MAX;
		int val;
			for(int i = pilhai;i<p;i++){
				val = pilhas[i].size() - posi;
				if(val > 0) soma+=val;
				else break;
			}
			minimo = soma;
			soma = 0;
	
			for(int i = pilhai;i>=0;i--){
				val = pilhas[i].size() - posi;
				if(val > 0) soma+=val;
				else break;
			}
			minimo = min(minimo,soma);
		if(p == 1) minimo = pilhas[0].size()- posi;
		cout << minimo-1 <<endl;
	}
	
	return 0;
}
