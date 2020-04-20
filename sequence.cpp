#include <bits/stdc++.h>
#define MAX 2000000000
using namespace std;

string seq;

main()
{
    unsigned int r=1,t,n;
    while (seq.length() < MAX)
    {
        for(unsigned int i=1;i<=r;i++)
            seq += to_string(i);
        r++;
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << seq[n-1] <<endl;
    }
    
}