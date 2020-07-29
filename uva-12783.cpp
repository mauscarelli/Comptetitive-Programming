#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool comp(pair<int, int> &a, pair<int, int> &b) {
	return (a.first < b.first || (a.first == b.first && a.second < b.second));
}

class grafo {
	int v;
	vector<pair<int, int>> *adj;

	void pontesRec(int u, vector<bool> &visitado, vector<int> &desc,
			vector<int> &menor, vector<int> &pai, vector<pair<int, int>> &p) {
		static int tempo = 0;
		visitado[u] = 1;
		desc[u] = menor[u] = ++tempo;
		for (const auto& w : adj[u]) {
			if (!visitado[w.first]) {
				pai[w.first] = u;
				pontesRec(w.first, visitado, desc, menor, pai, p);
				menor[u] = min(menor[u], menor[w.first]);
				if (menor[w.first] > desc[u]) {
					if (w.first <= u) p.push_back({w.first, u});
					else p.push_back({u, w.first});
				}
			}
			else if (w.first != pai[u]) menor[u] = min(menor[u], desc[w.first]);
		}
	}

public:

	grafo(int v) {
		this->v = v;
		adj = new vector<pair<int, int>>[v];
	}

	void aresta(int u, int w, int k) {
		adj[u].push_back(make_pair(w, k));
		adj[w].push_back(make_pair(u, k));
	}

	void imprime() {
		for (int i = 0; i < v; i++) {
			cout << '[' << i << "] ";
			for (const auto& w : adj[i]) cout << "-> " << w.first << "(" << w.second << ") ";
			cout << endl;
		}
	}

	void pontes() {
		vector<bool> visitado(v, 0);
		vector<int> pai(v, -1);
		vector<int> desc(v);
		vector<int> menor(v);
		vector<pair<int, int>> p;
		for (int i = 0; i < v; i++)
			if (!visitado[i])
				pontesRec(i, visitado, desc, menor, pai, p);
		sort(p.begin(), p.end(), comp);
		int n = p.size();
		cout << n;
		for (int i = 0; i < n; i++) {
			cout << " " << p[i].first << " " << p[i].second;
		}
		cout << endl;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	while (cin >> n >> m && (n || m)) {
		grafo g(n);
		while (m--) {
			cin >> a >> b;
			g.aresta(a, b, 1);
		}
		g.pontes();
	}
	return 0;
}