#include<iostream>

using namespace std;

main(){
	for(int i=1;i<10000;i++){
		cout << 1 << " ";
	}
	for(int i = 0;i<10000;i++){
		if(i != 99999)cout << i+1 << " ";
		else cout << i+1 <<"\n";
	}
}
