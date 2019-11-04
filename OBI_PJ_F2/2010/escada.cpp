#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int N;
   int total = 0, ultima;

   cin >> N >> ultima;
   for(int i = 1; i < N; i++){
      int M;
      cin >> M;

      if(ultima+10>= M){
         total += M-ultima;
      }else{
         total += 10;
      }
      ultima = M;
   }
   total += 10;
   cout << total << endl;
}
