#include <bits/stdc++.h>
#define MAX 200000
using namespace std;

vector<int> doces;

int main()
{
    int n, m,a;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        doces.push_back(a);
    }
    sort(doces.begin(), doces.end());
    long long res = 0;
    vector<long long> total(m,0);
    for (int k = 0; k < n; k++)
    {
        total[k % m] += doces[k];
        res += total[k%m];
        cout << res << " ";  
    }
    cout <<endl;
    return 0;
}