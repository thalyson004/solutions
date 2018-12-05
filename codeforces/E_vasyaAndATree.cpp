#include <bits/stdc++.h>
using namespace std;

//tipos
#define int long long
#define ll long long
#define ull unsigned long long
#define ii pair< int , int>
#define vi vector<int>
#define vii vector< pair<int,int> >

//comandos
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) x.begin(),x.end()

//constantes
#define MOD 1000000007
#define MAXN 300005LL
#define oo 2000000000000000005LL
int update(int,int,int);
int update(int,int);

int n, m;
int bit[MAXN];
vector<vi> G;
vector<vii> Q;
vector<int> ans;

int update(int a, int b, int v){
    update(b, v);
    update(a-1, -v);
}

int update(int p, int v){
    while(p){
        bit[p]+=v;
        p -= (p&-p);
    }
}

int query(int p){
    int ans = 0;
    while(p<MAXN){
        ans += bit[p];
        p += (p&-p);
    }
    return ans;
}

int dfs(int v, int p=-1, int d=1){
    for(ii t: Q[v]){
        update(d, min(MAXN-1, d+t.first), t.second);
    }
    ans[v] = query(d);
    for(int u : G[v]){
        if(u!=p)
            dfs(u, v, d+1);
    }
    for(ii t: Q[v]){
        update(d, min(MAXN-1, d+t.first), -t.second);
    }
}

int solve(){
    G = vector<vi>(n+1);
    Q = vector<vii>(n+1);
    ans = vector<int>(n+1);

    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%lld %lld", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    scanf("%lld", &m);
    for(int i = 0; i < m; i++){
        int v,d,x;
        scanf("%lld%lld%lld", &v, &d, &x);
        Q[v].push_back( make_pair(d, x) );
    }
    dfs(1);
    for(int i = 1; i <= n; i++) printf("%lld%c", ans[i], " \n"[i==n]);
}

main(){
    while(scanf("%lld", &n)!= EOF){
        solve();
    }
}
