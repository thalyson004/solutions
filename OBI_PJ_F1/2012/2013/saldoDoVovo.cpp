#include <iostream>
using namespace std;

int main(){
   int N, S, menor, movimento;

   cin >> N >> S;
   menor = S;

   for(int i = 0; i < N; i++){
      cin >> movimento;
      S += movimento;
      if( menor > S ){
         menor = S;
      }
   }
   cout << menor << endl;
}
