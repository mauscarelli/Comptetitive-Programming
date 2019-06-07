#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, b;
	vector<int> saco;
	map<int,int> p;
	while(cin >> n >> b, n != 0 && b !=0){
		int flag=0;
		saco.clear();
		for(int i=0; i<b;i++){
			int v;
			cin >> v;
			saco.push_back(v);
		}
		sort(saco.begin(),saco.end());
		if(saco[0] == 0 && saco[b-1] == n){
			p.clear();
			for(int c=0;c<b;c++)
				for(int c2=c;c2<b;c2++){
					int v = abs(saco[c]-saco[c2]);
					if(!p.count(v))
						p[v] = 1;
				}
			for(int i=0;i<=n;i++){
				if(!p.count(i)){
					flag = 1;
					break;
				}
			}
		}else
			flag = 1;
		if(flag)
			cout << "N" <<endl;
		else
			cout << "Y" <<endl;
	}
}

