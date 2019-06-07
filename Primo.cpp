#include<iostream>
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

main(){

	int t;
	long long int v;
	cin >> t;
	for(int c=0;c<t;c++){
		scanf("%lld",&v);
		int flag = 0;
		for(long long int i=2;i<=v/2;i++){
			if(v%i == 0){
				flag =1;
				break;
			}
		}
		if(flag)
			cout << "NO" <<endl;
		else
		cout << "YES" << endl;
	}
	
	return 0;
}
