#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, m = 0;
    long long int t;
    while (cin >> n, n)
    {
        m=0; t=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            a -= m;
            t += abs(a);
            m = -a;
        }
        cout << t << endl;
    }
    return 0;
}