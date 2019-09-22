#include <iostream>
using namespace std;

int main(){
   int N, B=0, x;
   cin >> N;

   for(int i = 0; i < N; i++){
      cin >> x;
      if(x==2){
         B++;
      }
   }
   cout << N%2 << endl << B%2 << endl;
}
