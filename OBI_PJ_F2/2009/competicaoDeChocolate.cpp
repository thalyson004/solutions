#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int N, M;
   cin >> N >> M;

   if( N>M and N%(M+1)==0 ){
      cout << "Carlos" << endl;
   }else{
      cout << "Paula" << endl;
   }
}
