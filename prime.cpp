#include <bits/stdc++.h>
#define MAX 20
using namespace std;

main()
{
    int b, n, d, c, v, f;
    int r[MAX];

    while (cin >> b >> n, b && n)
    {
        f = 0;
        for (int i = 0; i < b; i++)
        {
            cin >> r[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> d >> c >> v;
            //cout << "t: " << r[c-1] << " " <<r[d-1] << endl;
            r[c - 1] += v;
            r[d - 1] -= v;
        }
        for(int i =0; i<b;i++)
            if(r[i]<0) f = 1;
        if (f)
            cout << "N" << endl;
        else
            cout << "S" << endl;
    }
};