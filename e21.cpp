#include<iostream>

using namespace std;

int main()
{
    char sinal;
    int n,i;
    long long int x,total,sorvetes;
    int criancas_perigo;

    cin >> n >> x;

    total = x;
    criancas_perigo = 0;

    for(i=0;i<n;i++)
    {
        cin >> sinal >> sorvetes;

        if(sorvetes != 0)
        {
            if(sinal == '+')
                total = total + sorvetes;

            if(sinal == '-')
            {
                if(total>=sorvetes)
                    total=total-sorvetes;
                else
                    criancas_perigo++;
            }
        }

    }

    cout << total << " " << criancas_perigo << endl;

    return 0;
}
