#include<iostream>

using namespace std;

main(){
	int i, im, f, fm, t;
	cin >> i >> im >> f >> fm;
	if(i == f) t = 24;
	else if(i < f){
		if(im > fm) t = f-i-1;
		else t = f-i;
	}
	else t = 24 - i + f;
	printf("O JOGO DUROU %d HORA(S) ",t);
	if(im == fm) t = 0;
	else if(im < fm) t = fm - im;
	else t = 60-im+fm;
	printf("E %d MINUTO(S)\n",t);
}
