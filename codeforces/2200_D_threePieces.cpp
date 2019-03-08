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

vii moves[3];
int n;
int g[10][10];
ii dis[3][10][10];
ii p[150];

int ok(int a, int b){
   return a>=0 and b>=0 and a<n and b<n;
}
int cavaloMoves(){
   moves[0].push_back({2,1});
   moves[0].push_back({-2,1});
   moves[0].push_back({-2,-1});
   moves[0].push_back({2,-1});

   moves[0].push_back({1, 2});
   moves[0].push_back({1, -2});
   moves[0].push_back({-1, 2});
   moves[0].push_back({-1, -2});
}
int torreMoves(){
   for(int i = 0; i < n; i++)
      moves[1].push_back({0, i} ),
      moves[1].push_back({i, 0} ),
      moves[1].push_back({0, -i} ),
      moves[1].push_back({-i, 0} );
}
int bispoMoves(){
   for(int i = 0; i < n; i++)
      moves[2].push_back({i, i} ),
      moves[2].push_back({-i, i} ),
      moves[2].push_back({i, -i} ),
      moves[2].push_back({-i, -i} );
}
int infinito(){

   for(int i = 0; i < n; i++)
   for(int j = 0; j < n; j++)
   for(int k = 0; k < 3; k++)
      dis[k][i][j] = {oo,oo};
}

struct el{
   ii d;
   int i, j, k;
   bool operator < (el x) const {
      return d > x.d;
   }
};

int dj(int fi){

   priority_queue< el > fila;
   for(int i = 0; i < 3; i++){
      fila.push( {dis[i][p[fi-1].F][p[fi-1].S], p[fi-1].F, p[fi-1].S, i} );
   }

   while(fila.size()){
      el x = fila.top();
      fila.pop();
      if( dis[x.k][x.i][x.j] < x.d ) continue;
      for(ii i: moves[x.k]){
         int xx = x.i + i.F;
         int yy = x.j + i.S;
         if( ok(xx,yy) and (dis[x.k][xx][yy] > make_pair(x.d.F+1, x.d.S)) ){
            dis[x.k][xx][yy] = {x.d.F+1, x.d.S};
            fila.push( {dis[x.k][xx][yy], xx, yy, x.k} );
         }
      }
      for(int i = 0; i < 3; i++)
         if(i != x.k)
            if( dis[i][x.i][x.j] > make_pair(x.d.F+1, x.d.S+1) ){
               dis[i][x.i][x.j] = {x.d.F+1, x.d.S+1};
               fila.push( {dis[i][x.i][x.j], x.i, x.j, i} );
            }
   }

   for(int i = 0; i < n; i++)
   for(int j = 0; j < n; j++)
   if(g[i][j] != fi){
      for(int k = 0; k < 3; k++)
         dis[k][i][j] = {oo,oo};
   }
}

main(){
   cin >> n;
   cavaloMoves();
   torreMoves();
   bispoMoves();


   for(int i = 0; i < n; i++)
   for(int j = 0; j < n; j++){
      scanf( "%lld", &g[i][j] );
      int k = g[i][j];
      p[k] = {i,j};
   }
   infinito();
   dis[0][ p[1].F ][ p[1].S ] = {0,0};
   dis[1][ p[1].F ][ p[1].S ] = {0,0};
   dis[2][ p[1].F ][ p[1].S ] = {0,0};

   for(int i = 2; i <= n*n; i++){
      dj(i);
   }
   ii ans = min(dis[0][p[n*n].F][p[n*n].S],
                  dis[1][p[n*n].F][p[n*n].S]);
   ans = min(ans,
             dis[2][p[n*n].F][p[n*n].S]);

   cout << ans.F << " " << ans.S << endl;
}
