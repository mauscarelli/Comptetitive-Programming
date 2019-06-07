#include<iostream>

using namespace std;

main(){
	long long int x,y,sum;
	while(cin >> x >> y){
		sum = ((~x & y) | (x & ~y));
		cout << sum <<endl;
	}
	return 0;
}
