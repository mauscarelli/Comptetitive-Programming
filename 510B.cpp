#include <bits/stdc++.h>
#define MAX_V 2501
#define MAX_A 5
using namespace std;

int visited[MAX_V];
int grau[MAX_V];
int p[MAX_V];
int adj[MAX_V][MAX_A];

void aresta(int a, int b)
{
    adj[a][grau[a]] = b;
    grau[a]++;
}

bool bfs(int inicio)
{
    int s, t;
    queue<int> Q;
    memset(visited, 0, sizeof(visited));
    memset(p, -1, sizeof(p));
    visited[inicio] = 1;
    Q.push(inicio);
    while (!Q.empty())
    {
        s = Q.front();
        Q.pop();
        for (int i = 0; i < grau[s]; i++)
        {
            t = adj[s][i];
            if (visited[t] == 1 && t != p[s])
                return true;
            if (visited[t] == 0)
            {
                visited[t] = 1;
                p[t] = s;
                Q.push(t);
            }
        }
    }
    return false;
}

int main()
{
    memset(grau, 0, sizeof(grau));
    memset(visited, 0, sizeof(visited));
    memset(p, -1, sizeof(p));

    int n, m;
    cin >> n >> m >> ws;
    bool f = false;
    char mat[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char c = mat[i][j];
            if (i - 1 > -1 && c == mat[i - 1][j])
                aresta(i * m + j, (i - 1) * m + j);
            if (i + 1 < n && c == mat[i + 1][j])
                aresta(i * m + j, (i + 1) * m + j);

            if (j - 1 > -1 && c == mat[i][j - 1])
                aresta(i * m + j, i * m + j - 1);
            if (j + 1 < m && c == mat[i][j + 1])
                aresta(i * m + j, i * m + j + 1);
        }

    for (int i = 0; i < n && !f; i++)
        for (int j = 0; j < m && !f; j++)
            if (!visited[i * m + j])
                if (bfs(i * m + j))
                    f = true;

    if(f) cout << "Yes" <<endl;
    else cout << "No" <<endl;

    return 0;
}