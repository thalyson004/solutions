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
   vi v;
   vi op[62];

   for(int i = 0; i< N; i++){
      int x;
      cin >> x;
      v.push_back( x );
   }

   for(int i = 0; i <= 60; i++){
      for(int j = 0; j < N; j++){
         if( v[j]%(1LL<<i)==0 and (v[j]/(1LL<<i))%2==1 ){
            op[i].push_back( v[j] );
         }
      }
   }

   int ans = 0;
   int id;
   for(int i = 0; i < 60; i++){
      if( ans < op[i].size() ){
         ans = op[i].size();
         id = i;
      }
   }

   set<int> peguei;
   for(int x: op[id]) peguei.insert(x);

   printf("%lld\n", N-ans);
   for(int x:v){
      if( peguei.count(x)==0 ){
         printf("%lld ", x);
      }
   }

}
