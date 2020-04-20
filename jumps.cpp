#include <bits/stdc++.h>
#define MAX 10
using namespace std;
int board[MAX][MAX];
int mini;

void Back(int lin, int col, int res)
{
    board[lin][col] = 1;
    int lina, cola;
    res--;
    mini = min(mini, res);

    lina = lin - 2;
    cola = col - 1;

    if (lina >= 0 && cola >= 0 && !board[lina][cola])
    {
        Back(lina, cola, res);
    }
    cola = col + 1;
    if (lina >= 0 && cola < MAX && !board[lina][cola])
    {
        Back(lina, cola, res);
    }
    lina = lin + 2;
    if (lina < MAX && cola < MAX && !board[lina][cola])
    {
        Back(lina, cola, res);
    }
    cola = col - 1;
    if (lina < MAX && cola >= 0 && !board[lina][cola])
    {
        Back(lina, cola, res);
    }

    lina = lin - 1;
    cola = col - 2;
    if (lina >= 0 && cola >= 0 && !board[lina][cola])
    {
        Back(lina, cola, res);
    }
    cola = col + 2;
    if (lina >= 0 && cola < MAX && !board[lina][cola])
    {
        Back(lina, cola, res);
    }
    lina = lin + 1;
    if (lina < MAX && cola < MAX && !board[lina][cola])
    {
        Back(lina, cola, res);
    }
    cola = col - 2;
    if (lina < MAX && cola >= 0 && !board[lina][cola])
    {
        Back(lina, cola, res);
    }
    board[lin][col] = 0;
}

int main()
{
    int n, caso = 1;
    while (cin >> n, n)
    {
        int x = -1, y = -1, s, r, res = 0;
        memset(board, -1, sizeof board);
        for (int i = 0; i < n; i++)
        {
            cin >> s >> r;
            if (x == -1 && s != n)
            {
                y = i;
                x = s;
            }
            res += r;
            for (int c = s; c < s + r; c++)
            {
                board[i][c] = 0;
            }
        }
        mini = res;
        Back(y, x, res);
        if(mini == 1) printf("Case %d, 1 square can not be reached.\n", caso++, mini);
        else printf("Case %d, %d squares can not be reached.\n", caso++, mini);
    }
    return 0;
}