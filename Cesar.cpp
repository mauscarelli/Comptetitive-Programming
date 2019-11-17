#include<iostream>
#include<string>

using namespace std;


main(){

int t,n;
string p;

cin >> t;
for(int i=0;i<t;i++){
    cin >> p >> n;
    for(int c=0;c<p.size();c++){
        p[c]-=n;
        if(p[c] < 65)
            p[c]+=26;
    }
    cout << p <<endl;
}

return 0;
}
