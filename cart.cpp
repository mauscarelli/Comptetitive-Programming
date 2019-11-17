#include<iostream>

using namespace std;

int main(){
	int n,m,v;
	cin >> n >> m;
	int c[45000], ca[45000];
	for(int i=0; i<n;i++)
		cin >> c[i];
	for(int i=0; i<m ;i++){
		cin >> ca[i];
	}
	int t=0, i=0, e=0;
	while(e<m){
		if(ca[e] == c[i])
			e++;
		else if(ca[e] > c[i]){
			i++;
			t++;
		}else{
			t++;
			i--;
		}
	}
	cout << t << endl;
}
