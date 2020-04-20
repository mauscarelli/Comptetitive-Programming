#include<bits/stdc++.h>

using namespace std;

main(){
    int n,c,m,x,r,d;
    cin >> n;
    while (n--)
    {
        cin >> c >> m >>x;
        d = max(c,m)-min(c,m);
        x+= d; //considera-se o excesso de c ou m como x
        if(c>m)
            c-=d;
        else
            m-=d;
        r = min(x,min(c,m));
         c-=r;
         m-=r;
         x-=r;
         r+= (c+m)/3;
        cout << r <<endl;
    }
}