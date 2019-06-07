#include<iostream>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

main(){
	
	string s;
	while(cin >> s){
		map<char,int> oc;
		map<char,int>::iterator it;
		int t = s.size();
		for(int i =0; i<t; i++){
			if(oc.count(s[i]))
				oc[s[i]]++;
			else
				oc[s[i]] = 1;
		}
		int impares = 0;
		for(it = oc.begin();it != oc.end();it++){
			if(it->second % 2){
				impares++;
			 	if(s.size() % 2 ==0){
			 		impares = 2;
					 break;
				}
			}
		}
		if(impares > 1)
			cout << "-1" <<endl;
		else
			cout << "1" <<endl;
	}
	return 0;
}
