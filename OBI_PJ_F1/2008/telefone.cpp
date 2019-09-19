#include <iostream>
using namespace std;

int main(){
   string telefone;
   cin >> telefone;

   for(int i = 0; i < telefone.size(); i++){
      char c = telefone[i], n = telefone[i];
      if( c=='A' or c=='B' or c=='C') n = '2';
      if( c=='D' or c=='E' or c=='F') n = '3';
      if( c=='G' or c=='H' or c=='I') n = '4';
      if( c=='J' or c=='K' or c=='L') n = '5';
      if( c=='M' or c=='N' or c=='O') n = '6';
      if( c=='P' or c=='Q' or c=='R' or c=='S') n = '7';
      if( c=='T' or c=='U' or c=='V') n = '8';
      if( c=='W' or c=='X' or c=='Y' or c=='Z') n = '9';
      cout << n;
   }
}
