#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 100005
#define oo 1000000005
#define ii pair<int,int>
#define EPS 0.000000001
//#define int long long

int n, m;
vector< ii > G[MAXN];
int q;
int conf[MAXN];
int cor[MAXN];
int dist[MAXN];
vector<int> quais;

int alcanca(){
    priority_queue< ii > fila;
    for(int i = 1; i <= n; i++){
        dist[i] = oo;
    }

    for(int i: quais){
        fila.push( {0, i} );
        dist[ i ] = 0;
    }
    quais.clear();

    while(fila.size()){
        int c = -fila.top().first;
        int v = fila.top().second;
        fila.pop();
        if(dist[v]<c)continue;
        for(ii i : G[v]){
            int u = i.first;
            int cc = i.second;
            if( c+cc <= 600 and dist[u] > c+cc ){
                dist[u] = c+cc;
                fila.push( {-dist[u], u} );
                if(!cor[u]){
                    cor[u] = 1;
                    if(conf[u]){
                        quais.push_back( u );
                    }
                }
            }
        }
    }
    return quais.size();
}

main(){

    while( scanf("%d", &n) and n){
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            int x;
            scanf("%d", &x);
            conf[x] = 1;
        }

        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            G[a].push_back( {b, c} );
            G[b].push_back( {a, c} );
        }
        quais.push_back( 1 );
        int ans = -1;
        int i;
        for(i = 0; !cor[n] and alcanca() and !cor[n]; i++);
        if(cor[n]) ans = i;
        printf("%d\n", ans);

        for(int i = 1; i <= n; i++){
            cor[i] = 0;
            conf[i] = 0;
            G[i].clear();
        }
        quais.clear();
    }
}


/*
6
3 2 5 3
8
1 2 400
3 2 80
3 4 301
4 5 290
5 6 139
1 3 375
2 5 462
4 6 300
3
0
2
1 2 371
2 3 230
5
3 2 3 4
4
1 2 600
2 3 600
3 4 600
4 5 600
5
3 2 3 4
4
1 2 600
2 3 600
3 4 300
4 5 300
0

*/
