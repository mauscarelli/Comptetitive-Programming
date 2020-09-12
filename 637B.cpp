#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	stack<string> q;
	cin >> n;
	map<string, bool> visitado;
	while (n--) {
		cin >> s;
		q.push(s);
		visitado[s] = 0;
	}
	while (!q.empty()) {
		string s = q.top();
		q.pop();
		if (!visitado[s])
			cout << s << endl;
		visitado[s] = 1;
	}
	return 0;
}