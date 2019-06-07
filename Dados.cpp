// g++ -static -O2 -lm
#include <bits/stdc++.h>
using namespace std;

int main(){
	int p, s, t1, t2, t3, d1, d2, n;
	vector<int> pos, trap;
	while (cin >> p >> s && (p != 0 && s != 0)) {
		cin >> t1 >>  t2 >> t3 >> n;
		trap.clear(); pos.clear();
		for (int i = 0; i < p; i++) {
			trap.push_back(0);
			pos.push_back(0);
		}
		int fim = 0, jog = 0;
		while (n--) {
			cin >> d1 >> d2;
			pos[jog] += d1 + d2;
			if (pos[jog] == t1 || pos[jog] == t2 || pos[jog] == t3) trap[jog] = 1;
			if (pos[jog] > s) { fim = jog+1; break; }
			jog++;
			if (jog >= p) jog -= p;
			while (trap[jog] == 1) { 
				trap[jog] = 0;
				jog++; 
				if (jog >= p) jog -= p;
			}
		}
		cout << fim << endl;
	}
	return 0;
}
