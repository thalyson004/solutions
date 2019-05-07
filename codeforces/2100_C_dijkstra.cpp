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

int N, M;
vector< ii > G[200005];
int dist[200005], father[200005];

vector<int> DJ(){
   for(int i = 1; i <= N;i++) dist[i]=oo, father[i]=-1;
   priority_queue< ii, vector<ii>, greater<ii> > fila;
   dist[1]=0;
   fila.push( {0, 1} );
   while(fila.size()){
      int v = fila.top().S;
      int c = fila.top().F;
      fila.pop();
      if( dist[v]!=c )continue;
      for(ii p:G[v]){
         int u = p.F;
         int cc = p.S;

         if(dist[u]>c+cc){
            dist[u]=c+cc;
            father[u]=v;
            fila.push( {dist[u], u} );
         }
      }
   }
   vector<int> ans;
   if( dist[N]==oo ) ans.push_back(-1);
   else{
      int v = N;
      while(v>0){
         ans.push_back( v );
         v = father[v];
      }
   }
   reverse( all(ans) );
   return ans;

}

int solve(){
   for(int i = 1; i <= N;i++) G[i].clear();
   for(int i = 0; i < M; i++){
      int a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      G[a].push_back( {b,c} );
      G[b].push_back( {a,c} );
   }
   vector<int> ans = DJ();
   for(int i: ans) printf("%lld ", i);
   printf("\n");
}

main(){
   while(~scanf("%lld %lld", &N, &M)){
      solve();
   }
}
