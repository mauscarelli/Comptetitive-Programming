#include <bits/stdc++.h>

using namespace std;
vector<tuple<int, int, bool>> dom;
int fin;

int ans(int ant, int res)
{
    int d1, d2;
    for (tuple<int, int, bool> &t : dom)
    {
        d1 = get<0>(t);
        d2 = get<1>(t);
        if ((d1 == ant || d2 == ant) && get<2>(t))
        {
            //cout << ant << " " << d1 << " " << d2 <<endl;
            if (d1 == ant)
            {
                if (res == 1 && d2 == fin)
                    return 1;
                else if (res == 1)
                    return 0;
                get<2>(t) = false;
                if (ans(d2, res - 1))
                    return 1;
                get<2>(t) = true;
            }
            else if (d2 == ant)
            {
                if (res == 1 && d1 == fin)
                    return 1;
                else if (res == 1)
                    return 0;
                get<2>(t) = false;
                if (ans(d1, res - 1))
                    return 1;
                get<2>(t) = true;
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        int m;
        cin >> m;
        dom.clear();
        int d1, d2, ini;
        cin >> d1 >> ini;
        cin >> fin >> d2;
        for (int i = 0; i < m; i++)
        {
            cin >> d1 >> d2;
            dom.push_back(make_tuple(d1, d2, true));
        }
        if (ans(ini, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}