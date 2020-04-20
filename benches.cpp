#include<bits/stdc++.h>


using namespace std;

main(){
    int n,m,a,maxi=0;
    double soma = 0;
    cin >> n >>m;
    for(int i=0;i<n;i++){
        cin >>a;
        soma+= a;
        maxi = max(maxi,a);
    }
    soma+=m;
    cout << max(maxi,(int)ceil(soma/n)) << " " << maxi+m <<endl;
}