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

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int n, m;

bool primo(int x){
   for(int i = 2; i*i <= x; i++){
      if( x%i == 0 )
         return 0;
   }
   return 1;
}

main(){
   int t;
   cin >> t;
   while(t--){
      cin >> n >> m;

      if(n-m!=1LL){
         printf("NO\n");
         continue;
      }
      printf("%s\n", primo(n+m)?"YES":"NO\n");
   }

}
