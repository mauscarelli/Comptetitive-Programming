#include<iostream>
#include<string>
#define MAX 10000 //pode até 1000 caracteres na string de entrada
using namespace std;

struct Pilha{
	int topo=-1;
	int elemento[MAX];
};

int vazia(Pilha p){
	return p.topo == -1; // se o topo for igual a -1 então tá vazia, retorna verdadeiro, se não retorna falso 
}

int cheia(Pilha p ){
	return (p.topo == MAX-1); // se o topo for igual a MAX-1(limite), tá cheia e retorn verdadeiro, se não falso;
}

int empilha(Pilha *p, int n){
	if(cheia(*p)) return 0;
	p->elemento[++(p->topo)] = n;
	return 1;
}

int desempilha(Pilha *p){
	if(vazia(*p)) return 0;
	p->topo--;
	return 1;
}

void esvaziar(Pilha *p){
	p->topo = -1;
}

void printaPilha(Pilha p){
	for(int i=0;i<=p.topo;i++){
		cout << p.elemento[i];
	}
	cout << endl;
}

int main(){
	string s;
	Pilha *p = new Pilha(); // iniciação de uma struct pilha generica;
	while(cin >> s){
		int f;
		esvaziar(p);
		for(int i = 0; i<s.length();i++){
			if(s[i] == '(')
				empilha(p,1);
			else if(s[i] == ')'){
				f = desempilha(p);
				if(!f)
					break;
			}
		}
		if(!f || !vazia(*p))
			cout << "incorrect" << endl;
		else
			cout << "correct" << endl;
	}
	return 0;
}
