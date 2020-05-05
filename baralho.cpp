#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e,c;
    while(cin >> n){
        n/=2;
        e=0;
        c=1;
        do{
            if(c<n+1)
                c*=2;
            else
                c= c - (2*n+1 - c);
            e++;
        }while(c != 1);

        cout << e <<endl;

    }
    return 0;
}