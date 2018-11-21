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
#define oo (1LL<<40)

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int n, k, m=oo, uc;
int h[200005];


main(){
   set<int> quais;
   map<int,int> mapa;
   cin >> n >> k;
   for(int i = 0; i < n; i++){
      scanf("%lld", &h[i]);
      m = min(m, h[i]);
      uc = max(uc, h[i]);
      quais.insert(-h[i]);
      mapa[h[i]]++;
   }

   sort(h, h+n);
   int ans = 0;
   int total=0;
   int cortados = 0;

   for(int i = uc; i > m; i--){
      if( total + mapa[i] + cortados > k ){
         ans++;
         total = 0;
      }

      total = total + mapa[i] + cortados;
      cortados += mapa[i];
   }
   if(total) ans++;
   printf("%lld\n", ans);
}

