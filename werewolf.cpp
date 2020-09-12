#include <bits/stdc++.h>
using namespace std;

struct FlowEdge
{
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic
{
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap)
    {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs()
    {
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int id : adj[v])
            {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed)
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++)
        {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow()
    {
        long long f = 0;
        while (true)
        {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf))
            {
                f += pushed;
            }
        }
        return f;
    }
};

int a[55], b[55];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            a[i]--;
            b[i]--;
        }
        int s = n + n; //origem
        int t = s + 1; //destino
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (a[j] == i || b[j] == i)
                    cnt++;
            if (cnt <= 1)
            {
                ans++;
                continue;
            }
            Dinic din(n + n + 2, s, t);
            for (int j = 0; j < n; j++)
                if (j != i)
                {
                    din.add_edge(s, j, 1);
                    int cap = cnt - 1;
                    if (j == a[i] || j == b[i])
                        cap--;
                    din.add_edge(j + n, t, cap);

                    if (a[j] != i && b[j] != i)
                    {
                        din.add_edge(j, a[j] + n, 1);
                        din.add_edge(j, b[j] + n, 1);
                    }
                }
            long long flw = din.flow();
            if (flw < n - 1 - cnt)
                ans++;
        }
        cout << ans <<endl;
    }
}