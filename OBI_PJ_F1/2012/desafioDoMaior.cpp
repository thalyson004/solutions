#include <iostream>
using namespace std;

int main(){
   int maior=0, x;
   do{
      cin >> x;
      if(maior < x){
         maior = x;
      }
   }while(x!=0);
   cout << maior << endl;
}
