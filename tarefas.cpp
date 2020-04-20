#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

main()
{
    int t, n, s, e, caso = 1;
    cin >> t;
    while (t--)
    {
        vector<tuple<int, int, int> > atv;
        bool f = true;
        char res[MAX];
        int j = 0, c = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> e;
            atv.push_back(make_tuple(s, e, i));
        }
        sort(atv.begin(), atv.end());
        for(int i=0 ;i<n;i++){
            tie(s,e,ignore)= atv[i];
            if(s >= c){
                c = e;
                res[get<2>(atv[i])] = 'C';
            }else if(s >= j){
                j = e;
                res[get<2>(atv[i])] = 'J';
            }else{
                f = !f;
                break;
            }
        }
        res[n] = '\0';
        printf("Case #%d: ", caso++);
        f ? cout << res << endl : cout << "IMPOSSIBLE" << endl;
    }
}