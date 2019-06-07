//#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
int teste;
typedef struct no_arvore{
		 char info;
         struct no_arvore* esq;
         struct no_arvore* dir;
         } *def_arvore;

int infixo(def_arvore arvore, int teste){

    if (arvore != NULL){
        int a = infixo(arvore->esq,teste);
        if(!a&&!teste)
	        printf("%c",arvore->info);
		else
			printf(" %c",arvore->info);
		teste++;
        infixo(arvore->dir,1);
        return 1;
	}
	return 0;
}

void prefixo(def_arvore arvore, int teste){

    if (arvore != NULL){
    	if(teste==0)
	        printf("%c",arvore->info);
	    else
	    	printf(" %c",arvore->info);
        prefixo(arvore->esq,1);
        prefixo(arvore->dir,1);}
}

int posfixo(def_arvore arvore){

    if (arvore != NULL){
        int a = posfixo(arvore->esq);
        int b = posfixo(arvore->dir);
		if(!a&&!b&&!teste){
			printf("%c",arvore->info);
			teste = 1;
		}
	    else
	    	printf(" %c",arvore->info);
	    return 1;
	}
	else
		return 0;
}

void insere_arvore(def_arvore *arvore, char valor){

     if(*arvore!=NULL){
        if ((*arvore)->info > valor) insere_arvore(&((*arvore)->esq),valor);
        else if ((*arvore)->info < valor) insere_arvore(&((*arvore)->dir),valor);
		}
     else{
          *arvore=(def_arvore)malloc(sizeof(struct no_arvore));
          (*arvore)->info = valor;
          (*arvore)->esq = NULL;
          (*arvore)->dir = NULL;}
}

int busca(def_arvore arvore, char valor){
     if (arvore==NULL) return 0;
     if (arvore->info == valor) return 1;
     if (valor < arvore->info)
     		return busca(arvore->esq,valor);
     if (valor > arvore->info)
     		return busca(arvore->dir,valor);
}

int main(){
	def_arvore arvore;
    string s;
    char c;
    arvore = NULL;
    while(cin >> s){
    	if(s.compare("INFIXA") == 0){
			infixo(arvore, 0);
			cout << endl;
		}
		else if(s.compare("PREFIXA") == 0){
    		prefixo(arvore, 0);
    		cout << endl;
		}
		else if(s.compare("POSFIXA") == 0){
			teste = 0;
    		posfixo(arvore);
    		cout << endl;
		}
		else if(s[0]=='I'){
			cin >> c;
			insere_arvore(&arvore,c);	
		}
    	else if(s[0]=='P'){
    		cin >> c;
			if(busca(arvore,c))
    			cout << c << " existe" << endl;
    		else
    			cout << c << " nao existe" << endl;
		}
	}
    return 0;
}
