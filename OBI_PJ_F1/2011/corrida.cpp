#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int N, M, t;
   pair< int, int > carros[105];

   cin >> N >> M;

   for(int i = 0; i < N; i++){
      carros[i].second = i+1;
      for(int j = 0; j < M; j++){
         cin >> t;
         carros[i].first += t;
      }
   }
   sort(carros, carros + N);
   cout << carros[0].second << endl;
   cout << carros[1].second << endl;
   cout << carros[2].second << endl;
}
