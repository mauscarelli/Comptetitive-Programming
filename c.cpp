#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

class grafo
{
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    grafo(int V)
    {
        this->V = V;
        adj = vector<vector<pair<int, int>>>(V);
    }

    void aresta(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
    }

    void topologicalSort()
    {

        vector<int> grau_ent(this->V, 0);

        for (int i = 0; i < this->V; i++)
            for (int j = 0; j < adj[i].size(); j++)
                grau_ent[adj[i][j].first]++;
        queue<int> q;
        int last = 0;
        for (int i = 0; i < this->V; i++)
            if (!grau_ent[i])
            {
                q.push(i);
                last = i;
            }
        int rank = 1;
        bool m;
        priority_queue<pair<int,int>> res;
        while (!q.empty())
        {
            m = false;
            int u = q.front();
            q.pop();
            res.push({-rank,-u});
            if (u == last)
            {
                rank++;
                m = true;
                last = q.back();
            }
            for (int i = 0; i < adj[u].size(); i++)
                if (--grau_ent[adj[u][i].first] == 0)
                {
                    q.push(adj[u][i].first);
                    if(m)
                        last = adj[u][i].first;
                }
        }

        while(!res.empty()){
            printf("%d %d\n",-res.top().first,-res.top().second);
            res.pop();
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, t;
    cin >> t;
    for (int sc = 1; sc <= t; sc++)
    {
        cin >> n >> m;
        grafo g(n);
        while (m--)
        {
            cin >> a >> b;
            g.aresta(b, a, 1);
        }
        printf("Scenario #%d:\n", sc);
        g.topologicalSort();
    }
}