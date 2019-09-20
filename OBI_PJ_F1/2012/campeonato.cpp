#include <iostream>
using namespace std;

int main(){
   int cv, ce, cs, fv, fe, fs, cp, fp;
   char ganhador;

   cin >> cv >> ce >> cs >> fv >> fe >> fs;
   cp = 3*cv + ce;
   fp = 3*fv + fe;

   if( cp != fp ){
      if(cp < fp) ganhador = 'F';
      else ganhador  = 'C';
   }else{
      if( cs < fs ) ganhador = 'F';
      else if( cs > fs ) ganhador = 'C';
      else ganhador = '=';
   }
   cout << ganhador << endl;
}
