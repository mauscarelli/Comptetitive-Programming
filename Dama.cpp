#include<bits/stdc++.h>

using namespace std;

int diagonal(int x,int y,int a,int b){
	if(abs(x-a) == abs(y-b)) return 1;
	return 0;
}

main(){
	int x,y,a,b;
	while(cin >> x >> y >> a >> b,x){
		if(x == a && y ==b) cout << 0 <<endl;
		else if(x == a || y==b ||diagonal(x,y,a,b)) cout << 1 <<endl;
		else cout << 2 <<endl;
	}
}
