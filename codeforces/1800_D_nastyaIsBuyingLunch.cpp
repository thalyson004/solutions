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
//#define int long long

#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define pb push_back
#define FOR(v, i, l) for(int v = i; v < (int)l; ++v)
#define REP(v, l) FOR(v, 0, l)

#define MAXN 300005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int N, M;
int pos[MAXN];
int seq[MAXN];
int q[MAXN];
vector<int> p[2*MAXN];

int solve(){
   fill(pos, pos+1+N, 0);
   fill(q, q+1+N, 0);
   for(int i = 1; i <= N; i++) p[i].clear();

   for(int i = 1; i <= N; i++){
      int x;
      scanf("%d", &x);
      seq[ i ] = x;
      pos[ x ] = i;
   }
   for(int i = 0; i < M; i++){
      int u, v;
      scanf("%d %d", &u, &v);
      p[v].pb(u);
      if( pos[u]<pos[v] )
         q[ u ]++;
   }
   int ans = 0;
   for(int i = N-1; i >= 1; i--){
      if( q[ seq[i] ] >= (N-i-ans) ){
         ans++;
         for( int u: p[ seq[i] ] ) q[u]--;
      }
   }
   return ans;
}

main(){
   while( scanf("%d%d", &N, &M) != -1 ){
      printf("%d\n", solve() );
   }
}
