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

int N;
int cost[MAXN];
vector<int> T[MAXN], G[MAXN];
int dp[MAXN][2];
int mark[MAXN][2];

int TREE(int v, int father){
   for(int u:G[v]){
      if(u!=father){
         T[v].push_back(u);
         TREE(u,v);
      }
   }
}

int dfs(int v, int k){
   if(dp[v][k]!=-1)return dp[v][k];
   if(T[v].size()==0) return dp[v][k] = k?0LL:cost[v];
   int sum = 0;
   for(int u:T[v]) sum += dfs(u, 0);
   dp[v][k] = sum;
   for(int u:T[v]){
      if(!k){
         dp[v][k] = min(dp[v][k], sum+cost[v]-dfs(u,0)+dfs(u,1));
      }else{
         dp[v][k] = min(dp[v][k], sum-dfs(u,0)+dfs(u,1));
      }
   }
   return dp[v][k];
}

void getAns(int v, int k, vector< int > &ans){
   if(mark[v][k]) return;
   mark[v][k]=1;

   if(T[v].size()==0){
      if(!k){
         ans.push_back( v );
      }
      return;
   }

   int sum = 0;
   for(int u:T[v]) sum += dfs(u, 0);
   int ok = 0;
   if(dp[v][k]==sum){
      for(int u:T[v]){
         getAns(u, 0, ans);
      }
   }
   vector<int> go;
   for(int u:T[v]){
      if(!k){
         if(dp[v][k] == sum+cost[v]+dfs(u,1)-dfs(u,0) ){
            ok = 1;
            go.push_back(u);
            getAns(u, 1, ans);
         }
      }else{
         if( dp[v][k] == sum-dfs(u,0)+dfs(u,1) ){
            getAns(u, 1, ans);
            go.push_back(u);
         }
      }
   }

   if(ok) ans.push_back( v );
   if(go.size()>=2)
      for(int u:T[v]){
         getAns(u, 0, ans);
      }
   else if(go.size()==1)
      for(int u:T[v])
         if(u!=go[0])
            getAns(u, 0, ans);

}

void solve(){
   for(int i = 1; i <= N; i++){
      scanf("%lld" , & cost[i]);
      G[i].clear();
      T[i].clear();
      dp[i][0]=dp[i][1]=-1;
      mark[i][0]=mark[i][1]=0;
   }
   for(int i = 1; i < N; i++){
      int a, b;
      scanf("%lld%lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
   }
   TREE(1, -1);

   dfs(1, 0);
   dfs(1, 1);
   vector<int> ans;
   getAns(1, 0, ans);
   sort( all(ans) );
   printf("%lld %lld\n", dp[1][0], (int)ans.size());
   for(int x:ans) printf("%lld ", x);
   printf("\n");
}

main(){
   while(scanf("%lld", &N)!=EOF){
      solve();
   }

}







