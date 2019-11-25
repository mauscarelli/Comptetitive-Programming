#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int places[MAX][MAX];
int sistema[MAX];
int placar[MAX];

void clear()
{
    memset(places, 0, sizeof(places));
    memset(sistema, 0, MAX);
    memset(placar, 0, MAX);
}

int main()
{
    int g, p, s, k, e;

    while (cin >> g >> p, g && p)
    {
        clear();
        for (int i = 0; i < g; i++)
        {
            for (int j = 0; j < p; j++)
                cin >> places[j][i];
        }
        cin >> s;
        for(int i = 0; i < s;i++){
            memset(placar,0,MAX);
            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> sistema[j];
            }
            for(int l = 0; l < p; l++ ){
                for(int c = 0; c < g; c++){
                    if(places[l][c] <= k)
                        placar[l] += sistema[places[l][c]-1];
                }
            }
            
        }
    }

    return 0;
}