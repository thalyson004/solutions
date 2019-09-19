#include <iostream>
using namespace std;

int main(){
   int maximo, A, B, resultado;
   char operacao;

   cin >> maximo >> A >> operacao >> B;
   if(operacao == '+'){
      resultado = A+B;
   }else{
      resultado = A*B;
   }

   if(maximo<resultado){
      cout << "OVERFLOW" << endl;
   }else{
      cout << "OK" << endl;
   }
}
