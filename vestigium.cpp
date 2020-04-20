#include<bits/stdc++.h>
#define MAX 101
using namespace std;

main(){
    int t,n, rrow, rcol, trace;
    int mat[MAX][MAX];
    cin >> t;
    for(int caso=1;caso<=t;caso++){
        set<int> num;
        cin >> n;
        trace = rrow = rcol = 0;
        for(int i=0;i<n;i++){
            for(int z =0;z<n;z++){
                cin >> mat[i][z];
            }
        }
        for(int i=0;i<n;i++) trace += mat[i][i];

        for(int i=0;i<n;i++){
            num.clear();
            for(int c=0;c<n;c++) num.insert(mat[i][c]);
            if(num.size() != n) rrow++;
            num.clear();
            for(int r=0;r<n;r++) num.insert(mat[r][i]);
            if(num.size() != n) rcol++;
        }

        printf("Case #%d: %d %d %d\n",caso,trace,rrow,rcol);
    }
}