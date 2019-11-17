#include <iostream>
 
using namespace std;
 
int main() {
 
    int n,w=0,p;
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> p;
    	if(p != 1)
    		w++;
	}
 	cout << w << endl;
    return 0;
}
