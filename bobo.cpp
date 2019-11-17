#include <iostream>
 
using namespace std;
 
int main() {
    int n, c, m=0, k;
    cin >> n;
    cin >> c;
    m = c;
    for(int i = 1;i<n;i++){
        cin >> k;
        m = max(m,k);
    }
    
    (m == c) ? cout << "S" <<endl : cout << "N" <<endl; 
 
    return 0;
}