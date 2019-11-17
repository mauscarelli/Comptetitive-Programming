#include <iostream>
 
using namespace std;
 
int main() {
 
    int n;
    while(cin >> n, n){
            int soma=0;
            while(n){
                soma += n*n;
                n--;
            }
            cout << soma <<endl;
    }
 
    return 0;
}
