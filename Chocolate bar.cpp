#include<bits/stdc++.h>

using namespace std;
int pd[10000];
int res;

int resolve(int n, int m, int k,int at){
	if(k > n*m/2) k = n*m-k;
	if(n*m == k) return at;
	int custo = 100000;
	for(int i=1;i<n;i++){
		if(n-i > m) custo = min(custo, (n-i) * (n-i) + resolve(n-i,m,k,at));
		else custo = min(custo, m*m + resolve(n-i,m,k,at));
	}
	for(int i=1;i<m;i++){
		if(m-i > n) custo = min(custo, (m-i) * (m-i) + resolve(n,m-i,k,at));
		custo = min(custo, n*n + resolve(n,m-i,k,at));
	}
	cout << custo << " ";
	at += custo;
	return at;
}

main(){
	int t,n,m,k;
	scanf("%d",&t);
	for(int i =0; i<101;i++)
		pd[i] = -1;
	for(int i =0; i<t;i++){
		scanf("%d %d %d",&n,&m,&k);
		pd[1] = 1;
		printf("%d\n", resolve(n,m,k,0));
	}
}
