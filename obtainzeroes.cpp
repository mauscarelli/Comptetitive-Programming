#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, flag;
    long long a, b, x, mini, maxi;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        mini = min(a, b);
        maxi = max(a, b);
        flag = 1;
        if (mini * 2 < maxi)
            flag = 0;
        if (flag)
            while (mini || maxi)
            {
                x = mini;
                while (x * 2 > maxi)
                {
                    x=x/2;
                }
                mini -= x;
                maxi -= 2 * x;
                if ((mini == 1 && maxi == 1) || (!mini && maxi) || (mini && !maxi))
                {
                    flag = 0;
                    break;
                }
                if (mini > maxi)
                {
                    x = maxi;
                    maxi = mini;
                    mini = x;
                }
            }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}