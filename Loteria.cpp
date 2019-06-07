/* Uri -  1694 Loteria dos ponei
Thoughts and opinions:
1o passo: Crivo de erastótenes até 2499 pra pegar os primos.
2o passo: a cada entrada ver quantos primos tem em cada linha, e quantos tem em cada coluna.
3o passo: Fazer  Somatorio da Combinacao de cada linhae de cada coluna comb(m-primos,k) + comb(n-primos,k)
imprimir esse Somatorio.
*/
#include <bits/stdc++.h>
#define MAX 2500
#define MAXN 51
using namespace std;

vector<int> prime;
int p[MAX];
void crivo()
{
    memset(p, 1, sizeof(p));
    for (int i = 2; i < MAX; i++)
    {
        if (p[i])
        {
            prime.push_back(i);
            for (int c = 2; i * c < MAX; c++)
                p[c * i] = 0;
        }
    }
}

unsigned long long int bin[MAXN][MAXN];

void comb(int n, int k)
{ //Pré-calculando em O(n*k)
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                bin[i][j] = 1;
            else
                bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
        }
    }
}

int main()
{
    unsigned long long int sum;
    int m, n, k;
    crivo();
    int pl[51], pc[51];
    while (cin >> n >> m >> k, n)
    {
        memset(pl, 0, sizeof(pl));
        memset(pc, 0, sizeof(pc));
        int lin = 0;
        int last = n * m - 1;
        sum = 0;
        for (int i = 0; prime[i] <= last; i++)
        {
            while (prime[i] - lin * m > m - 1)
            {
                lin++;
                if (lin == n)
                    break;
            }
            pl[lin]++;
            pc[prime[i] - lin * m]++;
            if(i == prime.size()-1) break;
        }
        for (int i = 0; i < n; i++)
        {
            comb(m - pl[i], k);
            sum += bin[m-pl[i]][k];
        }
        if(k!=1)
            for (int i = 0; i < m; i++)
            {
            comb(n - pc[i], k);
            sum += bin[n-pc[i]][k];
            }
        cout << sum << endl;
    }
    return 0;
}