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

#define MAXN 300005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<60)
#define MAX 1000000000LL
#define debug(x) cout << #x << " is " << x << "\n";

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -2};

int N, M, K, T;
int soldiers[200005];
pair< int, pair<int,int> >traps[200005];

int ok(int agility){
   int temp[M+5]= {0};
   for(int i = 1; i <= K; i++){
      if( traps[i].F > agility ){
         temp[ traps[i].S.F ]++;
         temp[ traps[i].S.S+1 ]--;
      }
   }
   int total = 1, sum=0;
   for(int i = 1; i <= M; i++){
      sum += temp[i];
      total += 1 + (!!sum)*2;
   }
   return total <= T;

}

main(){
   cin >> N >> M >> K >> T;
   for(int i = 1; i <= N; i++){
      scanf("%d", soldiers+i);
   }
   soldiers[N+1] = 200005;
   sort( soldiers+1, soldiers+1+N+1 );

   for(int i = 1; i <=K; i++){
      scanf("%d %d %d", &traps[i].S.F, &traps[i].S.S, &traps[i].F);
   }
   sort( traps+1, traps+K+1 );

   int l=1, r=N+1;
   while( l < r ){
      int m = (l+r)/2;
      if( ok( soldiers[m] ) ) r=m;
      else l = m+1;
   }
   printf("%d\n", N+1-r);
}
