#include <iostream>
#include <algorithm>
using namespace std;

struct pais{
   int ouro, prata, bronze, id;

   bool operator < (pais &temp){
      if( ouro != temp.ouro ) return ouro > temp.ouro;
      if( prata != temp.prata ) return prata > temp.prata;
      if( bronze != temp.bronze ) return bronze > temp.bronze;
      return id < temp.id;
   }
};

int main(){
   int N, M;
   pais V[110];

   cin >> N >> M;
   for(int i = 1; i <= N; i++){
      V[i] = {0,0,0,i};
   }
   for(int i = 0; i < M; i++){
      int o, p, b;
      cin >> o >> p >> b;
      V[o].ouro++;
      V[p].prata++;
      V[b].bronze++;
   }
   sort( V+1, V+1+N );

   for(int i = 1; i <= N; i++){
      cout << V[i].id << " ";
   }
}
