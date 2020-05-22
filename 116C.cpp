#include<bits/stdc++.h>
#define MAX_V 2005
#define MAX_A 2005

using namespace std;

int grau[MAX_V];
int p[MAX_V]; 
int visited[MAX_V]; 

int adj[MAX_V][MAX_A];

int m = 0;

void aresta(int a, int b){
 adj[a][ grau[a] ] = b;
 grau[a]++;
}

void dfs(int n, int s){
    m = max(m,s);
    for(int i=0;i<grau[n];i++)
        dfs(adj[n][i],s+1);
}

int main(){
    memset(grau, 0, sizeof(grau));
    memset(visited, 0, sizeof(visited));
    memset(p, -1, sizeof(p));
    int n,pi;
    cin >> n;
    set<int> ini;
    set<int>::iterator it;
    for(int i = 1;i<=n;i++){
        cin >> pi;
        if(pi == -1) ini.insert(i);
        else aresta(pi,i);
    }
    for(it = ini.begin();it!=ini.end();it++)
        dfs(*it, 1);
    cout << m <<endl;
}