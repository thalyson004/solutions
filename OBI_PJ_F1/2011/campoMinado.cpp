#include <iostream>
using namespace std;

int main(){
   int N;
   int vetor[55]={0};

   cin >> N;
   for(int i = 1; i <= N; i++){
      cin >> vetor[i];
   }
   for(int i = 1; i <= N; i++){
      cout << vetor[i-1]+vetor[i]+vetor[i+1] << endl;
   }
}
