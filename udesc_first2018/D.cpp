#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 1000005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long


int n;
int v[MAXN];
int cor[MAXN];
vector<int> G[MAXN];
unordered_map<int, vector<int> > mapa;

main(){
    while(scanf("%lld", &n) and n){
        int ans = 0, x;

        for(int i = 1; i <= n; i++){
            scanf("%lld", &v[i]);
            G[i].clear();
            cor[i] = 0;
            G[i] = mapa[ i - v[i] ];
            mapa[ v[i] + i ].push_back( i );
        }
        mapa.clear();
        for(int i = n; i >= 1; i--){
            vector<int> temp = mapa[ i+v[i] ];
            for(int r: temp) G[i].push_back( r );
            mapa[ i - v[i] ].push_back( i );
        }

        mapa.clear();
        queue<int> fila;
        fila.push(1);
        while(fila.size()){
            int v = fila.front();
            fila.pop();
            for(int u: G[v]){
                if(!cor[u]){
                    cor[u] = 1;
                    ans = max(ans, u-1);
                    fila.push( u );
                }
            }
        }

        printf("%lld\n", ans);
    }
}
/*
7
2 1 0 1 2 3 3
11
7 6 1 4 1 2 1 4 1 4 5
0
*/
