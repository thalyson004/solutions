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

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int n, m;

int v[1005];
int q[1005];
int f[1005];
char ans[1005];
vector<int> um, maior;

main(){
   cin >> n;
   for(int i = 1; i <=n;i++){
      cin >> v[i];
      if(!f[ v[i] ]) f[v[i]]=i;
      q[ v[i] ]++;
      ans[i] = 'A';
   }

   for(int i = 1; i<=100;i++){
      if(q[i]==1) um.pb( i );
      if(q[i]> 2) maior.pb(i);
   }

   ans[n+1] = '\n';
   for(int i = 0; i < sz(um);i++){
      ans[ f[ um[i] ] ] = 'A' + i%2;
   }

   if( sz(um)%2 and !sz(maior) ){
      printf("NO\n");
      return 0;
   }
   if( sz(um)%2 ){
      ans[ f[ maior[0] ] ] = 'B';
   }
   printf("YES\n");
   cout << ans+1 << endl;
}
