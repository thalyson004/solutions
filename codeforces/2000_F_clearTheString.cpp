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

int len;
char s[505];
int dp[505][505];

int solve(int i, int j){
   if(dp[i][j] != -1) return dp[i][j];
   if(i==j) return 1;
   if(i>j) return 0;

   int ans = 1+solve(i+1, j);
   for(int k = i+1; k <= j; k++){
      if(s[i]==s[k])
         ans = min(ans, solve(i, k-1)+solve(k+1, j));
   }
   return dp[i][j] = ans;
}

main(){
   while( scanf("%d%s", &len, s) != -1 ){
      memset(dp, -1, sizeof dp);
      printf("%d\n", solve(0, len-1) );
   }
}
