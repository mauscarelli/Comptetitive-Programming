#include<bits/stdc++.h>
#define MAX 10000

using namespace std;


int josephus(int n,int k){
	if(n == 1) return 1;
	return (josephus(n-1,k) + k-1) % n + 1;
}

main(){
	int nc,n,k;
	cin >> nc;
	for(int c=1;c<=nc;c++){
		cin >> n >> k;
		cout <<"Case " << c <<": " << josephus(n,k) <<endl;
	}
	return 0;
}
