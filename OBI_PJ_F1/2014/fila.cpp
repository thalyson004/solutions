#include <iostream>
using namespace std;

int main(){
   int N, M;
   int fora[100005] = {0};
   int fila[50005], saiu;

   cin >> N;
   for(int i = 0; i < N; i++){
      cin >> fila[i];
   }
   cin >> M;
   for(int i = 0; i < M; i++){
      cin >> saiu;
      fora[ saiu ] = 1;
   }
   for(int i = 0; i < N; i++){
      if( fora[ fila[i] ]==0 ){
         cout << fila[i] << " ";
      }
   }
   cout << endl;
}
