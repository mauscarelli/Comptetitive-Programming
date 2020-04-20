#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin >> t;
    while(t--){
        string r;
        cin >> n;
        bool p = true;
        if(n == 1) r = '1';
        if(n == 0) r = "01";
        while(n >1){
            for(int i=9;i>=1;i--){
                if(i == 1){
                    p = false;
                    n= 1;
                    break;
                }
                if(n%i == 0){
                    n/=i;
                    r.push_back('0'+i);
                    break;
                }
            }
        }
        reverse(r.begin(),r.end());
        if(p) cout << r <<endl;
        else cout << -1 <<endl;
    }
}