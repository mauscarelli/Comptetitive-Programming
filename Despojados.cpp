#include<bits/stdc++.h>
#include<math.h>
#define MAX 1000001
using namespace std;

vector<long long int> prime;
vector<long long int> divisores;
int p[MAX];
void crivo(long long int n){
    int m = sqrt(n);
    int mi = min(n/2,(long long int) MAX-1);
    memset(p,1,sizeof(p));
    for(int i = 2;i<=mi;i++){
        if(p[i]){
            prime.push_back(i);
            //cout << i <<endl;
            for(int c = i*2; c<=mi; c += i)
                p[c] = 0;
        }
    }
}
bool ehPrimo(long long int n)
{
    int raiz = sqrt(n);
    for(int i = 2; i <= raiz; i++)
    if (n % i == 0)
    return false;
    return true;
}
int desp(long long int n){
    int i = 0;
    if(ehPrimo(n)) return 0;
    while(n>1){
        if(prime[i] > n) return 0;
        if(n%prime[i] == 0){
            n/=prime[i];
            if(n%prime[i] == 0) return 0;
        }
        i++;
    }
    return 1;
}

void div(long long int n){
    for(int i = 2; i <= n/2; i++)
        if (n % i == 0) divisores.push_back(i);
}

int main(){
    long long int n;
    cin >> n;
    if(ehPrimo(n)){
        cout << 0 <<endl;
    }else{
        crivo(n);
        div(n);
        int resp=0;
        for(long long int l: divisores)
            resp+=desp(l);
        
        cout << resp <<endl;
    }
    return 0;
}