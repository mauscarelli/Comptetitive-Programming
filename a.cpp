#include <bits/stdc++.h>
#include <math.h>
#define MAX 1004
using namespace std;

int m, n;
typedef struct
{
    int x;
    int y;
    int r;
} ponto;

ponto no[MAX]; // 0 - parede esquerda/ 1 - parede baixo / 2-parede direita / 3 - parede cima / >= 4 sensores
vector<int> adj[MAX];
int visitado[MAX];

void criaNo(int i, int x, int y, int r)
{
    ponto p;
    p.x = x;
    p.y = y;
    p.r = r;
    no[i + 4] = p;
}

void criaAresta(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

double distance(ponto a, ponto b) // distancia euclidiana
{
    int z = a.x - b.x;
    int w = a.y - b.y;
    return sqrt(z * z + w * w);
}

void conecta(int i) //conecta os pontos
{
    i = i+4;
    ponto p = no[i];
    if ((p.x - p.r) <= 0)
        criaAresta(0, i);
    if ((p.x + p.r) >= m)
        criaAresta(2, i);
    if ((p.y - p.r) <= 0)
        criaAresta(3, i);
    if ((p.y + p.r) >= n)
        criaAresta(1, i);
    for (int c = 4; c < i; c++)
    {
        if (distance(no[c], no[i]) - (no[c].r + no[i].r) <= 0.1)
            criaAresta(c,i);
    }
}

void mostraArestas(int i){ // printa pra testes
    cout << i << " - ";
    for(int c=0;c<adj[i].size();c++)
        cout << adj[i][c] << " ";
    cout << endl;
}

int busca(int origem, int atual){ // resolve
    if( (origem == 0 && (atual == 3 || atual == 2) ) || (origem == 1 && (atual == 2 || atual == 3)) )
        return 1;
    if(visitado[atual]) return 0;
    visitado[atual] = 1;
    for(int i=0;i<adj[atual].size();i++){
        if(busca(origem, adj[atual][i])) return 1;
    }
    return 0;
}

int main()
{
    int k, s, x, y;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y >> s;
        criaNo(i, x, y, s);
        conecta(i);
    }
    /*for(int i =0;i<k+4;i++){
        mostraArestas(i);
    }*/
    if(busca(0,0) || busca(1,1)) cout << "N" <<endl;
    else cout << "S" <<endl;
    return 0;
}