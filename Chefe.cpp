#include<bits/stdc++.h>
#define MAX_V 500

using namespace std;

vector<int> adj[MAX_V]; 
int idade[MAX_V];
int empregado[MAX_V];
int grau[MAX_V];
int visited[MAX_V];  

void initGrafo(int qtdeVertices){
    memset(grau, 0, sizeof(int)*qtdeVertices);
    for(int i = 0; i < qtdeVertices; i++)
    {
    	adj[i].clear();
    	empregado[i] = i;
	}
}

void aresta(int a, int b)
{
	adj[a].push_back(b);
	grau[a]++;
}

void troca(int a, int b)
{
	swap(idade[empregado[a]], idade[empregado[b]]);
	swap(empregado[a], empregado[b]);
}

void initDfs(int qtdeVertices)
{
	memset(visited, 0, sizeof(int)*qtdeVertices);
}

int menorIdade(int s)
{
	int t, idadeMin = INT_MAX;
	visited[s] = 1;
	for(int i = 0; i < grau[s]; i++)
	{
		t = adj[s][i];
		if (visited[t] == 0){
			idadeMin = min(idadeMin, idade[t]);
			idadeMin = min(idadeMin, menorIdade(t));
		}
	}
	return idadeMin;
}


int main()
{
	int n, m, inst, i, a, b;
	char c;
	while(cin >> n >> m >> inst)
	{
		initGrafo(n);
		for(i = 0; i < n; i++)
			cin >> idade[i];
		for(i = 0; i < m; i++)
		{
			cin >> a >> b;
			a--; b--;
			aresta(b, a);
		}
		for(i = 0; i < inst; i++)
		{
			cin >> c;
			if (c == 'T')
			{
				cin >> a >> b;
				troca(a-1, b-1);
			}
			else
			{
				cin >> a;
				initDfs(n);
				b = menorIdade(empregado[a-1]);
				if (b == INT_MAX)
					cout << "*" << endl;
				else
					cout << b << endl;
			}
		}
	}
}
