#include <iostream>
using namespace std;

int main(){
   int N, P, resposta = 0;
   int F1, F2;

   cin >> N >> P;

   for(int i = 0; i < N; i++){
      cin >> F1 >> F2;
      if(F1+F2>=P){
         resposta++;
      }
   }
   cout << resposta << endl;
}
