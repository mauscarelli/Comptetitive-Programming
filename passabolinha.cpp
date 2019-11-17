#include<iostream>
#define MAX 100
using namespace std;

//pos - 1 cima , 2 direita, 3 baixo, 4 esquerda;

int jogo(int mat[MAX][MAX], int b[MAX][MAX], int l,int c, int n, int pos){
	int soma = 1, v = mat[l][c];
	b[l][c] = 1;
	for(int i = 0; i<4;i++){
		if(++pos == 5) pos = 1;
		if(pos == 1 && l+1 < n && !b[l+1][c] && mat[l+1][c] >= v)
			soma += jogo(mat,b,l+1,c,n,3);
		else if(pos == 2 && c+1 < n && !b[l][c+1] && mat[l][c+1] >= v)
			soma += jogo(mat,b,l,c+1,n,4);
		else if(pos == 3 && l-1 >= 0 && !b[l-1][c] && mat[l-1][c] >= v)
			soma += jogo(mat,b,l-1,c,n,1);
		else if(pos == 4 && c-1 >= 0 && !b[l][c-1] && mat[l][c-1] >= v)
			soma += jogo(mat,b,l,c-1,n,2);
	}
	return soma;
}

main(){
	int n, i,j;
	int mat[MAX][MAX];
	int b[MAX][MAX];
	cin >> n >> i >> j;
	for(int l=0;l<n;l++){
		for(int c=0;c<n;c++){
			cin >> mat[l][c];
			b[l][c] = 0;
		}
	}
	cout << jogo(mat,b,i-1,j-1,n,1) << endl;
}
