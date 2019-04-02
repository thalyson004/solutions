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

#define MAXN 200005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)
#define MAX 1000000000LL

const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int N;
int v[MAXN];
int dp[MAXN][2];

main(){
   scanf("%d", &N);
   for(int i = 1; i <= N; i++){
      scanf("%d", v+i);
      dp[i][0] = -oo;
      dp[i][1] = oo;
   }
   dp[1][0] = oo; //incre
   dp[1][1] = -oo; //dec
   for(int i = 2; i <= N; i++){
      //Put on in
      //previous on in
      if( v[i]>v[i-1] ) dp[i][0] = max(dp[i][0], dp[i-1][0]);
      //previous on dec
      if( v[i]>dp[i-1][1] ) dp[i][0] = max(dp[i][0], v[i-1]);
      //Put on dec
      //previous on dec
      if( v[i]<v[i-1] ) dp[i][1] = min(dp[i][1], dp[i-1][1]);
      //previous on in
      if( v[i]<dp[i-1][0] ) dp[i][1] = min(dp[i][1], v[i-1]);

   }
   if( dp[N][0]==-oo and dp[N][1]==oo ){
      printf("NO\n");
   }else{
      printf("YES\n");
      int j = dp[N][1]!=oo;
      vector<int> ans;
      for(int i = N; i >= 1; i--){
         ans.push_back( j );
         if( dp[i-1][j] != dp[i][j] ) j = !j;
      }
      reverse( all(ans) );
      for(int x: ans) printf("%d ", x);
      printf("\n");
   }
}
