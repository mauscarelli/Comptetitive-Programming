#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int PAI[10001];
struct no{
	int v;
	int maxSeq;
	no *esq;
	no *cen;
	no *dir;
};
typedef no* def_arvore;

no* criaNo(int val,int seq){
	no* p = new no();
	p->v = val;
	p->maxSeq = seq+1;
	p->esq = NULL;
	p->cen = NULL;
	p->dir = NULL;
	return p;
}

void insere(def_arvore *arvore,int i,pair<int,int> v, int can){
	if((*arvore) == NULL){
		(*arvore) = criaNo(i,0);
		if(v.first)
			if(can) (*arvore)->esq = criaNo(v.first,0);
			else	(*arvore)->cen = criaNo(v.first,(*arvore)->maxSeq);
		if(v.second)
			if(can) (*arvore)->cen = criaNo(v.second,(*arvore)->maxSeq);
			else (*arvore)->dir = criaNo(v.second,0);
		return;
	}
	if(!v.first && !v.second) return;
	stack<int> caminho;
	caminho.push(i);
//	cout << "a";
	while(PAI[caminho.top()] != 1)
		caminho.push(PAI[caminho.top()]);
	no* q = *arvore;
	while(!caminho.empty()){
	//	cout << caminho.top() << "   "<< q->v <<endl;
		if(q->esq){
			if(q->esq->v == caminho.top()){
				caminho.pop();
				q = q->esq;
			}
		}
		if(q->cen){
			if(q->cen->v == caminho.top()){
				caminho.pop();
				q = q->cen;
			}
		}
		if(q->dir){
			if(q->dir->v == caminho.top()){
				caminho.pop();
				q = q->dir;
			}
		}
	}
	if(v.first)
		if(can) q->esq = criaNo(v.first,0);
		else	q->cen = criaNo(v.first,q->maxSeq);
	if(v.second)
		if(can) q->cen = criaNo(v.second,q->maxSeq);
		else q->dir = criaNo(v.second,0);
	return;
}
int teste = 0;
int getMaxSeq(def_arvore ar,int *minRaiz,int alt){
	if(ar == NULL)return 0;
	int maxSequence = ar->maxSeq;
	if(!teste && alt){
		(*minRaiz)++;
	}
	if(alt && ar->cen == NULL) teste = 1;
	maxSequence = max(maxSequence,getMaxSeq(ar->esq,minRaiz,0));
	maxSequence = max(maxSequence,getMaxSeq(ar->cen,minRaiz,alt));
	maxSequence = max(maxSequence,getMaxSeq(ar->dir,minRaiz,0));
	return maxSequence;
}

void Pre(def_arvore arvore){
	if(arvore == NULL) return;
	cout << " " << arvore->maxSeq;
	Pre(arvore->esq);
	Pre(arvore->cen);
	Pre(arvore->dir);
}
void In(def_arvore arvore){
	if(arvore == NULL) return;
	In(arvore->esq);
	cout << " " << arvore->maxSeq;
	In(arvore->cen);
	In(arvore->dir);
}
void Pos(def_arvore arvore){
	if(arvore == NULL) return;
	Pos(arvore->esq);
	Pos(arvore->cen);
	Pos(arvore->dir);
	cout << " " << arvore->maxSeq;
}

main(){
	int n,m,i,l,k;
	def_arvore can = NULL;
	def_arvore des = NULL;
	pair<int,int> col[10001];	
	cin >> n;
	for(int c=0;c<n;c++){
		cin >> i >> l >> k;
		PAI[l] = i;
		PAI[k] = i;
		col[i] = make_pair(l,k);
	}
	for(int c=1;c<=n;c++){
		insere(&can,c, col[c],1);
	}
	int mA,mrA=0;
	mA = getMaxSeq(can,&mrA,1);
	teste =0;
	cin >> m;
	for(int c=0;c<m;c++){
		cin >> i >> l >> k;
		PAI[l] = i;
		PAI[k] = i;
		col[i] = make_pair(l,k);
	}
	for(int c=1;c<=m;c++){
		insere(&des,c , col[c],0);
	}
	int mB,mrB=0;
	mB = getMaxSeq(des,&mrB,1);
	int minimo = m+n-1;
	if(mA >= mrB){
		minimo = min(minimo,m+n-mrB);
	}else{
		minimo = min(minimo,m+n-mA);
	}
	if(mB >= mrA){
		minimo = min(minimo,m+n-mrA);
	}else{
		minimo = min(minimo,m+n-mB);
	}
	cout << minimo <<endl;
	return 0;
}
