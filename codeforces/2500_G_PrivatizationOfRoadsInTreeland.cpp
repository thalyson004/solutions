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

#define MAXN 2000005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)
#define OO (1LL<<60)

const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int N, K;
vector< pair<int,int> > T[MAXN];
int ans[MAXN];
int mark[MAXN];
int colors;

int dfs(int v, int prevColor){
   int color = 1;
   mark[v]=1;
   for(auto u:T[v]){
      if( T[v].size()<=colors and color==prevColor ) color++;
      if(!mark[u.first]){
         dfs(u.first, color);
         ans[u.second]=color;
         if( T[v].size()<=colors ) color++;
      }

   }
}

void solve(){
   for(int i = 1; i <=N;i++) T[i].clear();
   memset(mark, 0, sizeof(int)*(N+1));
   memset(ans, 0, sizeof(int)*(N+1));

   for(int i = 0; i < N-1; i++){
      int a, b;
      scanf("%lld%lld", &a, &b);
      T[a].push_back( {b,i} );
      T[b].push_back( {a,i} );
   }

   vector<int> degree;
   for(int i = 1; i <= N; i++) degree.push_back( T[i].size() );
   sort( degree.begin(), degree.end() );

   colors = degree[N-K-1];
   int color = 1;
   mark[1]=1;
   for(auto u:T[1]){
      if(!mark[u.first]){
         dfs(u.first, color);
         ans[u.second]=color;
      }
      if( T[1].size()<=colors ) color++;
   }
   printf("%lld\n", colors);
   for(int i = 0; i < N-1; i++)
      printf("%lld%c",ans[i]," \n"[i+2==N]);
}

main(){
   while(scanf("%lld%lld", &N, &K)!=EOF){
      solve();
   }

}
