#include <bits/stdc++.h>

using namespace std;

vector<int> p;
int x, y, a, b;
long long int k;

long long int calc(int m)
{
    long long int sum = 0;
    int nx = 0, ny = 0, nxy = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i % a == 0 && i % b == 0)
            nxy++;
        else if (i % a == 0)
            nx++;
        else if (i % b == 0)
            ny++;
    }
    for (int i = 0; i < nxy; i++)
        sum += p[i] * (x + y);
    for (int i = 0; i < nx; i++)
        sum += p[i + nxy] * x;
    for (int i = 0; i < ny; i++)
        sum += p[i + nxy + nx] * y;
    //cout << m <<" t: " << sum << endl;
    return sum;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        p.clear();
        int n, e;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> e;
            p.push_back(e/100);
        }
        cin >> x >> a;
        cin >> y >> b;
        if (x < y)
        {
            swap(x,y);
            swap(a,b);
        }

        cin >> k;
        sort(p.begin(), p.end(), greater<int>());
        int l = 0, r = n+1, mid,ans = n+1;
        while (r >= l)
        {
            mid = (r + l) / 2;
            if (calc(mid) >= k){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        if (ans > n)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}