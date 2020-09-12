#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	vector<unsigned long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k % 2 == 0) {
			string s = bitset<32>(k).to_string();
			int k = 0;
			while (s[k] == '0') k++;
			s.erase(0, k);
			reverse(s.begin(), s.end());
			bitset<32> x(s);
			v[i] = x.to_ulong();
		}
		else v[i] = k;
	}
	for (int i = 0; i < n; i++) cout << v[i] << endl;
	return 0;
}