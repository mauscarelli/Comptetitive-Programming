#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct reg *no;
struct reg
{
    int filho;
    no prox;
};
int visitado[MAX];
int grauE[MAX];
int top[MAX];
no lista[MAX];

no criaNo(int f)
{
    no p = (no)malloc(sizeof(no));
    p->filho = f;
    p->prox = NULL;
    return p;
}

void insereNo(int p, int f)
{
    if (lista[p] == NULL)
    {
        lista[p] = criaNo(f);
    }
    else
    {
        no q = lista[p];
        while (q->prox)
        {
            q = q->prox;
        }
        q->prox = criaNo(f);
    }
}
void DFS(int n)
{
    no q = lista[n];
    visitado[n] = 1;
    printf("%d ", n);
    while (q)
    {
        if (!visitado[q->filho])
            DFS(q->filho);
        q = q->prox;
    }
}

int DFSB(int n, int d)
{
    if (n == d)
        return 1;
    visitado[n] = 1;
    no q = lista[n];
    while (q)
    {
        if (!visitado[q->filho])
            if( DFSB(q->filho , d) ) return 1;
        q = q->prox;
    }
    return 0;
}

no fila = NULL;

void insereFila(int i)
{
    if (fila == NULL)
    {
        fila = criaNo(i);
        return;
    }
    no q = fila;
    while (q->prox != NULL)
    {
        q = q->prox;
    }
    q->prox = criaNo(i);
}

void BFS(int n)
{
    memset(visitado, 0, MAX);
    fila = criaNo(n);
    while (fila != NULL)
    {
        no q = fila;
        visitado[q->filho] = 1;
        printf("%d ", q->filho);
        no p = lista[q->filho];
        while (p != NULL)
        {
            if (!visitado[p->filho])
            {
                insereFila(p->filho);
                visitado[p->filho] = 1;
            }
            p = p->prox;
        }
        fila = fila->prox;
        free(q);
    }
}

int BFSB(int n ,int d)
{
    memset(visitado, 0, MAX);
    fila = criaNo(n);
    while (fila != NULL)
    {
        no q = fila;
        visitado[q->filho] = 1;
        if(q->filho == d) return 1;
        no p = lista[q->filho];
        while (p != NULL)
        {
            if (!visitado[p->filho])
            {
                insereFila(p->filho);
                visitado[p->filho] = 1;
            }
            p = p->prox;
        }
        fila = fila->prox;
        free(q);
    }
    return 0;
}

void buscaG(int n){
    int i;
    for(i=0;i<n;i++){
        if(!visitado[i] && !grauE[i]){
            //printf("%d ",i);
            insereFila(i);
            visitado[i] = 1;
        }
    }
    //printf("\n");
}

int Topologia(int n){
    int c = 0;
    memset(visitado,0,MAX);
    fila = NULL;
    buscaG(n);
    while (fila != NULL)
    {
        //printf ("%d ",fila->filho);
        no q = fila;
        fila = fila->prox;
        top[c] = q->filho;
        no p = lista[q->filho];
        while(p){
            no r = p;
            if(!(--grauE[p->filho])){
                visitado[p->filho] = 1;
                insereFila(p->filho);
            }
            p = p->prox;
            free(r);
        }
        free(q);
        c++;
    }
    return (c == n) ?  1 : 0;    
}

int main()
{
    int n, m, i, p, f,d;
    memset(visitado, 0, MAX);
    memset(grauE,0,MAX);
    memset(top,0,MAX);
    printf("Digite quantos nos existem no grafo: ");
    scanf("%d", &n);
    printf("Digite quantas arestas existem: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        printf("Digite os nos da aresta (exemplo: 0 4): ");
        scanf("%d %d", &p, &f);
        insereNo(p, f);
        grauE[f]++;
    }
    printf("Feito, digite o vertice inicial: ");
    scanf("%d", &i);
    printf("Ordem dos vertices visitados DFS: ");
    memset(visitado, 0, MAX);
    DFS(i);
    printf("\nOrdem dos vertices visitados BFS: ");
    BFS(i);
    printf("\nDigite 2 vertices para ver se eh possivel alcanca-los (ex: 2 6) 0 0 para terminar: ");
    while(scanf("%d %d",&i,&d), i || d){
        memset(visitado, 0, MAX);
        if(DFSB(i,d)) printf("Por DFS achou\n");
        else printf("Nao da pra chegar\n");
        if(BFSB(i,d)) printf("Por BFS achou\n");
        else printf("Nao da pra chegar\n");
    }
    if(Topologia(n)){
        printf("Topologia linear: ");
        for(i = 0;i<n;i++){
            printf("%d ",top[i]);
        }
        printf("\n");
    }else
    {
        printf("O grafo possui ciclos.\n");
    }
    
    
}