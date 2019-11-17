#include <bits/stdc++.h>
#define MAX 100000
#define MAXA 1000001
using namespace std;

int main()
{
    int ocup = 0;
    int n, d = 0, flag = 0, a;
    cin >> n;
    int dias[MAX];
    memset(dias, 0, MAX);
    map<int, pair<bool, int>> funcionario;
    map<int, pair<bool, int>>::iterator it;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (!flag)
        {
            if (a < 0)
            {
                a = -a;
                it = funcionario.find(a);
                if (it == funcionario.end() || it->second.first != true)
                    flag = 1;
                else
                {
                    ocup--;
                    it->second.first = false;
                    dias[d] += 1;
                }
            }
            else
            {
                it = funcionario.find(a);
                if (it != funcionario.end())
                {
                    if (it->second.first != false || it->second.second == d)
                        flag = 1;
                    else
                    {
                        ocup++;
                        it->second.first = true;
                        dias[d] += 1;
                        it->second.second = d;
                    }
                }else{
                    funcionario.insert(make_pair(a,make_pair(true,d)));
                    dias[d] += 1;
                    ocup++;
                }
            }
            if (!ocup)
            {
                d++;
            }
        }
    }
    if (flag || ocup)
        cout << -1 << endl;
    else
    {
        cout << d << endl;
        for (int i = 0; i < d; i++)
            if (i != d - 1)
                cout << dias[i] << " ";
            else
                cout << dias[i] << endl;
    }
    return 0;
}