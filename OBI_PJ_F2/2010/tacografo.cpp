#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int N;
   int total = 0;

   cin >> N;
   for(int i = 0; i < N; i++){
      int T, V;
      cin >> T >> V;
      total += T*V;
   }
   cout << total << endl;
}
