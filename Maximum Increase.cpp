#include<bits/stdc++.h>

using namespace std;

int pd[100001], ar[100001];
int resp =0;
int resolve(int n){
	if(pd[n]) return pd[n];
	pd[n] = 1;
	for(int i = 1; i<n;i++){
		if(ar[i] < ar[n]) pd[n] = max(pd[n], resolve(i)+1);
	}
	resp = max(resp, pd[n]);
	return pd[n];
}

main(){
	int n, a;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&ar[i+1]);
		pd[i+1] = 0;
	}
	pd[1] = 1;
	resolve(n);
	printf("%d\n",resp);
}
