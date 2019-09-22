#include <iostream>
using namespace std;

int main(){
   int N;
   int fita[10005];

   cin >> N;
   fita[0] = fita[N+1] = -1;
   for(int i = 1; i <= N; i++){
      cin >> fita[i];
   }

   for(int d = 0; d < 8; d++){
      for(int i = 1; i <= N; i++){
         if(fita[i] == -1 and (fita[i-1]==d or fita[i+1]==d)){
            fita[i] = d+1;
         }
      }
   }
   for(int i = 1; i <= N; i++){
      if(fita[i]==-1){
         fita[i] = 9;
      }
   }
   for(int i = 1; i <= N;i++){
      cout << fita[i] << " ";
   }
   cout << endl;
}
