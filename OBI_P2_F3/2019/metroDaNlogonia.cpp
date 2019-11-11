#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N[2];
vector<int> G[2][100005];

int long_path(int g, int v, vector<int> &mark,
              vector<int> &prev){
   queue<int> fila;
   fila.push(v);

   while(fila.size()){
      v = fila.front();
      fila.pop();
      mark[v] = 1;

      for(int u: G[g][v]){
         if( !mark[u] ){
            prev[u] = v;
            fila.push(u);
         }
      }
   }

   return v;
}

vector<int> make_path(int g){
   vector<int> mark(N[g]+1);
   vector<int> prev(N[g]+1);


   int v = long_path(g, 1, mark, prev);
   mark = prev = vector<int>(N[g]+1);
   v = long_path(g, v, mark, prev);

   vector<int> ans;
   ans.push_back( v );
   while( prev[v] ){
      v = prev[v];
      ans.push_back( v );
   }
   return ans;
}

int main(){
   scanf("%d %d", &N[0], N+1);
   vector<int> path[2];

   for(int i = 0; i < 2; i++){
      for(int j = 1; j < N[i]; j++){
         int a, b;
         scanf("%d %d", &a, &b);
         G[i][a].push_back(b);
         G[i][b].push_back(a);
      }
      path[i] = make_path(i);
   }

   printf("%d %d\n", path[0][ (path[0].size())/2 ] ,
                     path[1][ (path[1].size())/2 ]);
}
