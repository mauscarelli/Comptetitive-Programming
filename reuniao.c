#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAX_A 10000
typedef struct aresta
{
    int B;
    int custo;
    struct aresta *prox;
} Aresta;

typedef struct
{
    int v;
    int custo;
} Vertice;

int dist[MAX];
Vertice heap[MAX_A];
Aresta *no[MAX];
int visitado[MAX];
int fim;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

Aresta *criaAresta(int v, int w)
{
    Aresta *ar = malloc(sizeof(Aresta));
    ar->B = v;
    ar->custo = w;
    ar->prox = NULL;
    return ar;
}

void swap(int a, int b)
{
    Vertice p = heap[a];
    heap[a] = heap[b];
    heap[b] = p;
}

void registraHeap(Vertice p)
{
    int i = fim;
    heap[fim] = p;
    fim++;
    while (i != 0 && heap[i].custo < heap[(i - 1) / 2].custo)
    {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void MinHeapify(int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < fim && heap[left].custo < heap[i].custo)
        smallest = left;
    if (right < fim && heap[right].custo < heap[smallest].custo)
        smallest = right;
    if (smallest != i)
    {
        swap(smallest, i);
        MinHeapify(smallest);
    }
}

int extraiMin()
{
    if (fim == 1)
    {
        fim--;
        return heap[0].v;
    }

    Vertice raiz = heap[0];
    heap[0] = heap[--fim];
    MinHeapify(0);
    return raiz.v;
}

int isInHeap(int v)
{
    int i;
    for (i = 0; i < fim; i++)
        if (heap[i].v == v)
            return i + 1;
    return 0;
}

void atualiza(int i, int cost)
{
    heap[i].custo = cost;
    while (i != 0 && heap[i].custo < heap[(i - 1) / 2].custo)
    {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void Dijkstra(int atual)
{
    int ok;
    Vertice q;
    q.custo = 0;
    dist[atual] = 0;
    q.v = atual;
    registraHeap(q);
    while (fim != 0)
    {
        atual = extraiMin();
        visitado[atual] = 1;
        Aresta *p = no[atual];
        while (p != NULL)
        {
            //printf("%d\n",p->custo);
            if (!visitado[p->B] && dist[p->B] > dist[atual] + p->custo)
            {
                dist[p->B] = dist[atual] + p->custo;
                if (ok = isInHeap(p->B))
                {
                    atualiza(ok - 1, dist[p->B]);
                }
                else
                {
                    Vertice q;
                    q.v = p->B;
                    q.custo = dist[p->B];
                    registraHeap(q);
                }
            }
            p = p->prox;
        }
    }
}

int main()
{
    int n, m, u, v, w, distI, maxdist = __INT_MAX__, i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        if (no[u] == NULL)
        {
            no[u] = criaAresta(v, w);
        }
        else
        {
            Aresta *p = no[u];
            while (p->prox)
            {
                p = p->prox;
            }
            p->prox = criaAresta(v, w);
        }
        if (no[v] == NULL)
        {
            no[v] = criaAresta(u, w);
        }
        else
        {
            Aresta *p = no[v];
            while (p->prox)
            {
                p = p->prox;
            }
            p->prox = criaAresta(u, w);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[j] = __INT_MAX__;
            visitado[j] = 0;
        }
        dist[i] = 0;
        distI = 0;
        fim = 0;
        Dijkstra(i);
        for (j = 0; j < n; j++)
        {
            distI = max(distI, dist[j]);
            //printf("%d ",dist[j]);
        }
        maxdist = min(distI, maxdist);
        //printf("\n");
    }
    printf("%d\n", maxdist);
    return 0;
}
