#include<bits/stdc++.h>

using namespace std;
char mat[20][20];
int cont=0;
string binaria, palavra;
vector <string> casos;
int esquerda,direita,cima,baixo;

void inicia(){
    casos.push_back("00000");
    casos.push_back("00001");
    casos.push_back("00010");
    casos.push_back("00011");
    casos.push_back("00100");
    casos.push_back("00101");
    casos.push_back("00110");
    casos.push_back("00111");
    casos.push_back("01000");
    casos.push_back("01001");
    casos.push_back("01010");
    casos.push_back("01011");
    casos.push_back("01100");
    casos.push_back("01101");
    casos.push_back("01110");
    casos.push_back("01111");
    casos.push_back("10000");
    casos.push_back("10001");
    casos.push_back("10010");
    casos.push_back("10011");
    casos.push_back("10100");
    casos.push_back("10101");
    casos.push_back("10110");
    casos.push_back("10111");
    casos.push_back("11000");
    casos.push_back("11001");
    casos.push_back("11010");
    casos.push_back("11011");
    casos.push_back("11100");
    casos.push_back("11101");
    casos.push_back("11110");
    casos.push_back("11111");
}

void agrega(){

    int i =0;
    while(i < 27 && binaria != casos[i]){
        i++;
    }
    switch (i){
        case 0:
            palavra += " ";
            break;
        case 1:
            palavra += "A";
            break;
        case 2:
            palavra += "B";
            break;
        case 3:
            palavra += "C";
            break;
        case 4:
            palavra += "D";
            break;
        case 5:
            palavra += "E";
            break;
        case 6:
            palavra += "F";
            break;
        case 7:
            palavra += "G";
            break;
        case 8:
            palavra += "H";
            break;
        case 9:
            palavra += "I";
            break;
        case 10:
            palavra += "J";
            break;
        case 11:
            palavra += "K";
            break;
        case 12:
            palavra += "L";
            break;
        case 13:
            palavra += "M";
            break;
        case 14:
            palavra += "N";
            break;
        case 15:
            palavra += "O";
            break;
        case 16:
            palavra += "P";
            break;
        case 17:
            palavra += "Q";
            break;
        case 18:
            palavra += "R";
            break;
        case 19:
            palavra += "S";
            break;
        case 20:
            palavra += "T";
            break;
        case 21:
            palavra += "U";
            break;
        case 22:
            palavra += "V";
            break;
        case 23:
            palavra += "X";
            break;
        case 24:
            palavra += "W";
            break;
        case 25:
            palavra += "Y";
            break;
        case 26:
            palavra += "Z";
            break;
        default:
            break;
    }
    binaria = "";
    cont = 0;
}
void LCB(int x,int y);
void LDE(int x,int y);
void LBC(int x,int y);

void LED(int x,int y){
    if(y > direita) return;
    while(y<=direita){
        //cout << x << " " << y << " " << mat[x][y] << endl;
        binaria += mat[x][y++];
        if(binaria.size() == 5)
            agrega();
    }
    cima++;
    LCB(x+1,y-1); 
}
void LCB(int x,int y){
    if(x > baixo) return;
    while(x<=baixo){
        //cout << x << " " << y << " " << mat[x][y] << endl;
        binaria += mat[x++][y];
        if(binaria.size() == 5)
            agrega();
    }
    direita--;
    LDE(x-1,y-1); 
}

void LDE(int x,int y){
    if(y < esquerda) return;
    while(y>=esquerda){
        //cout << x << " " << y << " " << mat[x][y] << endl;
        binaria += mat[x][y--];
        if(binaria.size() == 5)
            agrega();
    }
    baixo--;
    LBC(x-1,y+1); 
}

void LBC(int x,int y){
    if(x < cima) return;
    while(x>=cima){
        //cout << x << " " << y << " " << mat[x][y] << endl;
        binaria += mat[x--][y];
        if(binaria.size() == 5)
            agrega();
    }
    esquerda++;
    LED(x+1,y+1); 
}

int main(){
    //cout << "oi";
    inicia();
    int n, r,c;
    cin >> n;
    //cout << "eae";
    for(int i =1;i<=n;i++){
        cin >> r >> c;
        palavra = "";
        binaria = "";
        esquerda = cima = 0;
        baixo = r-1;
        direita = c-1;
        for(int l=0;l<r;l++)
            for(int col=0;col<c;col++)
                cin >> mat[l][col];
        LED(0,0);
        char c = *palavra.rbegin();
        while(c == ' '){
            //cout << "oieee";
            palavra.pop_back();
            c = *palavra.rbegin();
        }
        c = *palavra.begin();
        while(c == ' '){
            //cout << "oieee";
            palavra.erase(0,1);
            c = *palavra.begin();
        }

        cout << i << " " << palavra <<endl;
    }
}