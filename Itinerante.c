#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40000
#define MAX_A 50000
typedef struct
{
    int A;
    int B;
    int custo;
} aresta;
int pai[MAX];
aresta a[MAX];


void quick_sort(aresta *ar, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = ar[(left + right) / 2].custo;
     
    while(i <= j) {
        while(ar[i].custo < x && i < right) {
            i++;
        }
        while(ar[j].custo > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = ar[i].custo;
            ar[i].custo = ar[j].custo;
            ar[j].custo = y;
            y = ar[i].A;
            ar[i].A = ar[j].A;
            ar[j].A = y;
            y = ar[i].B;
            ar[i].B = ar[j].B;
            ar[j].B = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(ar, left, j);
    }
    if(i < right) {
        quick_sort(ar, i, right);
    }
}

int find(int x){
    if(x != pai[x])
        pai[x] = find(pai[x]);
    return pai[x];
}

int main(){
    int m, n,x,y,z, i, soma,x_set,y_set;
    while(scanf("%d %d",&m,&n), m && n){
        soma = 0;
        for(i=0;i<m;i++){
            pai[i] = i;
        }
        for(i = 0; i<n;i++){
            scanf("%d %d %d",&x,&y,&z);
            a[i].A = x;
            a[i].B = y;
            a[i].custo = z;
        }
        quick_sort(a,0,n-1);
        
        for(i =0; i < n ;i++){
            x = a[i].A;
            y = a[i].B;
            z = a[i].custo;
            x_set = find(x);
            y_set = find(y);
            if(x_set != y_set){
                pai[y_set] = pai[x_set];
                soma += z;
            }
        }
        printf("%d\n",soma);
    }

    return 0;
}
