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

#define MAXN 100005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)
#define OO (1LL<<60)

const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int n, m;
vector< int > h;
vector< int > l;
main(){
   scanf("%lld %lld", &n, &m);
   for(int i = 0; i < n; i++){
      int x;
      scanf("%lld", &x);
      l.push_back( x );
   }
   l.push_back(1000000000LL);
   sort( all(l) );

   for(int i = 0; i < m; i++){
      int x1,x2,y;
      scanf("%lld %lld %lld", &x1, &x2, &y);
      if( x1==1 ) h.push_back( x2 );
   }
   sort(all(h));
   int ans = m+n;
   int k = 0;
   for(int i = 0; i < l.size(); i++){
      while( k<h.size() and h[k]<l[i] ) k++;
      ans = min(ans, i+((int)h.size()-k) );
   }
   printf("%lld\n", ans);
}
