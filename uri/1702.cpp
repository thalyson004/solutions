#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000

int n, m, p, k;
int colors[1005];
int mark[1005];
vector<int> G[1005];
int ncolors[1005];
int M[1005][1005];

int dfs(int v){
   mark[v] = 1;
   for(int u: G[v]){
      if(!mark[u]) dfs(u);
   }
   return 0;
}

char solve(  ){
   scanf("%d %d %d %d", &n, &m, &p, &k);
   memset(ncolors, 0, sizeof ncolors);
   for(int i = 1; i <= n; i++){
      scanf("%d", &colors[i]);
      ncolors[colors[i] ]++;
      G[i].clear();
      for(int j=1; j<=n;j++) M[i][j] = 0;
   }
   int ok = 1;
   //Monta grafo e checa arestas múltiplas
   for(int i = 0; i < m; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      if(colors[a]==colors[b])ok = 0;
      G[a].push_back(b);
      G[b].push_back(a);
      M[a][b]=M[b][a]=1;
   }
   //printf("montou grafo...\n");
   if(!ok) return 'N';
   //Checa ciclos e conta componentes
   int componets = 0;
   memset(mark, 0, sizeof mark);
   for(int i =1; i <=n; i++){
      if(!mark[i]){
         componets++;
         ok = ok and !dfs(i);
      }
   }
   int minimum = componets-1;
   int maximum = 0;
   for(int i = 1; i <= k; i++) maximum += ncolors[i]*(n-ncolors[i]);
   maximum = maximum/2 - m;
   
   if( p<=maximum and p>=minimum ) return 'Y';
   return 'N';
}

int main(){
   int t;
   scanf("%d", &t);

   while(t--){
      printf("%c\n", solve());
   }
}



