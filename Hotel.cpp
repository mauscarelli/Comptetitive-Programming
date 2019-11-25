#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

priority_queue <pair<long long, int > > custo;
int cortesias[MAX];
int m,k;

int calculaVoucher(int i){
    for(int c=i+1; c<i+k+1 && c<m ;c++ ){
        if(cortesias[c]-1 < 0) return 0;
    }
    return 1;
}

int main(){
    long long p;
    long long soma = 0;
    pair<long long , int> par;
    int u=0;
    cin >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> p;
        soma += p;
        cortesias[i] = i;
        custo.push(make_pair(p,i));
    }
    while(!custo.empty()){
        par = custo.top();
        custo.pop();
        if(cortesias[par.second] >0 && calculaVoucher(par.second)){
            soma -= par.first;
            for(int i =0;i<m;i++){
                if(cortesias[i] !=0) cortesias[i] --;
            }
        }
    }
    cout << soma <<endl;
    return 0;
}