#include<bits/stdc++.h>
using namespace std;
int p[1 << 20];
int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while(n--)
	{
		char op;
		string num;
		cin >> op >> num;
		int x = 0;
		for(auto &i : num) x = (x << 1) | (i & 1);
		if(op == '+') p[x]++;
		else if(op == '-') p[x]--;
		else cout << p[x] <<endl;
	}
	//
}