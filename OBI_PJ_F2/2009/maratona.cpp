#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int N, M;
   int A, B, ok = 1;

   cin >> N >> M;
   cin >> A;

   for(int i = 1; i < N; i++){
      cin >> B;
      if(B-A > M){
         ok = 0;
      }
      A = B;
   }

   if(42195-A > M){
      ok = 0;
   }

   if(ok==1){
      cout << "S\n";
   }else{
      cout << "N\n";
   }
}
