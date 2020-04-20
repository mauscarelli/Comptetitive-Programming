#include<bits/stdc++.h>

using namespace std;


int main(){
    int t,b;
    bool f;
    cin >> t >> b;
    while(t--){
        int ig=-1,dif=-1,it=0,a;
        f= false;
        vector<int> vet(b,-1);
        int n=0;
        while(!f){
            for(int i=0;i<b/2 && it<150;i++){
                cout << i <<endl;
                cin >> vet[i];
                it++;
                if(it == 1){
                    i--;
                    continue;
                }else if(it%10 == 1){
                    if(ig != -1 && dif !=-1){
                        
                    }else if(ig != -1){
                        cout << ig <<endl;
                        cin >> a;
                        if(a != vet[ig])
                    }else if(dif != -1){

                    }
                }else{
                    cout << b-i-1 <<endl;
                    cin >> vet[b-i-1];
                    it++;
                    if(vet[i] == vet[b-i-1]) ig = i;
                    else dif = i;
                }
                
            }
        }
    }
    return 0;
}