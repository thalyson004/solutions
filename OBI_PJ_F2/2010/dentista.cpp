#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int N;
   int quantidade = 0, termino = 0;

   cin >> N;
   for(int i = 0; i < N; i++){
      int X, Y;
      cin >> X >> Y;

      if( X>=termino ){
         quantidade++;
         termino = Y;
      }else if( termino > Y ){
         termino = Y;
      }
   }

   cout << quantidade << endl;
}
