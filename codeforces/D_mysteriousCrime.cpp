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
int p[10][100005];
int u[100005];
int t[10][100005];

main(){
   scanf("%lld %lld", &n, &m);
   if(m == 1){
      printf("%lld\n", ((n+1)*n)/2LL );
      return 0;
   }

   for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
         scanf("%lld", &t[i][j]);
         p[ i ][ t[i][j] ] = j;
      }
   }
   int ans = 0;
   for(int i = 0; i < n; i++){
      int vez = t[0][i];
      if( u[vez] != 0 ) continue;
      int ps[10];
      for(int j=0; j < m; j++) ps[j] = p[j][vez];
      int tamanho = 1;
      while(1){
         int ok = 1;
         for(int j=1; ok and j <m; j++)
            if(ps[j]+tamanho >= n or
               ps[j-1]+tamanho >= n or
               t[j][ ps[j]+tamanho ] !=
               t[j-1][ ps[j-1]+tamanho ]){
               ok = 0;

               }
         if(!ok) break;
         tamanho++;
      }
      for(int j = 0; j < tamanho; j++)
         u[ t[0][i+j]  ] = 1;
      ans += ((tamanho+1)*tamanho)/2LL;

   }
   printf("%lld\n", ans);
}
