// g++ -static -O2 -lm
#include <bits/stdc++.h>
using namespace std;

int main(){

	int N,M,bilhete,cont;
	
	while(1)
	{
		map<int,int> mapa;
		map<int,int>::iterator it;
		
		cin >> N >> M;
		
		if(N==0 && M == 0)
			break;
		
		for(int i = 0;i<M;i++)
		{
			cin >> bilhete;
			
			if(mapa.count(bilhete) == 1)
				mapa[bilhete]++;
			else
				mapa[bilhete] = 1;
		}
		
		cont = 0;
		
		for(it = mapa.begin();it != mapa.end(); it++)
		{
			if((it->second)>1)
				cont++;
		}
		
		cout << cont << endl;
	}
	
	return 0;
}
