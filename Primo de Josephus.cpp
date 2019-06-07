#include<bits/stdc++.h>
using namespace std;

vector<int> prime;

int josephus(int n,int m){
	if(n == 1) return 1;
	return (josephus(n-1,m+1)+prime[m]-1) % n + 1;
}

int main(){
	int p=0, n,div;
	for(int i=2;i<INT_MAX-1;i++){
		div=0;
		for(int c=2;c<=i/2;c++){
			if(i%c == 0){
				div++;
				break;
			}
		}
		if(!div) {
			prime.push_back(i);
			p++;
			if(p == 3501) break;
		}
	}
	while(cin >> n, n){
		cout << josephus(n,0) <<endl;
	}
}
