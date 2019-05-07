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

int N;
vector< ii > G[200005];
int c[200005];
int dp[200005];

int isLucky(int n){
   int ans = 1;
   while(n and ans){
      ans = ans and (n%10 == 4 or n%10 == 7);
      n /= 10;
   }
   return ans;
}

int count(int v, int p = -1){
   for(auto par:G[v]){
      int u = par.F;
      if(p!=u){
         c[v] += 1 + count(u, v);
      }
   }
   return c[v];
}

int dfs1(int v, int p = -1){
   for(auto par:G[v]){
      int u = par.F;
      if(p!=u){
         dfs1(u, v);
         if( isLucky( par.S ) ){
            dp[v]+=c[u]+1;
         }else{
            dp[v]+=dp[u];
         }
      }
   }
   return dp[v];
}

int dfs2(int v, int p = -1){
   for(auto par:G[v]){
      int u = par.F;
      if(p!=u){
         if( isLucky( par.S ) ){
            dp[u]+= N - c[u] - 1;
         }else{
            dp[u]+= dp[v]-dp[u];
         }
         dfs2(u, v);
      }
   }
   return dp[v];
}

int solve(){
   for(int i = 1; i <= N;i++) G[i].clear(), c[i]=0, dp[i]=0;
   for(int i = 1; i < N; i++){
      int a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      G[a].push_back( {b,c} );
      G[b].push_back( {a,c} );
   }
   count(1);
   dfs1(1);
   dfs2(1);
   int ans = 0;
   for(int i= 1; i  <= N; i++){
      ans += dp[i]*(dp[i]-1LL);
   }
   printf("%lld\n", ans);
}

main(){
   while(~scanf("%lld", &N)){
      solve();
   }
}


