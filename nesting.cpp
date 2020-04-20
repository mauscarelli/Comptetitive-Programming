#include <bits/stdc++.h>

using namespace std;

main()
{
    int t, n, num, caso = 1;
    string s;
    cin >> t >> ws;
    while (t--)
    {
        n = 0;
        string res;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            num = s[i] - '0';
            if (num > n)
            {
                for (int c = 0; c < num - n; c++)
                    res.push_back('(');
                n = num;
            }
            else if (num < n)
            {
                for (n; n > num; n--)
                    res.push_back(')');
            }
            res.push_back(s[i]);
        }
        for (n; n > 0; n--)
            res.push_back(')');

        cout << "Case #" << caso++ << ": " << res << endl;
    }
}