#include<iostream>
#define MAX 26
using namespace std;

struct Pilha{
	int topo=-1;
	char elementos[MAX];
};

void iniciaPilha(Pilha *p){
	p->topo = -1;
}

int cheia(Pilha p){
	return p.topo == MAX-1;
}

int vazia(Pilha p){
	return p.topo == -1;
}

int inserePilha(Pilha *p, char valor){
	if(cheia(*p)) return 0;
	p->elementos[++(p->topo)] = valor;
	return 1;
}

char removePilha(Pilha *p){
	if(vazia(*p)) return 0;
	return p->elementos[(p->topo)--];
}

char top(Pilha p){
	if(vazia(p)) return 0;
	return p.elementos[p.topo];
}

int main(){
	int n;
	char c, final[MAX];
	Pilha *p = new Pilha();
	Pilha *aux = new Pilha();
	
	while(cin >> n, n){
		iniciaPilha(p);
		iniciaPilha(aux);
		for(int i=0; i< n;i++){
			cin >> c;
			inserePilha(aux,c);
		}
		for(int i=0; i< n;i++){
			c = removePilha(aux);
			inserePilha(p,c);
			cin >> c;
			final[i] = c;
		}
		
		int i = 0, flag = 0;
		while(i<n){
			if(top(*aux) == final[i]){
				removePilha(aux);
				cout << "R";
				i++;
			}else if(!vazia(*p)){
				c = removePilha(p);
				inserePilha(aux,c);
				cout << "I";
			}else{
				flag = 1;
				break;
			}
		}
		if(flag)
			cout<< " Impossible";
		cout << endl;
	}
	
	return 0;
}
