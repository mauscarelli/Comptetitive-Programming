#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int main()
{
    map<char, int> m;
    map<char, int>::iterator it;
    int tabela[MAX][MAX];
    string a, b;
    string nl("\n");
    int bin, sim, sub, cse = 0;
    int variaveis;
    while (cin >> a)
    {
        cse++;
        variaveis = a.size();
        bin = sim = sub = 1;
        m.clear();
        for (int i = 0; i < variaveis; i++)
            m.insert(make_pair(a[i], i));
        for (int i = 0; i < variaveis; i++)
        {
            cin >> b;
            for (int c = 0; c < variaveis; c++)
            {
                it = m.find(b[c]);
                if (it == m.end())
                    bin = 0;
                else
                {
                    tabela[i][c] = it->second; // variavel correspondente a letra
                }
            }
        }

        if (!bin)
        {
            cout << "Case " << cse << ": The operator is not a binary operation." << endl <<endl;
            continue;
        }

        /*for(int i = 0;i<variaveis;i++){
            for(int c = 0;c<variaveis;c++)
                cout << tabela[i][c] <<" ";
            cout <<endl;
        } // Print para ver a tabela de estados. */

        //Testa comutatividade (simetria em relação a diagonal principal)
        for (int i = 1; i < variaveis; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (tabela[i][j] != tabela[j][i])
                {
                    sim = 0;
                    break; //Em c(c++) só é possivel sair do laço mais interior
                }
            }
            if (!sim)
                break;
        }

        if (sim) // se é comutativa então é associativa (suposição)
        {
            cout << "Case " << cse << ": The operator is a commutative semigroup." << endl <<endl;
            continue;
        }

        //if(variaveis > 2) // Se for apenas 2 variaveis é associativa (suposição)
        for (int x = 0; x < variaveis; x++) // Solução: O(N^3) porém N é muito pequeno (max 10)
        {
            for (int y = 0; y < variaveis; y++)
            {
                for (int z = 0; z < variaveis; z++)
                {
                    //verificar se (x @ y) @ z == x @ (y @ z)
                    // @ é o operador que retorna tabela[v1][v2]
                    if (tabela[tabela[x][y]][z] != tabela[x][tabela[y][z]])
                    {
                        sub = 0;
                        break;
                    }
                }
                if (!sub)
                    break;
            }
            if (!sub)
                break;
        }

        if (!sub)
            cout << "Case " << cse << ": The operator is not a semigroup." <<endl;
        else
            cout << "Case " << cse << ": The operator is not a commutative semigroup." <<endl;
        cout << endl;
    }

    return 0;
}