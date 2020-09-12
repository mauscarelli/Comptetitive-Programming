#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void lics(vector<int> &v, int n) {
    vector<int> dp(n), anterior(n);
    map<int, int> indice;
    int maior = INT_MIN, imax = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        anterior[i] = -1;
        if (indice.find(v[i] - 1) != indice.end()) {
            anterior[i] = indice[v[i] - 1];
            dp[i] = dp[indice[v[i] - 1]] + 1;
        }
        indice[v[i]] = i;
        if (dp[i] > maior) maior = dp[i], imax = i;
    }
    vector<int> r = {imax};
    while (anterior[imax] != -1) {
        imax = anterior[imax];
        r.push_back(imax);
    }
    reverse(r.begin(), r.end());
    cout << maior << endl;
    for (int &x : r)
        cout << x + 1 << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    lics(v, n);
	return 0;
}