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
int N, C, T;
int bag[100005];

int ok(int sec){
   int p = 1, q=0;
   for(int i = 0; i < N; i++){
      if(bag[i]>T*sec)return 0;

      if(q+bag[i]<=T*sec){
         q+=bag[i];
      }else{
         q=bag[i];
         p++;
      }
   }
   return p<=C;
}
int solve(){
   int l = 1, r = 1000000005, m;
   while(l<r){
      int m = (l+r)/2;
      if(ok(m))r=m;
      else l=m+1;
   }
}
main(){
   cin >> N >> C >> T;
   for(int i = 0; i < N; i++) cin >> bag[i];
   cout << solve() << endl;
}






