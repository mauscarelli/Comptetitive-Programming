#include<iostream>
#include<string>

using namespace std;

int main(){
	string s, sub;
	int v=0,flag=0;
	cin >> s;
	for(int i=0; i<s.length();i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			if(sub.empty())
				sub =s[i];
			else
				sub += s[i];
	}
	
	for(int i=0, e = sub.size()-1; i < e; i++,e--){
		if(sub[i] != sub[e]){
			flag = 1;
			break;
		}
	}
	if(flag)
		cout << "N" <<endl;
	else
		cout << "S" <<endl;
	return 0;
}
