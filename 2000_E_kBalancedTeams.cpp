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

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int N,K;
vector<int> stu;
vector< vector<int> > dp;
vector< int > go;

int solve(int n, int k){

   if( k>K ) return -oo;
   if( n==N ) return k ? 0 : -oo;
   if( k==K ) return 0;
   if( dp[n][k]!=-1 ) return dp[n][k];


   int ans = solve(n+1, k);
   if( solve( go[n], k+1 ) != -oo ){
      ans = max(ans, solve( go[n], k+1 ) + (go[n]-n)  );
   }

   return dp[n][k] = ans;
}

main(){
   while( scanf("%lld%lld", &N, &K) != -1 ){
      stu.clear(); stu=vector<int>(N);
      for(int &x:stu)scanf("%lld", &x);
      sort(stu.begin(), stu.end());
      dp.clear(); dp = vector< vector<int> >(N, vector<int>(K, -1));
      go.clear(); go = vector<int>(N);
      int j = 0;
      for(int i = 0; i < N; i++){
         while(j<N and stu[i]+5>=stu[j]) j++;
         go[i]=j;
      }

      printf("%lld\n", solve(0,0) );
   }
}
