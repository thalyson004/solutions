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


int a[1005];
int x[1005];

main(){
   int n;
   vector<int> ans;
   cin >> n;
   a[0] = 0;

   for(int i = 1; i <= n; i++){
      cin >> a[i];
      x[i-1] = a[i] - a[i-1];
   }
   for(int k = 1; k <= n; k++){
      int ok = 1;
      for(int i = 1; i <= n and ok; i++){
         if( a[i] - a[i-1] != x[(i-1)%k] )
            ok = 0;
      }
      if(ok) ans.push_back( k );
   }
   cout << sz(ans) << endl;
   for(int i : ans) printf("%d ", i);
   printf("\n");
}
