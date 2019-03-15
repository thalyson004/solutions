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

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int N;
char l[1000005];
int len;
int bea[30];

int one(char *s){
   for(int i = 1; s[i]; i++)
      if( s[0]!=s[i] )
         return 0;
   return 1;
}

void calcBea(){
   char last = -1;
   int q = 0;
   for(int i = 0; l[i]; i++){
      if(l[i]!=last){
         q = 1;
         last = l[i];
      }else{
         q++;
      }
      bea[ last-'a' ] = max(q, bea[ last-'a' ]);
   }
}

void solve2(){
   scanf("%s", l);
   len = strlen(l);

   if( one(l) ){
      for(int i = 0; i < 30; i++){
         if(i==l[0]-'a') bea[i] += len*(bea[i]+1);
         else bea[i] = !!bea[i];
      }
   }else{
      for(int i = 0; i < 30; i++){
         bea[i] = !!bea[i];
      }
      int pre = 0, pos=0;
      for(int i = 0; l[i]==l[0]; i++) pre++;
      for(int i = len-1; l[i]==l[len-1]; i--) pos++;

      if( l[0]==l[len-1] ){
         if( bea[ l[0]-'a' ] )
            bea[ l[0]-'a' ] = max(bea[ l[0]-'a' ], 1+pre+pos);
      }else{
         if( bea[ l[0]-'a' ] )
            bea[ l[0]-'a' ] = max(bea[ l[0]-'a' ], 1+pre);

         if( bea[ l[len-1]-'a' ] )
            bea[ l[len-1]-'a' ] = max(bea[ l[len-1]-'a' ], 1+pos);
      }
      calcBea();
   }
   for(int i = 0; i < 30; i++) bea[i] = min(bea[i], MAX);
}

int solve(){
   scanf("%s", l);
   calcBea();
   for(int i = 1; i<N;i++){
      solve2();
   }
   int ans = 0;
   for(int i = 0; i < 30; i++){
      ans = max(ans, bea[i]);
   }
   return ans;
}

main(){
   while( scanf("%lld", &N) != -1 ){
      for(int i = 0; i < 30; i++) bea[0]=0;
      printf("%lld\n", solve() );
   }
}
