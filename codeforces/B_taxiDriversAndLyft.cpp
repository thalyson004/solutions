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
#define OO (1LL<<60)

const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int n, m;
int p[200005];
int t[200005];
int ans[200005];
vector< int > a, b;

main(){
   cin >> n >> m;
   for(int i = 1; i <=m+n; i++) scanf("%d", &p[i]);
   for(int i = 1; i <=m+n; i++){
      scanf("%d", &t[i]);
      if(t[i]){
         a.push_back( i );
      }else{
         b.push_back( i );
      }
   }
   for(int i = 1; i <= n+m; i++){
      if(t[i] == 0){
         int prox = upper_bound(a.begin(), a.end(), i) - a.begin();
         int ant  = prox-1;

         //printf("Para %d - %d %d - %d %d\n", i, ant, prox, a[ant], a[prox]);
         if( prox==a.size() ) ans[ a[ant] ]++;
         else if( ant==-1 ) ans[ a[prox] ]++;
         else if( p[i]-p[ a[ant] ] <= p[ a[prox] ]-p[i] ) ans[a[ant]]++;
         else ans[a[prox]]++;
      }
   }
   for(int i = 1; i <= n+m; i++)
      if(t[i])
         printf("%d ", ans[i]);
}
