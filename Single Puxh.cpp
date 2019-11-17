#include<bits/stdc++.h>
#define MAX 100000
using namespace std;



int main(){
    int a[MAX], b[MAX];
    int n, k,numero,t,flag,operacao;
    cin >> t;
    while(t--){
        numero = 0;
        flag = 0;
        operacao = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
            if(!flag){
                if(0 > b[i] - a[i]){
                    flag = 1;
                }
                else if(operacao == 1 && b[i]-a[i] == 0)
                    operacao = 2;
                else if(operacao == 1 && b[i]-a[i] != numero)
                    flag = 1;
                else if(operacao == 2 && b[i]-a[i] != 0)
                    flag = 1;
                else if(operacao == 0 && b[i]-a[i] !=0){
                    operacao = 1;
                    numero = b[i]-a[i];
                }
            }
            //cout << flag << " " << operacao << " "<< numero <<endl;
        }
        if(flag) cout << "NO" <<endl;
        else cout << "YES" <<endl;
    }
    

    return 0;
}