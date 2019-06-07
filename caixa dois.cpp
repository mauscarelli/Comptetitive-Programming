	#include<bits/stdc++.h>
	#define MAX_V 10000
	#define MAX_A 100000
	using namespace std;

	vector< tuple<long long, int, int> > aresta;

	//Union-find
	int dset[MAX_V+1]; 
	int tam[MAX_V+1];

	int find(int x) {
		if (dset[x] == x || dset[x] == -1) 
			return x;
		else             
			return find(dset[x]);
	}

	bool same(int x, int y)
	{
		return (find(x) == find(y));
	}

	void merge(int u, int v) {
		int a = find(u);
		int b = find(v);
		if (tam[a] < tam[b]) 
			swap(a, b);
		
		dset[b] = a;
		tam[a] += tam[b];
	}

	long long kruskal(int n){
		long long total=0;
		for(int i=1;i<=n;i++){
			dset[i] = i;
			tam[i] = 1;
		}
		for(int i=0; i<aresta.size();i++){
			if( !same(get<1>(aresta[i]),get<2>(aresta[i]))){
				merge(get<1>(aresta[i]),get<2>(aresta[i]));
				total+=get<0>(aresta[i]);
			}
		}
		return total;
	}

	int main(){
		int n,m,x,y;
		long long c,k;
		while(cin >> n >> m, n && m){
			aresta.clear();
			for(int i=0;i<m;i++){
				cin >> x >> y >> c;
				aresta.push_back(make_tuple(c,x,y)); // { } é um jeito de se inserir um par ou tuple
			}
			sort(aresta.begin(),aresta.end());
			k = -kruskal(n);
			reverse(aresta.begin(),aresta.end());
			k+= kruskal(n);
			cout << k << endl;
		}
		return 0;
	}