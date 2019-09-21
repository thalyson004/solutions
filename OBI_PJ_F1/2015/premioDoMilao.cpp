#include <iostream>
using namespace std;

int main(){
   int N, soma = 0, A, resposta, milao = 1000000;

   cin >> N;
   for(int  i = 1; i <= N; i++){
      cin >> A;
      if(soma < milao and soma+A>=milao){
         resposta = i;
      }
      soma += A;
   }
   cout << resposta << endl;
}
