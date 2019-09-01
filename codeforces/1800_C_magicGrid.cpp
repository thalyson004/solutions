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
 
int cases;
int N, M, K;
 
main(){
   cin >> N;
 
   vector<vector<int>> ans(N, vector<int>(N));
 
   int k = 0;
   for(int i = 0; i < N/2; i++)
   for(int j = 0; j < N/2; j++){
      ans[i][j] = k;
      ans[i][j+N/2] = k+1;
      ans[i+N/2][j] = k+2;
      ans[i+N/2][j+N/2] = k+3;
      k+=4;
   }
   for(int i = 0; i < N; i++)
   for(int j = 0; j < N; j++){
      printf("%lld%c", ans[i][j], " \n"[j+1==N]);
   }
}
