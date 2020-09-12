#include <bits/stdc++.h>

using namespace std;

int pancake[32], t[32];
int p;
void entry(string s)
{
    p = 0;
    string numero = "";
    for (auto x : s)
    {
        if (x == ' ')
        {
            stringstream cvrt(numero);
            cvrt >> pancake[p];
            cout << pancake[p++] << " ";
            numero = "";
        }
        else
            numero += x;
    }
    stringstream cvrt(numero);
    cvrt >> pancake[p];
    cout << pancake[p++] <<endl;
}

void flip (int *p, int x)
{
    for ( int i = 0; i <= x / 2; i++ )
        swap (p [i], p [x - i]);
}

int main()
{

    string s;
    while (getline(cin, s))
    {
        entry(s);
        for(int i=0;i<p;i++) t[i] = pancake[i];
        sort(pancake,pancake+p);
        
        int ind = p-1;
        while(ind >= 0){
            if(t[ind] != pancake[ind]){
                if(t[0]== pancake[ind]){
                    cout << p-ind << " ";
                    flip(t,ind);
                }else{
                    for(int i=0;i<p;i++){
                        if(t[i] == pancake[ind]){
                            cout << p-i <<" ";
                            flip(t,i);
                            flip(t,ind);
                        }
                    }
                }
            }
            ind--;
        }
        cout << "0" <<endl;
    }

    return 0;
}