#include<bits/stdc++.h>
#define MAX 100000
using namespace std;


int main(){
    long long int direita=0;
    int saco[MAX];
    int n,c,t;
    cin >> n >> c >> t;
    for(int i=0;i<n;i++){
        cin >> saco[i];
        direita+= saco[i];
    }
    int comp;
    long long int pipoqueiro, mpipoqueiro=direita,esquerda = 0;
    while(direita >= esquerda){
        long long int meio = (esquerda+direita)/2;
        //cout << meio <<endl;
        pipoqueiro=0;
        comp=0;
        long long int soma=0;
        for(int i =0;i<n;i++){
            if(soma + saco[i]>=meio){
                comp++;
                pipoqueiro = max(pipoqueiro,soma);
                soma = 0;
            }
            soma+= saco[i];
            //cout << soma << " ";
        }
        if(soma != 0) comp++;
        pipoqueiro = max(pipoqueiro,soma);
        //cout << comp << " "<<  (int) ceil((1.0*pipoqueiro)/t) <<endl;
        if(comp <= c){
            mpipoqueiro = min(mpipoqueiro,pipoqueiro);
            direita = meio-1;
        }else{
            esquerda = meio+1;
        }
    }
    cout << (int) ceil(mpipoqueiro/(1.0*t)) <<endl;
    return 0;
}