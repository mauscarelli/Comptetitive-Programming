#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int maior = 1;

int PD[MAX] = {};

main(){
	//Vou apelar pra PD entao 
	int n,val, seq;
	scanf("%d",&n);
	for(int i =0; i<n;i++){
		seq = 1;
		scanf("%d",&val);
		PD[val] = PD[val-1] + 1;
		maior = max(maior,PD[val]);
	}
	printf("%d\n",maior);
}
