#include <iostream>
using namespace std;

int main(){
   int tamanho;
   string estrada;
   int resposta=0;

   cin  >> tamanho >> estrada;

   for(int i = 0; i < tamanho; i++){
      if( estrada[i] == 'A' ){
         resposta += 1;
      }else if(estrada[i]=='P' or estrada[i]=='C'){
         resposta += 2;
      }
   }

   cout << resposta << endl;
}
