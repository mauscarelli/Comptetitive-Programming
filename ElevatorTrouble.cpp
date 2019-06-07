#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
int floors, start, goal, up, down;
int vis[MAX];//visitados
int dis[MAX];//Botoes a serem precionados
void bts(){
	int Atual, ProxUp, ProxDown;
	queue<int> fila;
	vis[start] = 1;
	dis[start] = 0;
	fila.push(start);
	while(!fila.empty()){
		Atual = fila.front(); fila.pop();
		ProxUp = Atual+up;
		ProxDown = Atual-down;
		if(ProxUp<=floors && !vis[ProxUp]){
			vis[ProxUp] = 1;
			dis[ProxUp] = dis[Atual] + 1;
			fila.push(ProxUp);
		}
		if(ProxDown>=1 && !vis[ProxDown]){
			vis[ProxDown] = 1;
			dis[ProxDown] = dis[Atual] + 1;
			fila.push(ProxDown);
		}
	}
}
int main(){
	cin >> floors >> start >> goal >> up >> down;
	dis[goal] = -1;
	bts();
	if(dis[goal] == -1)
		cout << "use the stairs" << endl;
	else
		cout << dis[goal];	
}
