// g++ -static -O2 -lm
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, x;
	while(cin >> n, n){
		int joao = 0;
		stack<int> vp,vi,ap,ai;
		for(int i = 0;i<n;i++){
			cin >> x;
			if(x % 2) ai.push(x);
			else ap.push(x);
		}
		for(int i = 0;i<n;i++){
			cin >> x;
			if(x % 2) vi.push(x);
			else vp.push(x);
		}
		while(!vi.empty() && !ap.empty()){
			joao++;
			vi.pop();
			ap.pop();
		}
		while(!vp.empty() && !ai.empty()){
			joao++;
			vp.pop();
			ai.pop();
		}
		cout << n-joao <<endl;
	}
	return 0;
}
