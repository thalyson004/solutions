#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 405
#define oo 1000000005
#define ii pair<int,int>
#define vii vector< ii >
#define EPS 0.000000001
int vl[4] = {1, 0, 0, -1};
int vc[4] = {0, 1, -1, 0};
#define int long long


main(){
    int n;


    cin >> n;
    int ja = 0;
    while(n--){
        if(ja)printf("\n");
        ja = 1;
        string danger[105];
        int p, s;
        cin >> p;
        for(int i = 0; i < p; i++) cin >> danger[i];
        cin >> s;
        for(int i = 0; i < s; i++){
            int ok = 1;
            string en;
            cin >> en;

            for(int j = 0; j < p and ok; j++){
                for(int k = 0; k+danger[j].size() <= en.size(); k++){
                    int mach = 1;
                    for(int w = 0; mach and w < danger[j].size();w++){
                        mach = mach and (danger[j][w] == en[k+w]);
                    }
                    if (mach and (k+danger[j].size() == en.size() or
                                  isupper( en[ k+danger[j].size() ]) ) )
                        ok = 0;
                }
            }

            printf("%s\n", ok ?"Prossiga" : "Abortar");
        }

    }
}

