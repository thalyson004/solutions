#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair<int,int>
#define iii pair<ii, int>
#define iiii pair<ii, ii>
#define viiii vector< iiii >
#define viii vector< iii >
#define vii vector< ii >
#define vi vector< int >
#define int long long

#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define pb push_back
#define FOR(v, i, l) for(int v = i; v < (int)l; ++v)
#define REP(v, l) FOR(v, 0, l)

#define MAXN 300005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<60)
#define MAX 1000000000LL

const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int N, M;

int group[MAXN];
int which(int a){ return group[a]==a?a:group[a]=which( group[a] ); }
int same(int a, int b){ return which(a)==which(b); }
void join(int a, int b){ group[ which(a) ] = which(b); }

int mark[MAXN];
vector< pair<int, pair<int,int> > > edges;
vector< pair<int, pair<int,int> > > unused;
vector< pair<int,int>  > G[MAXN];

int table[MAXN][30][2];
int h[MAXN];

int dfs(int v){
   mark[v] = 1;
   for(auto cur:G[v]){
      int u = cur.F;
      int c = cur.S;
      if( !mark[u] ){
         mark[u] = 1;
         h[u] = h[v]+1;
         table[u][0][0] = v;
         table[u][0][1] = c;
         dfs(u);
      }
   }
}

void makeTable(){
   for(int l = 1; l < 30; l++){
      for(int v =1; v<=N; v++){
         table[v][l][0] = table[ table[v][l-1][0] ][l-1][0];
         table[v][l][1] = (!!table[v][l][0])*max(table[v][l-1][1],
                              table[ table[v][l-1][0] ][l-1][1]);

      }
   }
}

int LCA(int v, int u){
   if( h[v] < h[u] ) {
      swap( v, u  );
   }
   int ans = 0;
   for(int l = 29; l >= 0; l--){
      if( h[v]-(1<<l) >= h[u] ){
         ans = max(ans, table[v][l][1]);
         v = table[v][l][0];
      }
   }
   if(u==v) return ans;
   for(int l = 29; l >= 0; l--){
      if( table[v][l][0] and table[u][l][0] and
          table[v][l][0]!=table[u][l][0]){
         ans = max(ans, max(table[v][l][1], table[u][l][1]));
         v = table[v][l][0];
         u = table[u][l][0];
      }
   }
   return max(ans, max(table[v][0][1], table[u][0][1]));
}

main(){
   scanf("%lld %lld", &N, &M);
   for(int i = 0; i < M; i++){
      int a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      edges.push_back( {c,{a,b}} );
   }
   for(int i = 1; i <= N; i++){
      group[i] = i;
   }
   sort(all( edges ));
   int ans = 0;
   for(pair<int, pair<int,int> > cur: edges){
      int cost = cur.F;
      int a = cur.S.F;
      int b = cur.S.S;
      if( same(a,b) ){
         unused.pb( cur );
      }else{
         G[a].push_back( {b,cost} );
         G[b].push_back( {a,cost} );
         join(a,b);
      }
   }
   dfs(1);
   makeTable();
   for(auto cur: unused){
      if( cur.F == LCA(cur.S.F, cur.S.S) ){
         ans++;
      }
   }
   printf("%lld\n", ans);
}
