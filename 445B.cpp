#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class grafo {
	ll V;
	vector<vector<pair<ll, ll>>> adj;

	void dfsR(ll raiz, vector<bool> &visitado) {
		visitado[raiz] = 1;
		for (auto &u : adj[raiz])
			if (!visitado[u.first])
				dfsR(u.first, visitado);
	}

public:

	grafo(ll V) {
		this->V = V;
		adj = vector<vector<pair<ll, ll>>>(V);
	}

	void aresta(ll u, ll v, ll w) {
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	ll dfs(ll raiz) {
		vector<bool> visitado(V, 0);
		ll total = 0;
		for (ll i = 0; i < V; i++) {
			if (!visitado[i]) {
				dfsR(i, visitado);
				total++;
			}
		}
		return total;
	}


};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, x, y;
	cin >> n >> m;
	grafo g(n);
	while (m--) {
		cin >> x >> y;
		g.aresta(x-1, y-1, 1);
	}
	cout << fixed << setprecision(0) << pow(2, (n-g.dfs(0))) << endl;
	return 0;
}