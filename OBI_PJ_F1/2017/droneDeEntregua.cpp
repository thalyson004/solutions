#include <iostream>
using namespace std;

int main(){
   int A, B, C, H, L;
   cin >> A >> B >> C >> H >> L;

   if( (A<=H and B <= L) or (A<=L and B <= H) or
       (A<=H and C <= L) or (A<=L and C <= H) or
       (C<=H and B <= L) or (C<=L and B <= H) ){
      cout << "S" << endl;
   }else{
      cout << "N" << endl;
   }
}
