#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y,r,l;
    while(cin >> x >> y){
        r = y-x;
        x=0;
        l=0;
        while(x<y){
            x+=r;
            l++;
        }
        cout << l <<endl;
    }

    return 0;
}