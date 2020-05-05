#include<bits/stdc++.h>
#define MAX 101
int n;
using namespace std;
int p[MAX][MAX];
int s[MAX][MAX];

//Inacabado - Rodar BFS com mascara de bits (a ou A, b ou B)  para as 1024 combinações


int BFS(int mask){
    s[1][1] = 1;

    return s[n][n];
}

int main(){
    while (cin >> n)
    {
        memset(l,0,sizeof(l));
        memset(v,0,sizeof(v));
        char a;
        int m = INT_MAX;
        for(int i=1;i<=n;i++)
            for(int c=1;c<=n;c++){
                cin >> a;
                if(a-'A' >10)
                    p[i][c]= 10 + a-'a';
                else
                    p[i][c]= a-'A';
            }
        for(int i =0; i < (1 << 10);i++)
            m = min(m,BFS(i));
        if(m == INT_MAX) cout << "-1" <<endl;
        else cout << m <<endl;
    }
    return 0;
}