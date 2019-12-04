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

int cases;
int R, C, K;

char grid[110][110];
char ans[110][110];

char marca(int x){
   if(x<=26) return 'a' + (x-1);
   if(x<=52) return 'A' + (x-26-1);
   return '0' + (x-53);
}

main(){
   scanf("%d", &cases);

   while(cases--){
      scanf("%d %d %d", &R, &C, &K);
      int nR = 0, rR = 0, kR = 0;

      for(int i =1; i <= R; i++){
         scanf("%s", grid[i]+1 );
         for(int j=1; j <= C; j++){
            nR += (grid[i][j]=='R');
         }
         ans[i][C+1]='\0';
      }
      kR = nR/K;
      rR = nR%K;

      int i = 1, j = 1, aK = 1, aR = 0;
      while( i<=R and j <= C ){

         aR += (grid[i][j]=='R');
         if( aR == kR + !!rR + 1 ){
            rR -= !!rR;
            aR = 1;
            aK++;
         }
         ans[i][j] = marca(aK);

         j += i%2 ? 1 : -1;
         i += (j==0 or j==C+1);
         j = min(j, C);
         j = max(j, 1);
      }
      for(int i =1; i <= R; i++)
         printf("%s\n", ans[i]+1 );
   }
}
