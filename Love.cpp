#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int binToDec(string b){
    int d=0;
    for(int i = b.size();i>=0;i--){
        if(b[i] == '1'){
            d+= pow(2,b.size()-i-1);
        }
    }
    return d;
}

int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main(){
    int t,ai,bi;
    string a,b;
    cin >> t;
    fflush(stdin);
    for(int i = 1;i <= t;i++){
        cin >> a;
        cin >> b;
        ai = binToDec(a);
        bi = binToDec(b);
        if(gcd(ai,bi) != 1){
            printf("Pair #%d: All you need is love!\n",i);
        }else
        {
            printf("Pair #%d: Love is not all you need!\n",i);
        }
        

    }
    return 0;
}