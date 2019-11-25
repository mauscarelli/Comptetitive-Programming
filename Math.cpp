#include <bits/stdc++.h>

using namespace std;

main()
{

    int t, n;
    long long ml, mr, lx, rx;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        ml = 0;
        mr = INT_MAX;
        for (int c = 0; c < n; c++)
        {
            cin >> lx >> rx;
            ml = max(ml, lx);
            mr = min(mr, rx);
        }
        cout << max(ml - mr , (long long)0) << endl;
    }
    return 0;
}