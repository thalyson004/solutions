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

#define MAXN 100005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<60)
#define MAX 1000000000LL
#define debug(x) cout << #x << " is " << x << "\n";

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -2};

int cases;
int N, M, K;
vi G[MAXN];
ii criminoso[MAXN];
int preso[MAXN];
int filho[MAXN];

int dfs(int v){
   if(!G[v].size()) return 0;
   int ans = 0;
   for(int u:G[v]){
      int d = dfs(u)+1;
      if(ans < d){
         ans = d;
         filho[v] = u;
      }

   }
   return criminoso[v].first = ans;
}

main(){
   cin >> N >> K;
   for(int i = 1; i <= N; i++){
      criminoso[i].first = 0;
      criminoso[i].second = i;
   }
   for(int i = 2; i <= N; i++){
      int v;
      cin >> v;
      G[v].push_back(i);
   }
   dfs(1);
   sort( criminoso+1, criminoso+1+N );
   reverse( criminoso+1, criminoso+1+N );
   int ans = 0;
   for(int i = 1; i <= N and K; i++){
      if(preso[ criminoso[i].second ])continue;
      K--;
      int v = criminoso[i].second;
      while( v ){
         ans++;
         preso[v]=true;
         v = filho[v];
      }
   }
   printf("%lld\n", ans);
}


