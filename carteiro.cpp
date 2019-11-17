#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

int BinarySearch(int x, int e, int d, int c[]){
	int meio = (e+d)/2;
	if(x == c[meio])
		return meio;
	else if(x < c[meio])
		return BinarySearch(x,e,meio-1,c);
	else
		return BinarySearch(x,meio+1,d,c);
}

int main(){
	int n,m,v;
	cin >> n >> m;
	int c[45000];
	queue<int> p;
	for(int i=0; i<n;i++)
		cin >> c[i];
	for(int i=0; i<m ;i++){
		cin >> v;
		p.push(v);
	}
	int t=0, i=0,ia=0;
	while(!p.empty()){
			i = BinarySearch(p.front(),0,n-1,c);
			p.pop();
			t+= abs(i-ia);
			ia = i;
	}
	cout << t << endl;
}
