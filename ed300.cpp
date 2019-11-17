#include<iostream>

using namespace std;

struct No{ int Dado; struct No* prox;};

int main(){
	struct No *L, *I; int n;
	scanf("%d",&n);
	if(n==0) L = NULL;
	else{
		L = new No;	L->Dado = n--;
		L->prox = NULL;
		for(;n>0;){
			I = new No; I->Dado = n--;
			I->prox = L; L=I;}}
	while(L != NULL){
		printf("%d",L->Dado); L = L->prox;}
	return 0;
}
