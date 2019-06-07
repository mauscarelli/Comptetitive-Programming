#include<bits/stdc++.h>

using namespace std;

int resolve(int n, int m){
	if(n == 1) return 1;
	return (resolve(n-1,m) + m-1) %n + 1;
	
}

main(){
	int n, m;
	while(cin >> n, n){
		m=1;
		while(resolve(n-1,m)+1 != 13)m++;
		cout << m <<endl;
	}
}
