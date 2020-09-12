#include <bits/stdc++.h>
#define ll long long
#define INF (ll)(1 << 30)
using namespace std;

vector<int> cuts;

ll memo[1010][1010];
ll dp(int l, int r) {
   ll &ans = memo[l][r];
   if (ans != -1) return ans;

   ans = INF;
   for (int cut : cuts)
      if (cut > l && cut < r)
         ans = min(ans, (ll) r-l + dp(cut, r) + dp(l, cut));

   if (ans == INF)  // nao tem corte no intervalo [l .. r]
      ans = 0ll;    // caso base

   return ans;
}

int main() {
   while (true) {
      int len; cin >> len;
      if (len == 0) return 0;

      int N; cin >> N;
      cuts.resize(N);
      for (int &cut : cuts) cin >> cut;

      memset(memo, -1ll, sizeof memo);
      printf("The minimum cutting is %ld.\n", dp(0, len));
   }
}

