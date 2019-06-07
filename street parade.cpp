#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	while(cin >> n,n){
		queue<int> q;
		stack<int> s;
		for(int i =0;i<n;i++){
			cin >> m;
			q.push(m);
		}
		int c=1;
		while(c != n+1){
			if(!q.empty() && q.front() == c){
				c++;
				q.pop();
			}else if(!s.empty() && s.top() == c){
				c++;
				s.pop();
			}else if(!q.empty()){
				s.push(q.front());
				q.pop();
			}else{
				break;
			}
		}
		if(c == n+1)
			cout << "yes" <<endl;
		else
			cout << "no" <<endl;
	}
}
