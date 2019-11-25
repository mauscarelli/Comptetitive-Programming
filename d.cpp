#include<bits/stdc++.h>
#define MAX 100002
using namespace std;

vector<int> filhos [MAX];
int visitado[MAX];
int pai[MAX];
priority_queue< pair<int,int> > folhas;

void registra(int p, int filho){
    filhos[p].push_back(filho);
    pai[filho] = p;
}

void limpa(){
    memset(visitado,0,MAX);
    memset(pai,0,MAX);
    while(!folhas.empty())
        folhas.pop();
    for(int i =0; i<MAX;i++){
        filhos[i].clear();
    }
}
int nAltura(int no){
    if(visitado[no]) return 0;
    if(no == 0) return 1;
	return 1 + nAltura(pai[no]);
}
void marca(int no){
    if(visitado[no]) return;
    visitado[no] = 1;
    marca(pai[no]);
}

void DFS(int no, int altura){
    if(filhos[no].empty()){
        folhas.push(make_pair(altura,no));
        return;
    }
    for(int i=0;i<filhos[no].size();i++)
        DFS(filhos[no][i],altura+1);
}


int main(){
    int n, k, aux;
    cin >> n >> k;
    limpa();
    for(int i=1;i<n;i++){
        cin >> aux;
        registra(aux-1,i);
    }
    DFS(0,1);
    int resposta = 0;
    //cout <<"alow" <<endl;
    while(!folhas.empty() && k>0){
        int no = folhas.top().second;
        int nA = nAltura(no);
        //cout << nA <<endl;
        if( nA == folhas.top().first){
            //cout << folhas.top().second << " " << folhas.top().first <<endl;
            resposta += folhas.top().first;
            k--;
            marca(folhas.top().second);
            folhas.pop();
        }else{
            folhas.pop();
            folhas.push(make_pair(nA,no));
        }
    }
    cout << resposta <<endl;

    return 0;
}
