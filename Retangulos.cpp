#include<iostream>
using namespace std;
main(){
	int n, i, j, res;
	i = j = 2;
	cin >> n;
	res = n;
	while(i*i<=n){
		while(i*j<=n){
			++res;
			++j;
		}
		j = ++i;
	}
	cout << res << endl;
}
