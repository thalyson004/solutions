#include <iostream>
using namespace std;

int main(){
   int N, total = 0;
   int bebidas, copos;

   cin >> N;
   for(int i = 0; i < N; i++){
      cin >> bebidas >> copos;
      if(bebidas>copos){
         total += copos;
      }
   }
   cout << total << endl;
}
