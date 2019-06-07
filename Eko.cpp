#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	long long int n,m,h;
	vector<long long int> a;
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&h);
		a.push_back(h);
	}
	sort(a.begin(),a.end(),greater<long long int>());
	long long int ini=0,fim=a[0],meio,l=-1,lm;
	while(fim>=ini){
		h=0;
		meio = (ini+fim)/2;
		for(int i=0;i<a.size();i++)
			if(a[i]>meio) h+=a[i]-meio;
		if(h == m) {
			lm = meio;
			break;
		}
		else if(h < m)fim = meio-1;
		else{
			if(l == -1 || h<l){
				l = h;
				lm = meio;
			}
			ini = meio+1;
		}
	}
	printf("%lld\n",lm);
	return 0;
}
