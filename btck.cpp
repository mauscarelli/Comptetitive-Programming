#include <bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n[10], a[10], k;
        for (int i = 0; i < 10; i++)
        {
            a[i] = i;
            cin >> n[i];
        }
        cin >> k;
        bool r = false;

        do
        {
            int sum = 0;
            for (int i = 0; i < 10; i++)
            {
                sum += n[i] * a[i];
            }
            if (sum <= k)
            {
                r = true;
                break;
            }
        } while (next_permutation(a, a + 10));
        if (r)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << a[i] << " ";
            }
        }
        else
            cout << "-1";
        cout << endl;
    }
}