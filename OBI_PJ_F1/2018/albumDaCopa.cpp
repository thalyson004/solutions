#include <iostream>
using namespace std;

int main(){
   int N, M, x, resposta;
   int album[105] = {0};

   cin >> N >> M;
   resposta = N;

   for(int i = 0; i < M; i++){
      cin >> x;
      if( album[x]==0 ){
         resposta -= 1;
      }
      album[x] = 1;
   }
   cout << resposta << endl;
}
