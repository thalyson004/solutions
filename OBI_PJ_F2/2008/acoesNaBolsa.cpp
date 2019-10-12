#include <iostream>
using namespace std;

int main(){
   int N;
   int V[100005];

   cin >> N;
   for(int i = 0; i < N; i++){
      cin >> V[i];
   }
   int resposta = -1000*4;
   for(int i = 3; i < N; i++){
      int soma = 0;
      for(int j = 0; j < 4; j++){
         soma += V[i-j];
      }
      if(soma > resposta){
         resposta = soma;
      }
   }
   cout << resposta << endl;
}
