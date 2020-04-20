#include <bits/stdc++.h>
using namespace std;

map<tuple<int, int, int>, char> pos;

int bfs(int tx, int ty)
{
    queue<tuple<int, int, int>> mov;
    int x, y, m;
    mov.push(make_tuple(0, 0, 1));
    while (!mov.empty())
    {
        x = get<0>(mov.front());
        y = get<1>(mov.front());
        m = get<2>(mov.front());
        mov.pop();
        if (x == tx && y == ty)
            return m;
        if (m >= 512)
            continue;
        if (pos.find(make_tuple(x + m, y, m * 2)) == pos.end())
        {
            pos[make_tuple(x + m, y, m * 2)] = 'E';
            mov.push(make_tuple(x + m, y, m * 2));
        }
        if (pos.find(make_tuple(x - m, y, m * 2)) == pos.end())
        {
            pos[make_tuple(x - m, y, m * 2)] = 'W';
            mov.push(make_tuple(x - m, y, m * 2));
        }
        if (pos.find(make_tuple(x, y + m, m * 2)) == pos.end())
        {
            pos[make_tuple(x, y + m, m * 2)] = 'N';
            mov.push(make_tuple(x, y + m, m * 2));
        }
        if (pos.find(make_tuple(x, y - m, m * 2)) == pos.end())
        {
            pos[make_tuple(x, y - m, m * 2)] = 'S';
            mov.push(make_tuple(x, y - m, m * 2));
        }
    }
    return -1;
}

main()
{
    int t, tx, ty, q;
    char a;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        string res;
        pos.clear();
        cin >> tx >> ty;
        q = bfs(tx, ty);
        if (q != -1)
        {
            while (q > 1)
            {
                a = pos[make_tuple(tx, ty, q)];
                res.push_back(a);
                q /= 2;
                if (a == 'N')
                    ty -= q;
                else if (a == 'S')
                    ty += q;
                else if (a == 'E')
                    tx -= q;
                else
                    tx += q;
            }
            reverse(res.begin(), res.end());
            printf("Case #%d: ", c);
            cout <<res <<endl;
        }
        else
            printf("Case #%d: IMPOSSIBLE\n", c);
    }
}