#include <bits/stdc++.h>
using namespace std;

int PD[1001];
int grana[1001];

int resolve(int casa,int n){
	if(PD[casa]) return PD[casa];
	int maximo = 0;
	for(int i = casa+2;i<n;i++){
		maximo = max(maximo,resolve(i,n));
	}
	PD[casa] = maximo + grana[casa];
	return PD[casa];
}

int main(){
	int n;
	while (cin >> n && n != 0) {
		memset(PD,0,sizeof(int) * 1001);
		memset(grana,0,sizeof(int) * 1001);
		for(int i=0;i<n;i++)
			cin >> grana[i];
		int m = resolve(0,n);
		m = max(m,resolve(1,n));
		cout << m << endl;
	}
	return 0;
}
