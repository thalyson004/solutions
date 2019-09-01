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

int cases;
int N, M, K;
char s[200005];
int slen;
char t[200005];
int tlen;

int pre[200005];
int pos[200005];

int ok(int in, int fi){
   int mach = 0;
   for(int i=in; i<=fi and mach<tlen; i++){
      mach += (s[i]==t[mach+1]);
   }
   return mach==tlen;
}

int ok2(int in, int fi){
   int mach = 0;
   for(int i=1; i<=in and mach<tlen; i++){
      mach += (s[i]==t[mach+1]);
   }
   for(int i=fi; i<=slen and mach<tlen; i++){
      mach += (s[i]==t[mach+1]);
   }
   return mach==tlen;
}

main(){
   cin >> s+1 >> t+1;
   slen = strlen(s+1);
   tlen = strlen(t+1);
   int ans = 0;
   for(int i = 1; i <= slen; i++){
      if( ok(1,i) ) ans = max(ans, slen-i);
      if( ok(i,slen) ) ans = max(ans, i-1);
      for(int j = i; j <= slen; j++){
         if( ok(i, j) ) ans = max( max(ans, i-1), slen-j);
         if( i!=j and ok2(i, j) ) ans = max( ans, j-i-1);
      }
   }
   printf("%lld\n", ans);
}





















