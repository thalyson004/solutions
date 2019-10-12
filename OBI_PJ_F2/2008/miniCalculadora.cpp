#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int N, D, Q, mdc;
   cin >> N >> D >> Q;

   mdc = __gcd(D,Q);
   D = D/mdc;
   Q = Q/mdc;

   if( D<=N and Q<=N ){
      cout << D << " " << Q << endl;
   }else{
      cout << "IMPOSSIVEL" << endl;
   }
}
