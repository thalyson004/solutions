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
 
int N, S, sum;
vector< pair<int,int> > salaries;
 
bool ok(int x){
   int gi=0;
   int q=0, v=0;
   for(pair<int,int> p:salaries){
      if(p.first>=x) gi++;
      if(p.first<x and p.second >= x and v+x-p.first<=sum ){
         q++;
         v+= x-p.first;
      }
   }
   return gi+q>= (N+1)/2;
}
 
main(){
   int cases;
   scanf("%lld", &cases);
   while( cases-- ){
      scanf("%lld %lld", &N, &S);
      salaries.clear();
      sum = S;
      for(int i = 0; i < N; i++){
         int l, r;
         scanf("%lld %lld", &l, &r);
         salaries.push_back( {l,r} );
         sum -= l;
      }
      sort( all(salaries) );
      reverse( all(salaries) );
      int l = salaries[N/2].first, r=0;
      for(pair<int,int> p:salaries) r = max(r, p.second);
 
      while(l < r){
         int m = (l+r+1)/2;
         if(ok(m)) l=m;
         else r = m-1;
      }
      printf("%lld\n", l);
   }
}
