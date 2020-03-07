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
#define oo (1<<30)
#define MAX 1000000000LL
#define debug(x) cout << #x << " is " << x << "\n";

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -2};

int N, M, K;
vector<int> special;
vector<int> G[2*100005];
vector<int> dist[2];

vector<int> DJ(int in){
   vector<int> ans(N+1, oo );

   ans[in] = 0;
   queue<int> fila;
   fila.push(in);
   while( fila.size() ){
      int v = fila.front();
      fila.pop();

      for(int u: G[v] ){
         if( ans[ u ]==oo ){
            ans[u] = ans[v]+1;
            fila.push( u );
         }
      }
   }
   return ans;
}

bool funcC(int a, int b){
   return dist[1][a]-dist[0][a] < dist[1][b]-dist[0][b];
}

main(){
   scanf("%d %d %d", &N, &M, &K);

   for(int i = 0; i < K; i++){
      int v;
      cin >> v;
      special.push_back( v );
   }

   for(int i = 0; i < M; i++){
      int u, v;
      scanf("%d %d", &u, &v);
      G[v].push_back(u);
      G[u].push_back(v);
   }
   dist[0] = DJ(1);
   dist[1] = DJ(N);

   vector<int> dif=special;
   sort(all(dif),  funcC);

   int ans = 0;

   for(int i = 0; i < K; i++){
      int v = dif[i];
      int da = 0;
      int dn = 0;
      if(i){
         int u = dif[i-1];
         da = min(dist[0][N],  min(dist[0][v]+1+dist[1][u], dist[0][u]+1+dist[1][v]) );
      }
      if(i<K-1){
         int u = dif[i+1];
         dn = min(dist[0][N],  min(dist[0][v]+1+dist[1][u], dist[0][u]+1+dist[1][v]) );
      }
      ans = max(ans, max(da,dn) );
   }
   printf("%d\n", ans);
}














