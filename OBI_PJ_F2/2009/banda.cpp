#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int N, M;
   int a,b,c,atual=0, total;
   int score[105][105];
   for(int i = 1; i <=N ;i++)
      for(int j = i+1; j <=N ;j++)
         score[i][j] = score[j][i] = 0;

   cin >> N >> M;
   for(int i = 0; i < M; i++){
      cin >> a >> b >> c;
      score[a][b] = score[b][a] = c;
   }

   for(int i = 1; i <=N ;i++){
      for(int j = i+1; j <=N ;j++){
         for(int k = j+1; k <=N ;k++){
            total = score[i][j] + score[i][k] + score[j][k];
            if( atual <= total ){
               atual = total;
               a = i; b = j; c = k;
            }
         }
      }
   }
   cout << a << " " << b << " " << c << endl;
}
