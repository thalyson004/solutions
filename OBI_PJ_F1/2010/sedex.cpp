#include <iostream>
using namespace std;

int main(){
   int D, A, B, C;

   cin >> D >> A >> B >> C;
   if(D<=A and D<=B and D<=C){
      cout << "S" << endl;
   }else{
      cout << "N" << endl;
   }
}
