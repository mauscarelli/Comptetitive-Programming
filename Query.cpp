#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	char q;
	string e;
	map<string,int> ms;
	map<string,int>::iterator it;
	cin >> n;
	for(int i = 0; i<n;i++){
		cin >> q >> e;
		if(q == '+'){
			if(ms.count(e))
				ms[e]++;
			else
				ms[e] = 1;
		}else if(q == '-'){
			ms[e]--;
		}else if(q == '?'){
			int cont = 0;
			for(it = ms.begin(); it != ms.end(); it++){
				int flag = 0;
				string t = it->first;
				while(t.size() < e.size())
					t= '0' + t;
				for(int c = e.size()-1, d = t.size()-1; c>=0; c--,d--){
					if(e[c] != (t[d]%2)+48){
						flag = 1;
						break;
					}
				}
				if(!flag)
					cont += it->second;
				//cout << it->second << endl;
			}
			cout << cont <<endl;
		}
	}
}
