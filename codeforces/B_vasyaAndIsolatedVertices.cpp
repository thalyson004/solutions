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

main(){
   cin >> n >> m;
   int ma, mi;

   mi = max(0LL, n-m*2LL);
   ma = n;
   if(m){
      int c = 2;
      m--;
      for(int i = 3; i <= n and m>0; i++){
         m-=c;
         c++;
      }
      ma = n-c;
   }

   cout << mi << " " << ma << endl;
}
