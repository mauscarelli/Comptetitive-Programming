#include<iostream>
#include<bits/stdc++.h>

using namespace std;

main(){
	int t,n,c;
	cin >> t;
	while(t--){ 
		cin >> n >> c;
		long long int v;
		vector<long long int> x;
		for(int i=0; i<n;i++){
			cin >> v;
			x.push_back(v);
		}
		sort(x.begin(),x.end());
		long long int vc,uv, e=0,d=x[n-1],mdis=0,dis;
		while(d >= e){
			long long int m = (e+d)/2;
			vc = 1;
			uv = 0;
			dis = x[n-1]+1;
			for(int i=1;i<n;i++){
				if(x[i] - x[uv] >= m){
					dis = min(dis,x[i]-x[uv]);
					uv = i;
					vc++;
				}
			}
			if(vc >= c){
				mdis = max(mdis,dis);
				e = dis+1;
			}else{
				d = m-1;
			}
		}
		cout << mdis << endl;
	}
	return 0;
}
