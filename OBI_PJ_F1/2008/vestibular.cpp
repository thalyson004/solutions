#include <iostream>
using namespace std;

int main(){
   int questoes, acertos = 0;
   string prova, gabarito;

   cin >> questoes >> prova >> gabarito;

   for(int i = 0; i < questoes; i++){
      if( prova[i]==gabarito[i] ){
         acertos++;
      }
   }
   cout << acertos << endl;
}
