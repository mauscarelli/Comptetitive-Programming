#include<bits/stdc++.h>

using namespace std;
int pd[101];

int troco(int val){
	if(pd[val] != -1) return pd[val];
	int sum = val;
	if(val-20 >= 0) sum = min(sum, troco(val-20)+1);
	if(val- 10 >= 0) sum = min(sum, troco(val-10)+1);
	if(val-5 >= 0) sum = min(sum, troco(val-5)+1);
	if(val-1 >= 0) sum = min(sum, troco(val-1)+1);
	pd[val] = sum;
	//printf("%d\n",sum);
	return sum;
}

main(){
	int n;
	scanf("%d",&n);
	for(int i =0; i<=100;i++)
		pd[i] = -1;
	pd[0] = 0;
	pd[1] = pd[5] = pd[20] = pd[100] = 1;
	int c = n/100;
	n = n % 100;
	printf("%d\n", troco(n)+c);
}
