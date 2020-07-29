#include <bits/stdc++.h>
#define MAX_V 101
#define MAX_A 10000
using namespace std;

typedef struct
{
    int v; // vértice
    int w; // peso
} t_adj;
t_adj adj[MAX_V][MAX_A];
int d[MAX_V];    // distância
int p[MAX_V];    // pai do vertice
int grau[MAX_V]; // número de arestas no vértice

bool bellmanFord(int inicial, int n)
{
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++)
        d[i] = 40000; //limite superior
    d[inicial] = 0;
    for (int i = 0; i < n; i++)               // todos vertices
        for (int j = 0; j < n; j++)           /* todas */
            for (int k = 0; k < grau[j]; k++) /* arestas */
                if (d[j] + adj[j][k].w < d[adj[j][k].v])
                {
                    d[adj[j][k].v] = d[j] + adj[j][k].w;
                    p[adj[j][k].v] = j;
                }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < grau[i]; j++)
            if (d[adj[i][j].v] > d[i] + adj[i][j].w)
                return false;
    return true;
}

void aresta(int a, int b, int w)
{
    adj[a][grau[a]].v = b;
    adj[a][grau[a]].w = w;
    grau[a]++;
}
int main()
{
    int n, m, x, y, z;
    cin >> n >> m;
    memset(grau, 0, sizeof(grau));
    memset(p, -1, sizeof(p));
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        aresta(x, y, z);
    }
    bellmanFord(1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] >= 30000) //sem caminho
            d[i] = 30000;
        cout << d[i] << " ";
    }
    cout << endl;

}