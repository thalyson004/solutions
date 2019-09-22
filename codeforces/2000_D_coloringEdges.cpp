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
#define debug(x) cout << #x << " is " << x << "\n";

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -2};

int cases;
int N, M, K, L;

vii G[5005];
int color[5005];
int mark[5005];

int dfs(int v){
   mark[v]=1;

   for(ii ed : G[v]){
      int u = ed.F;
      int a = ed.S;

      if(mark[u]!=1 and !color[a]){
         color[a]=K;
         L++;
         if(mark[u]==0)dfs( u );
      }
   }

   mark[v]=2;
}

main(){
   cin >> N >> M;

   for(int i = 1; i <= M; i++){
      int v, u;
      cin >> v >> u;
      G[v].pb( {u,i} );
   }
   K = 0;
   L = 0;
   for(int i = 1; i <= M and L < M; i++){
      K=i;
      fill(mark, mark+N+1, 0);
      for(int j = 1; j <=N; j++)
         if( !mark[j] )
            dfs(j);
   }
   printf("%lld\n", K);
   for(int i = 1; i <= M; i++){
      printf("%lld%c", color[i], " \n"[i==M] );
   }
}
