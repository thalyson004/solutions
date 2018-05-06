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
vector< int > G[MAXN];
int dist[MAXN];

int bfs(int a, int b, int c){
    for(int i = 1; i <= n; i++) dist[i] = oo;
    queue<int> fila;
    fila.push( a );
    dist[a] = 0;
    while(fila.size()){
        int v = fila.front();
        fila.pop();

        for(int u:G[v]){
            if(u!=c and dist[u]==oo){
                dist[u] = dist[v]+1;
                fila.push(u);
                if(u == b) return dist[u];
            }
        }
    }
    return dist[b];
}

main(){
    while(scanf("%d %d", &n, &m) != EOF){

        for(int i = 1; i <= m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int a, b, c;
        scanf("%d %d %d", &a, &b,&c);

        printf("%d\n", bfs(a,b,c) );

        for(int i = 1; i <= n; i++) G[i].clear();
    }
}


/*
3 1
1 3
1 3 2
5 5
1 3
3 2
1 4
4 5
5 2
1 2 3
*/
