#include<bits/stdc++.h>

using namespace std;

int main(){
    //cout << "Oi" <<endl;
    int n, d, nota, pico,m;
    vector<int> f;
    while(cin >> n, n){
        pico = 1;
        f.clear();
        for(int i = 0;i<n;i++){
            cin >> nota;
            f.push_back(nota);
        }
        f.push_back(f[0]);
        if( (f[0] < f[n-1] && f[0] > f[1]) || (f[0] > f[n-1] && f[0] < f[1]) ) pico--;
        d = f[0] < f[1];
        for(int i = 0;i<n;i++){
            if(d != (f[i] < f[i+1])){
                d = !d;
                pico++;
            }
        }

        cout << pico <<endl;
    }
    
    return 0;
}
