#include <iostream>
using namespace std;

int main(){
   int N, K, x;
   int quantidade[1005] = {0};
   cin >> N >> K;

   for(int i = 0; i < N; i++){
      cin >> x;
      quantidade[x]++;
   }
   int menor = quantidade[1];
   for(int i = 2; i <= K; i++){
      if( menor > quantidade[i] ){
         menor = quantidade[i];
      }
   }
   cout << menor << endl;
}
