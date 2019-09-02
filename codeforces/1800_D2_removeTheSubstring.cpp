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

main(){
   cin >> s+1 >> t+1;
   slen = strlen(s+1);
   tlen = strlen(t+1);
   int ans = 0;

   for(int i = 1; i <= slen; i++){
      pre[i] = pre[i-1];
      pre[i] += (pre[i]<tlen and s[i]==t[pre[i]+1]);
      if(pre[i]==tlen) ans = max(ans, slen-i);
   }
   pos[slen+1]=tlen+1;
   for(int i = slen; i >= 1; i--){
      pos[i] = pos[i+1];
      pos[i] -= (pos[i]>1 and s[i]==t[pos[i]-1]);
      if(pos[i]==1) ans = max(ans, i-1);
   }
   if(tlen!=1){
      int j = 1;
      for(int i = 1; i < slen; i++){
         j = max(j, i+1);
         while(j<slen and pos[j+1]<=pre[i]+1)j++;
         if(pre[i]+1==pos[j]){
            ans = max(ans, j-i-1);
         }
      }
   }

   printf("%lld\n", ans);
}





















