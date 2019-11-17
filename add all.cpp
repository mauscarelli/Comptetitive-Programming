#include<iostream>
#include<bits/stdc++.h>

using namespace std;

main(){
	int n, c;
	priority_queue<int> heap;
	while(cin >> n, n){
		int x,y;
		for(int i=0;i<n;i++){
			cin >> c;
			heap.push(-c);
		}
		c=0;
		while(!heap.empty()){
			x= -heap.top();
			heap.pop();
			if(heap.empty())
				break;
			y = -heap.top();
			heap.pop();
			c+=x+y;
			heap.push(-x-y);
		}
		cout << c <<endl;
	}
}
