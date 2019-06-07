#include<bits/stdc++.h>

using namespace std;

int PAI[10002];
int resposta = 0;
struct no{
	int v;
	int cor;
	int corDesejada;
	vector<no*> filho;
};
typedef no* def_arvore;

no* criaNo(int vert, int cd){
	no* p = new no();
	p->v = vert;
	p->cor = 0;
	p->corDesejada = cd;
	return p;
}

void insere(def_arvore *arvore,int vert,int cd){
	if(*arvore == NULL){
		(*arvore) = criaNo(vert,cd);
		return;
	}
	stack<int> caminho;
	caminho.push(PAI[vert]);
	while(caminho.top() != 1)
		caminho.push(PAI[caminho.top()]);
	caminho.pop();
	no* q = *arvore;
	while(!caminho.empty()){
		for(int i=0;i < q->filho.size();i++){
			if(q->filho[i]->v == caminho.top()){
				q = q->filho[i];
				caminho.pop();
			}
		}
	}
	q->filho.push_back(criaNo(vert,cd));
}

void colore(def_arvore *arvore, int cor){
	(*arvore)->cor = cor;
	for(int i=0;i < (*arvore)->filho.size();i++) 
		colore( &(*arvore)->filho[i], cor);
}

void resolve(def_arvore *arvore){
	if(*arvore == NULL) return;
	if((*arvore)->cor != (*arvore)->corDesejada){
		resposta++;
		colore(&(*arvore),(*arvore)->corDesejada);
	}
	for(int i=0;i< (*arvore)->filho.size();i++) resolve( &(*arvore)->filho[i]);
}

main(){
	int n, val;
	def_arvore arvore = NULL;
	scanf("%d",&n);
	PAI[1] = 0;
	for(int i=2;i<=n;i++){
		scanf("%d",&PAI[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&val);
		insere(&arvore,i,val);
	}
	resolve(&arvore);
	printf("%d\n",resposta);
}
