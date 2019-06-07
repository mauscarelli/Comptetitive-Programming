#include<bits/stdc++.h>

using namespace std;
int n;
int quadrant(int ex,int ey,int ox,int oy){
	if(ox > ex){
		if(oy > ey) return 1;
		else return 4;
	}else{
		if(oy > ey) return 2;
		else return 3;
	}
}

main(){
	int ax,ay,bx,by,cx,cy;
	cin >> n;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;
	if(quadrant(ax,ay,bx,by) == quadrant(ax,ay,cx,cy)){
		cout << "YES";
	}
	else cout << "NO"<<endl;
}
