#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, res = 0;
    long long a, b, diff;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        diff = abs(a - b);
        res = diff / 5;
        diff = diff % 5;
        res += diff / 2;
        diff = diff % 2;
        res += diff;
        cout << res << endl;
    }

    return 0;
}