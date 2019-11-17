#include<iostream>
#define max 200

using namespace std;

/*
void printMat(int m[][max], int h, int l){
	for(int i=0; i<h;i++){
		for(int i2=0;i2<l;i2++){
			cout << m[i][i2] << " ";
		}
		cout << endl;
	}
}
*/
int Grupo(int m[][max],bool vis[][max],int h, int l,int x, int y, int cor){
	if(vis[x][y] || m[x][y] != cor)
		return 0;
	vis[x][y] = true;
	int soma = 1;
	if( ((x-1) >= 0) && ((x-1) < h ))
		soma+=Grupo(m,vis,h,l,x-1,y,cor);
	if(((x+1) >= 0) && ((x+1) < h ))
		soma+=Grupo(m,vis,h,l,x+1,y,cor);
	if( ((y-1) >= 0) && ((y-1) < l ))
		soma+=Grupo(m,vis,h,l,x,y-1,cor);
	if(((y+1) >= 0) && ((y+1) < l ))
		soma+=Grupo(m,vis,h,l,x,y+1,cor);
	return soma;
}

main(){
	int h,l, menor = max*max,atual;
	int lad[max][max];
	bool vis[max][max];
	cin >> h >> l;
	for(int i=0; i<h ;i++){
		for(int i2=0; i2<l ;i2++){
			cin >> lad[i][i2];
			vis[i][i2] = false;
		}
	}
	
	for(int i=0; i<h ;i++){
		for(int i2=0; i2<l ;i2++){
			atual = Grupo(lad,vis,h,l,i,i2,lad[i][i2]);
			if(atual < menor && atual)
			 menor = atual;
		}
	}
	
	cout << menor << endl;
	
	return 0;
}
