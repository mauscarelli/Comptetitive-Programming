#include<bits/stdc++.h>

using namespace std;

int alocaTabua(int l, int passo, int k,vector<int> tabua){
	if(passo%k) return INT_MAX;
	int n=0, flag=0;
	for(int i=0;i<tabua.size();i++){
		if(tabua[i]>l)continue;
		if(tabua[i] == l){
			//cout << tabua[i] <<endl;
			tabua[i] = 0;
			n++;
		}else{
			flag=0;
			for(int m=tabua.size()-1;m>i;m--){
				if(tabua[i]+tabua[m] == l ){
					flag = 1;
					n+=2;
				//	cout << tabua[i] << " " << tabua[m] <<endl;
					tabua[i] = 0;
					tabua[m] = 0;
					break;
				}
			}
			if(!flag) continue;
		}
		passo = passo -k;
		if(!passo)break;
	}
//	cout << endl << n << endl;
	if(passo) return INT_MAX;
	return n;
}
int menor;
main(){
	int n,m,l,k,t;
	vector<int> tabua;
	while(cin >> n >> m, n && m){
		tabua.clear();
		menor = INT_MAX;
		cin >> l >> k;
		for(int i=0;i<k;i++){
			cin >> t;
			tabua.push_back(t); 
		}
		if( (n*100)%l !=0 && (m*100)%l !=0 ) {
			//cout << "oi";
			cout << "impossivel" <<endl;
			continue;
		}
		sort(tabua.begin(),tabua.end(),greater<int>() );
		menor = min(alocaTabua(n,m*100,l,tabua),alocaTabua(m,n*100,l,tabua));
		if(menor == INT_MAX) cout << "impossivel" <<endl;
		else cout << menor << endl;
	}
	
}
