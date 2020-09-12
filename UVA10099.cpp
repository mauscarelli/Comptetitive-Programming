#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Edge {
	int u, v, weight;
	Edge() { }
	Edge(int u, int v, int weight) {
		this->u = u, this->v = v, this->weight = weight;
	}
};

bool comp(Edge &a, Edge &b) {
    return a.weight > b.weight;
}

class unionFind {
	vector<int> parent;
	vector<Edge> edges;

public:

	unionFind(int n) {
		parent = vector<int>(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	void insert(int u, int v, int w) {
		edges.push_back(Edge(u, v, w));
	}

	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	int kruskal(int s, int d, int t) {
		sort(edges.begin(), edges.end(), comp);
		int r;
		for (auto e : edges) {
			int a = find_set(e.u);
            int b = find_set(e.v);
            if (a != b) {
                parent[b] = a;
                if (find_set(s) == find_set(d)) {
                    r = (t + e.weight) / e.weight;
                    break;
                }
            }
        }
		return r;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r, a, b, p, s, d, t, caso = 1;
	while (cin >> n >> r && (n || r)) {
		unionFind uf(n);
		while (r--) {
			cin >> a >> b >> p;
			uf.insert(a-1, b-1, p-1);
		}
		cin >> s >> d >> t;
		s--, d--, t--;
		cout << "Scenario #" << caso++ << endl;
		cout << "Minimum Number of Trips = " << uf.kruskal(s, d, t) << endl << endl;
	}
	return 0;
}