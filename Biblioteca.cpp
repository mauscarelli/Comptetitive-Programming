// g++ -static -O2 -lm
//.
#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, d, p, flag = 0;
	int alunos[101];
	while(cin>>n>>d, n && d){
		flag =0;
		memset(&alunos,1,sizeof(int) * 101);
		for(int a = 0; a<d; a++)
		{
			
			for(int b = 1; b<=n; b++){
				cin>>p;
				if(p == 0)
					alunos[b] = 0;
			}
		}
		for(int i = 1;i<=n;i++){
			if(alunos[i]){
				flag = 1;
				break;
			}
		}
			if(!flag)
				cout<<"no"<<endl;
			else
				cout<<"yes"<<endl;
	}
	
	return 0;
}
