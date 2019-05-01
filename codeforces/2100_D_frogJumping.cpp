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

int A, B, M, gcd;
vector<int> vis;
int last;
int limite(int x){
   return x>=0 and x<=A+B;
}

int dfs(int v){
   last = max(last, v);
   vis[v] = last;

   if( limite(v-B) and vis[v-B]==oo ) dfs(v-B);
   if( limite(v+A) and vis[v+A]==oo ) dfs(v+A);
}

int solve(int x){
   if(x==0)return 0;
   int q = x/gcd;

   if(x%gcd==0){
      return ((2LL+q+1LL)*q)/2LL +
             (2LL+q)*(gcd-1)*(q-1)/2LL;
   }else{
      return q+1 + solve(x-1);
   }
}

main(){
   scanf("%lld%lld%lld", &M, &A, &B);

   vis = vector<int>(A+B+1, oo);
   vis[0] = 0;
   dfs(0);

   int ans = 0;
   int sum = 0;
   for(int i =0; i<=min(M, A+B); i++ ){
      ans+= max(0LL, min(M, A+B)-vis[i]+1);
   }

   if(M>A+B){
      gcd = __gcd(A,B);
      ans += solve(M) - solve(A+B);
   }
   printf("%lld\n", ans);
}


















