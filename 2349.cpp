#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#define maxN 100
#define maxC 1000
using namespace std;
int main(){
	int Pos=1, N, C , S, Comando, Resultado=0;
	cin >> N >> C >> S;
	if(S==1)
		Resultado++;
	while(C--){
		cin >> Comando;
		if(Comando==-1&&Pos==1)
			Pos=N;
		else if(Comando==1&&Pos==N)
			Pos=1;
		else
			Pos +=Comando;
		if(Pos==S)
			Resultado++;
	}
	cout << Resultado << endl;
}
