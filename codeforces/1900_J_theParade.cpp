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

int N, K;
vector< int > heights;

bool ok(int x){
   int ans = 0;
   vector<int> temp = heights;
   for(int i = 0; i < N; i++){
      if(i){
         if( temp[i-1]+temp[i]>=x ){
            temp[i]-= (x-temp[i-1]);
            temp[i-1] = 0;
            ans++;
         }
      }
      ans += temp[i]/x;
      temp[i]%=x;
   }
   return ans>=K;
}

main(){
   int cases;
   scanf("%lld", &cases);
   while( cases-- ){
      scanf("%lld %lld", &N, &K);
      heights.clear();
      int sum = 0;
      for(int i = 0; i < N; i++){
         int h;
         scanf("%lld", &h);
         sum += h;
         heights.push_back( h );
      }
      int l = 0, r = sum/K;
      while( l < r ){
         int m = (l+r+1)/2;
         if( ok(m) ) l = m;
         else r = m-1;
      }
      printf("%lld\n", l*K);
   }
}
