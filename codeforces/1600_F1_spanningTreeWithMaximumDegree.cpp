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

#define MAXN 2000005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)
#define OO (1LL<<60)

const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int N, M;
int group[MAXN];
vector< int > G[MAXN];

int find(int v){ return group[v]==v?v:group[v]=find( group[v] ); };
int same(int v, int u){ return find(v)==find(u); }
void merge(int v,int u){ group[ find(v) ] = find(u); }

void solve(){
   vector< pair<int,int> > v;
   int maximum=0;
   for(int i = 1; i<=N;i++){
      group[i]=i;
      G[i].clear();
   }
   for(int i = 0; i < M; i++){
      int a, b;
      scanf("%lld%lld", &a, &b);
      v.push_back( {a,b} );

      G[a].pb(b);
      G[b].pb(a);

      maximum = max(maximum, max((int)G[a].size(),(int)G[b].size()) );
   }
   for(int i = 1; i<=N;i++){
      if(maximum==G[i].size()){
            for(int v:G[i]){
               printf("%lld %lld\n", i, v);
               merge(i, v);
            }
            break;
      }
   }
   for( auto p:v ){
      if( !same(p.F,p.S) ){
         printf("%lld %lld\n", p.F,p.S);
         merge( p.F, p.S );
      }
   }
}

main(){
   while(scanf("%lld%lld", &N, &M)!=EOF){
      solve();
   }

}
