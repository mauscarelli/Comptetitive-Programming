#include <bits/stdc++.h>
using namespace std;

int lps[1000000], vis[1000000] = {0};

void kmp(string s)
{
    lps[0] = -1;
    int k = -1, j = 0;
    while (j < s.size())
        if (k == -1 || s[j] == s[k])
            lps[++j] = ++k;
        else
            k = lps[k];
    lps[0] = 0;
    for (int i = 0; i < s.size(); i++)
        vis[lps[i]] = 1;
    bool flag = false;
    int i = s.size();
    while (lps[i])
    {
        if (vis[lps[i]])
        {
            for (j = 0; j < lps[i]; j++)
                cout << s[j];
            flag = true;
            break;
        }
        i = lps[i];
    }
    if (flag)
        cout << endl;
    else
        cout << "Just a legend" << endl;
}

int main()
{
    string s;
    cin >> s;
    kmp(s);
}