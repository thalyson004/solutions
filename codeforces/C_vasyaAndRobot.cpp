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

int n;
char s[200005];
int x, y;
int preSumX[200005];
int preSumY[200005];
ii p(0,0);

void di(char c, ii &p){
   if(c=='U') p.second++;
   if(c=='D') p.second--;
   if(c=='R') p.first++;
   if(c=='L') p.first--;
}

int sal(int i, int k){
   int xx = p.F - (preSumX[i+k-1] - preSumX[i-1]);
   int yy = p.S - (preSumY[i+k-1] - preSumY[i-1]);

   int dx = x-xx;
   int dy = y-yy;

   int op = abs(dx)+abs(dy);
   if( op <= k and (k-op)%2==0 ){
      return 1;
   }
   return 0;
}

main(){
   scanf("%d", &n);
   scanf("%s", s+1);
   scanf("%d %d", &x, &y);

   if( abs(x)+abs(y) <= n and (n-abs(x)-abs(y))%2==0  ){

      for(int i = 1; i <= n; i++) di(s[i], p);

      if( p == make_pair(x,y) ){
         printf("0\n");
      }else{
         for(int i = 1; i <= n; i++){
            preSumX[i] = preSumX[i-1] + (s[i]=='R'?1:(s[i]=='L'?-1:0));
            preSumY[i] = preSumY[i-1] + (s[i]=='U'?1:(s[i]=='D'?-1:0));
         }
         int ok = oo;
         for(int i = 1; i <= n ; i++){
               int e = 1, d = n-i+1;
               while(e<d){
                  int k = (e+d)/2;
                  if( sal(i, k) ){
                     if( !sal(i, k-1) ) e = d = k;
                     else d = k-1;
                  }else{
                     e = k+1;
                  }
               }
               if( sal(i,e) ) ok = min(ok, e);
            }
         printf("%d\n", ok);
      }
   }else{
      printf("-1\n");
   }
}
