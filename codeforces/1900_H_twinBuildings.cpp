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
 
int N;
#define X first
#define Y second
pair<int, int> lands[100005];
 
main(){
   int answer = -1;
 
   scanf("%lld", &N);
   for(int i = 0; i < N; i++){
      scanf("%lld %lld", &lands[i].X, &lands[i].Y);
      if( lands[i].X > lands[i].Y ){
         swap( lands[i].X, lands[i].Y );
      }
      int temp = (lands[i].X*lands[i].Y);
      answer = max( answer, temp );
   }
   sort( lands, lands+N );
   int maxY=0;
 
   for(int i = N-1; i >= 0; i--){
      answer = max( answer, lands[i].X*min(maxY, lands[i].Y)*2LL );
      maxY = max( maxY, lands[i].Y );
   }
 
   printf("%lld.%d\n", answer/2LL, answer%2LL ? 5:0);
}
