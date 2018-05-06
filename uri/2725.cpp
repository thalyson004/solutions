#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 100005
#define oo 1000000005
#define ii pair<int,int>
#define vii vector< pair<int,int> >
#define EPS 0.000000001
#define all(x) x.begin(),x.end()
#define ABS(x) max(x,-x)
//#define int long long

int n, k;
vii G[MAXN];
int X[MAXN], Y[MAXN];
vector< pair<int, pair<int,int> > > arestas;
int grupo[MAXN];

void limpa(){
    for(int i = 0; i <= n; i++) {
        G[i].clear();
        grupo[i] = i;
    }
    arestas.clear();
}

int custo(int a, int b){
    int dx = ABS( (X[a]-X[b]) );
    int dy = ABS( (Y[a]-Y[b]) );
    int gcd = __gcd( dx,dy )-1;
    return gcd;
}

int group(int a){ return grupo[a]==a? a : (grupo[a] = group(grupo[a]) ) ; }
int same(int a, int b){ return group(a)==group(b); }
int link(int a, int b){ grupo[a] = group(b); }

main(){
    int casos;
    scanf("%d", &casos);
    while(casos--){
        scanf("%d %d", &n, &k);
        limpa();
        for(int i = 0; i < n; i++){
            scanf("%d %d", X+i, Y+i);
            for(int j = 0; j < i; j++){
                arestas.push_back( { k*custo(i,j), {i,j} } );
            }
        }
        sort( all(arestas) );
        int peguei = 1, ans = 0;
        for(int i = 0; i< arestas.size() and peguei < n; i++){

            int a = arestas[i].second.first;
            int b = arestas[i].second.second;
            int c = arestas[i].first;
            if( !same(a,b) ){
                link(a,b);
                ans += c;
                peguei++;
            }
        }

        printf("%d\n", ans);
    }
}


/*
3

4 1
1 1
3 5
5 1
5 3

2 2
9 2
3 8

5 6
0 0
10 0
6 24
0 48
10 48
*/
