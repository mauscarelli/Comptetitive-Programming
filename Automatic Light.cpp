#include<bits/stdc++.h>

using namespace std;


vector<int> ti, to;
int menor = INT_MAX;
int BS(int e, int d){
	if(e>d) return menor;
	int m = (d+e)/2;
	int ii = 0;
	for(int io = 0; io<to.size();io++){
		while(to[io]-ti[ii] > m){
			ii++;
			if(ii > ti.size()-1 || ti[ii] > to[io]) {
				BS(m+1,d);
				return menor;
			}
		}
	}
	menor = min(menor,m);
	BS(e,m-1);
	return menor;
}

int main(){
	
	int n, tempo;
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> tempo;
		ti.push_back(tempo);
		cin >> tempo;
		to.push_back(tempo);
	}
	
	sort(ti.begin(),ti.end());
	sort(to.begin(),to.end());
	int fi= ti[0], lo = to[n-1];
	menor = lo-fi;
	BS(fi,lo);
	cout << menor <<endl;
	
	return 0;
}
