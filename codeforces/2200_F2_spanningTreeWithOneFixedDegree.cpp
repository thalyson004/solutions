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

#define MAXN 300005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int N, M, D;

vector< vector<int> > G;
vector< int > go;
queue< int > qq;
vector< int > component;
int cc; //Número de componentes retirando o 1

void dfs(int v){
   component[v] = cc;
   for(int u:G[v]){
      if( u!=1 and !component[u] ){
         dfs(u);
      }
   }
}

void solve(){
   G.clear();
   G = vector< vector<int> > (N+1);
   go.clear();

   for(int i = 0; i < M; i++){
      int u, v;
      scanf("%d%d", &u, &v);

      if(u==1) go.push_back(v);
      else if(v==1) go.push_back(u);

      G[u].push_back(v);
      G[v].push_back(u);
   }

   cc=0;
   component.clear();
   component = vector<int>(N+1);
   vector< int > use, nuse;
   for(int v: go){
      if( !component[v] ){
         cc++;
         dfs(v);
         use.push_back( v );
      }else
         nuse.push_back( v );
   }

   if( D < cc or G[1].size()<D){
      printf("NO\n");
      return;
   }
   printf("YES\n");
   fill(component.begin(), component.end(), 0);
   component[1] = 1;
   for(int i = 0; i < use.size(); i++){
      printf("%d %d\n", 1, use[i]);
      qq.push( use[i] );
      component[ use[i] ] = 1;
   }
   for(int i = 0; i < D-use.size(); i++){
      printf("%d %d\n", 1, nuse[i]);
      qq.push( nuse[i] );
      component[ nuse[i] ] = 1;
   }
   while(qq.size()){
      int v = qq.front(); qq.pop();
      for( int u: G[v] ){
         if(!component[u]){
            component[u]=1;
            qq.push(u);
            printf("%d %d\n", v, u);
         }
      }
   }
   return;
}


main(){
   while( scanf("%d%d%d", &N, &M, &D) != -1 ){
      solve();
   }
}
