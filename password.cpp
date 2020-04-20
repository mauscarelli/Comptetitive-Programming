#include<bits/stdc++.h>

using namespace std;

string word;
vector<string> d;

void pass(string at,int q){
    if(word[q] == '#'){
        for(int i=0;i<d.size();i++){
            if(q == word.length()-1)
                cout << at+d[i] <<endl;
            else
                pass(at+d[i],q+1);
        }
    }else{
        for(int i=0;i<10;i++){
            if(q == word.length()-1)
                cout << at << i <<endl;
            else
                pass(at+to_string(i),q+1);
        }
    }
}

int main(){

    int t,m;
    while(cin >> t >>ws){
        string s;
        d.clear();
        for(int i=0;i<t;i++){
            cin >> s;
            d.push_back(s);
        }
        cin >> m >>ws;
        cout << "--" <<endl;
        for(int i=0;i<m;i++){
            cin >> word;
            pass("",0);
        }
    }

    return 0;
}