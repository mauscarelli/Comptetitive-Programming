#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int primos[MAX];

void carregaPrimos(int n){
    int p= 2,ind=1; primos[0]=1;
    bool Ehprimo;
    while (p < n/2) //Um número significativo de primos vai ser carregado
    {
        Ehprimo = true;
        for(int i = 2; i<p;i++ ){
            if(p%i == 0){
                Ehprimo = false;
                break;
            }
        }
        
        if(Ehprimo) primos[ind++] = p; //adiciona o numero p na tabela de primos e depois incrementa o indice
        p++;
    }
    
}

main()
{
    int n,ind;
    cin >> n;
    carregaPrimos(n);
    long long soma = 0;
    if (n <39)
    {
        printf("falso"); // Primeiro numero possível é 39
    }
    else
    {
        soma = pow(primos[0],2) + pow(primos[1],2) + pow(primos[2],2) + pow(primos[3],2); //Primeira possibilidade
        ind= 3;
        for(int i=4;soma<n;i++){
            soma= soma - pow(primos[i-4],2) + pow(primos[i],2); //retiro o primo que foi inserido 4 passos atrás e insiro o novo
            //como é sempre quadrado de um numero poderia substituir para primos[i] * primos[i], ocupa menos tempo, 
            //mas use o tipo long long na hora de fazer a operação para n estourar limite
            ind = i;
        }
        if(soma == n)
            printf("%d %d %d %d\n",primos[ind-3],primos[ind-2],primos[ind-1],primos[ind]);
        else
            cout << "falso" << endl;

    }
}