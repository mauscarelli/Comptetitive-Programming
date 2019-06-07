#include<bits/stdc++.h>

using namespace std;

main(){
	int t,tam, maxT;
	string s;
	cin >> t;
	for(int i = 0;i<t;i++){
		maxT = 0;
		tam = 0;
		stack<int> v;
		cin >> s;
		for(int c=0;c<s.size();c++){
			if(s[c] == 'n'){
				tam++;
				maxT= max(maxT,tam);
				v.push(c);
				v.push(c);
			}else{
				if(!v.empty()){
					int topo = v.top();
					v.pop();
					while(!v.empty() && v.top() != topo){
						topo = v.top();
						v.pop(); tam--;
					}
				}
			}
		}
		cout << maxT << endl;
	}
	return 0;
}
