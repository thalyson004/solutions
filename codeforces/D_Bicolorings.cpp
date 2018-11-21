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

#define MAXN 1005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)
#define MOD 998244353LL

#define uu 0
#define ud 1
#define du 2
#define dd 3

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int n, m, k;
int dp[MAXN][4][2*MAXN];

main(){
   cin >> n >> k;

   dp[1][uu][1] = 1;
   dp[1][ud][2] = 1;
   dp[1][du][2] = 1;
   dp[1][dd][1] = 1;

   for(int i = 2; i <=n; i++){
      for(int j=1; j <=k; j++){
         dp[i][uu][j] = (dp[i][uu][j]+    dp[i-1][uu][j])%MOD;
         dp[i][uu][j] = (dp[i][uu][j]+    dp[i-1][ud][j])%MOD;
         dp[i][uu][j] = (dp[i][uu][j]+    dp[i-1][du][j])%MOD;
         dp[i][uu][j] = (dp[i][uu][j]+    dp[i-1][dd][j-1])%MOD;
      }

      for(int j=1; j <=k; j++){
         dp[i][ud][j] = (dp[i][ud][j]+    dp[i-1][uu][j-1])%MOD;
         dp[i][ud][j] = (dp[i][ud][j]+    dp[i-1][ud][j])%MOD;
         if(j>1)
         dp[i][ud][j] = (dp[i][ud][j]+    dp[i-1][du][j-2])%MOD;
         dp[i][ud][j] = (dp[i][ud][j]+    dp[i-1][dd][j-1])%MOD;
      }

      for(int j=1; j <=k; j++){
         dp[i][du][j] = (dp[i][du][j]+    dp[i-1][uu][j-1])%MOD;
         if(j>1)
         dp[i][du][j] = (dp[i][du][j]+    dp[i-1][ud][j-2])%MOD;
         dp[i][du][j] = (dp[i][du][j]+    dp[i-1][du][j])%MOD;
         dp[i][du][j] = (dp[i][du][j]+    dp[i-1][dd][j-1])%MOD;
      }

      for(int j=1; j <=k; j++){
         dp[i][dd][j] = (dp[i][dd][j]+    dp[i-1][uu][j-1])%MOD;
         dp[i][dd][j] = (dp[i][dd][j]+    dp[i-1][ud][j])%MOD;
         dp[i][dd][j] = (dp[i][dd][j]+    dp[i-1][du][j])%MOD;
         dp[i][dd][j] = (dp[i][dd][j]+    dp[i-1][dd][j])%MOD;
      }
   }

   cout << (dp[n][uu][k]+dp[n][ud][k]+dp[n][dd][k]+dp[n][du][k])%MOD << endl;
}
	