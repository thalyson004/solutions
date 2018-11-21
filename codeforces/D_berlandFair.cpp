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

int n, t, sum, ans, total;
int v[200005];
int bit[200005];

void add(int p, int v){
   while( p<=n ){
      bit[p]+=v;
      p += ( p&-p );
   }
}

int query(int p){
   int ans = 0;
   while( p ){
      ans += bit[p];
      p -= ( p&-p );
   }
   return ans;
}

int tira(){

   int e = 1, d = n;
   while( e < d){
      int m = (e+d)/2;
      if( query(m)<=t ){
         e = m+1;
      }else{
         if(m==e or query(m-1)<=t ) e = d = m;
         else d = m-1;
      }
   }
   sum -= v[e];
   add(e, -v[e]);
   v[e] = 0;
   total--;
}

main(){
   scanf("%lld %lld", &n, &t);
   total = n;
   for(int i = 1; i <= n; i++){
      scanf("%lld", &v[i]);
      sum+=v[i];
      add(i, v[i]);
   }

   while(total){
      ans += total*(t/sum);
      t = t - (t/sum)*sum;
      while(sum>t){
         tira();
      }
   }
   printf("%lld\n", ans);
}
