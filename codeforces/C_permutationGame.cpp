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

#define MAXN 100005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int n, m;
int ans[100005];
int v[100005];

main(){
   scanf("%d", &n);
   priority_queue< pair<int,int> > ss;
   for(int i= 1; i <= n; i++){
      scanf("%d", &v[i]);
      ss.push( {v[i], i} );
   }

   while( ss.size() ){
      ii t = ss.top();
   ss.pop();
      m = t.F;
      int i = t.S;
      int ok = 0;
      for(int j = i+m; j <= n and !ok; j+=m)
         ok = ok or (v[j]>m and !ans[j]);
      for(int j = i-m; j >= 1 and !ok; j-=m)
         ok = ok or (v[j]>m and !ans[j]);

      ans[i] = ok;
   }
   for(int i = 1; i <=n;i++)
      printf("%c", ans[i]?'A':'B');
   putchar('\n');

}
