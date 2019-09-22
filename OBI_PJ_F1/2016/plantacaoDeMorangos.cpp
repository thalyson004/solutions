#include <iostream>
using namespace std;

int main(){
   int C1, L1, C2, L2, A1, A2;
   cin >> C1 >> L1 >> C2 >> L2;
   A1 = C1*L1;
   A2 = C2*L2;

   if(A1 > A2){
      cout << A1 << endl;
   }else{
      cout << A2 << endl;
   }
}
