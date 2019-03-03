#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000
#define MAXN 2005
#define all(x) x.begin(),x.end()

int N,M;
char relation[MAXN][MAXN];
vector< vector<int> > G(MAXN);
vector< vector<int> > T(MAXN);
vector< vector<int> > component;
int group[MAXN];
int mark[MAXN];
int ans[MAXN];
vector<int> topo;

int setComponent(int v, int id){
   mark[v] = 1;
   group[v] = id;
   component[id].push_back(v);

   for(int u:G[v])
      if( !mark[u] )
         setComponent(u, id);
}

int topologicSort(int v){
   mark[v]=1;

   for(int u:G[v])
      if( mark[u]==1 ) return 1;
      else if( !mark[u] and topologicSort(u) ) return 1;

   topo.push_back( v );
   mark[v]=2;
   return 0;
}

int solve(){
   for(int i = 1; i <= N; i++){
      G[i].clear();
      scanf("%s", relation[i]+1);
      for(int j=1; j <= M; j++)
         if( relation[i][j]=='=' ){
            G[i].push_back(j+N);
            G[j+N].push_back(i);
         }
   }
   component.clear();
   memset(mark, 0, sizeof mark);
   for(int i = 1; i <= N+M;i++){
      if( !mark[i] ){
         component.push_back( vector<int>() );
         setComponent(i, (int)component.size()-1);
      }
   }

   for(int i = 0; i < component.size(); i++)
      G[i].clear();

   for(int i = 1; i <=N; i++)
   for(int j = 1; j <=M; j++)
      if(relation[i][j]=='>'){
         G[ group[i] ].push_back( group[j+N] );
         T[ group[j+N] ].push_back( group[i] );
      }else if( relation[i][j]=='<' ){
         G[ group[j+N] ].push_back( group[i] );
         T[ group[i] ].push_back( group[j+N] );
      }
   
   int cicly=0;
   memset( mark, 0, sizeof mark );
   topo.clear();
   for(int i = 0; i < component.size(); i++){
      if( !mark[i] )
         cicly = cicly or topologicSort(i);
   }

   if( cicly ) return 0;
  
   memset(ans, 0, sizeof ans);
   for(int i = 0; i < topo.size(); i++){
      int value = 1;
      for(int v : G[ topo[i] ] )
         value = max(value, ans[ component[v][0] ]+1 );

      for(int v : component[ topo[i] ] ){
         ans[v]=value;
      }

   }

   return 1;
}

int main(){
   int n;
   while( scanf("%d%d", &N, &M) != -1 ) {
      if( solve() ){
         printf("Yes\n");
         for(int i = 1; i <=N; i++) printf("%d%c",ans[i]," \n"[i==N]);
         for(int i = N+1; i <=N+M; i++) printf("%d%c",ans[i]," \n"[i==N+M]);
      }else{
         printf("No\n");
      }
   }
}
