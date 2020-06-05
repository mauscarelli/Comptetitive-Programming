#include <bits/stdc++.h>
#define MAX_V 10000
#define MAX_A 100000

using namespace std;

typedef struct
{
    int v;
    int w;
} TAdj;

vector<TAdj> adj[MAX_V + 1]; //Grafo
int p[MAX_V + 1];
int d[MAX_V + 1];
int visited[MAX_V + 1];
int cidades = 0;
void initGrafo(int qtdeVertices)
{
    for (int i = 0; i < qtdeVertices; i++)
        adj[i].clear();
}

void aresta(int a, int b, int w)
{
    adj[a].push_back(*(new TAdj()));
    int grau = adj[a].size() - 1;
    adj[a][grau].v = b;
    adj[a][grau].w = w;

    adj[b].push_back(*(new TAdj()));
    grau = adj[b].size() - 1;
    adj[b][grau].v = a;
    adj[b][grau].w = w;
}

long long int prim(int inicio, int n)
{
    long long int total = 0;
    priority_queue<pair<int, int>> heap;
    int s, t, arc;
    for (int i = 0; i < n; i++)
        d[i] = INT_MAX;
    memset(p, -1, sizeof(p));
    memset(visited, 0, sizeof(visited));
    heap.push(make_pair(d[inicio] = 0, inicio));
    total = 0;
    cidades = 0;
    while (!heap.empty())
    {
        s = heap.top().second;
        heap.pop();
        if (!visited[s]){
            total += d[s];
            cidades++;
        }
        visited[s] = 1;
        for (int i = 0; i < adj[s].size(); i++)
        {
            t = adj[s][i].v;
            arc = adj[s][i].w;
            if (d[t] > arc && !visited[t])
            {
                d[t] = arc;
                p[t] = s;
                heap.push(make_pair(-d[t], t));
            }
        }
    }
    return total;
}

int main()
{
    int n, m, i, w,node;
    long long int resp = 0;
    string s,u,v;
    map<string,int> c;
    while (cin >> n >> m, n)
    {
        initGrafo(n);
        node = 0;
        c.clear();
        cin.ignore(1,'\n');
        for(int i =0;i<n;i++){
            cin >> s;
            c[s] = node++;
        }
        cin.ignore(1,'\n');
        for (i = 0; i < m; i++)
        {
            getline(cin,s);
            int sp=0;
            sp = s.find(' ');
            u = s.substr(0,sp);
            s.erase(0,sp+1);
            sp = s.find(' ');
            v = s.substr(0,sp);
            s.erase(0,sp+1);
            w = stoi(s);
            aresta(c[u], c[v], w);
        }
        cin >> s;
        cin.ignore(1,'\n');
        resp = prim(c[s],n);
        if(cidades != n)
            cout << "Impossible" <<endl;
        else
            cout << resp << endl;
    }
}
