#include <bits/stdc++.h>
using namespace std;

struct no
{
    map<char, no*> filhos;
    bool isword;
};
typedef struct no node;

node arvore;

void insereArvore(string s)
{
    node* t = &(arvore);
    map<char, node*>::iterator it;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        it = t->filhos.find(c);
        if (it != t->filhos.end())
            t = it->second;
        else
        {
            node* newnode;
            t->filhos[c] = newnode;
            cout << c <<endl;
            t = newnode;
        }
    }
    node* fim;
    fim->isword = true;
    t->filhos['$'] = fim;
}

void percorre(node* no, int prof)
{
    map<char, node*>::iterator it;
    for (it = no->filhos.begin(); it != no->filhos.end(); it++)
    {
        cout << it->first << " " << prof << endl;
        percorre(it->second, prof + 1);
    }
}

int main()
{
    cout << "oi" << endl;
    insereArvore("GATTACA");
    cout << arvore.filhos.size() << " morreu?" << endl;
    percorre(&arvore, 0);

    cout << "e agora?" << endl;
    return 0;
}