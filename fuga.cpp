#include<bits/stdc++.h>
#define MAX_V 100
#define MAX_A 10000

using namespace std;
 ////////////////////////// REPENSAR, Procurar sobre Min cost Max Flow /////////////////////
typedef struct{
    int v; // vértice
    int w; // peso
    bool u; //usado
} t_adj;
t_adj adj[MAX_V][MAX_A];

int grau[MAX_V];
int d[MAX_V]; // distância
int p[MAX_V]; // pai do vertice

void dijkstra(int inicial, int vertices){
    priority_queue< pair<int, int> > heap; //distância, vértice
    int s, t, peso;

    for(int i = 0; i < vertices; i++)
        d[i] = INT_MAX;
    memset(p, -1, sizeof(p));

    heap.push(make_pair(d[inicial] = 0, inicial));
    while(!heap.empty()){
        s = heap.top().second;
        heap.pop();
        for(int i = 0; i < grau[s]; i++){
            t = adj[s][i].v;
            peso = adj[s][i].w;
            if (d[s] + peso < d[t] && !adj[s][i].u){
                d[t] = d[s] + peso;
                p[t] = s;
                heap.push(make_pair(-d[t], t));
            }
        }
    }
}

void aresta(int a, int b, int w){
    adj[a][ grau[a] ].v = b;
    adj[a][ grau[a] ].w = w;
    adj[a][ grau[a] ].u = false;
    grau[a]++;

    adj[b][ grau[b] ].v = a;
    adj[b][ grau[b] ].w = w;
    adj[b][ grau[b] ].u = false;
    grau[b]++;
}

void desativar(int v){
    if(p[v] == -1) return;
    for(int i =0; i < grau[p[v]];i++){
        if(adj[p[v]][i].v == v){
            adj[p[v]][i].u = true;
            break;
        }
    }
    desativar(p[v]);
}

int main(){

    int n,m,a,b,c,soma;
    while(cin >> n,n){
        soma = 0;
        memset(grau, 0, sizeof(grau));
        cin >> m;
        while(m--){
            cin >> a >> b >> c;
            aresta(a-1,b-1,c);
        }
        dijkstra(0,n);
        if(d[n-1] == INT_MAX) cout << "Back to jail"<<endl;
        else{
            soma = d[n-1];
            desativar(n-1);
            dijkstra(0,n);
            if(d[n-1] == INT_MAX) cout << "Back to jail"<<endl;
            else cout << soma + d[n-1] <<endl;
        }
    }

    return 0;
}