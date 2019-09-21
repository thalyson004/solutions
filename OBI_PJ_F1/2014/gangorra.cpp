#include <iostream>
using namespace std;

int main(){
   int P1, C1, P2, C2;
   cin >> P1 >> C1 >> P2 >> C2;
   int resposta;

   if(P1*C1 < P2*C2){
      resposta = 1;
   }
   if(P1*C1 == P2*C2){
      resposta = 0;
   }
   if(P1*C1 > P2*C2){
      resposta = -1;
   }

   cout << resposta << endl;
}
