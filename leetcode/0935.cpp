const int dx[8] = {1, 1, -1, -1, 2, -2, 2, -2};
const int dy[8] = {2, -2, 2, -2, 1, 1, -1, -1};
int dp[4][3][5005];
int ans[5005];
int MOD = 1000000007;
int maior = 1;

class Solution {
public:
   
   int limite(int a, int b){
      return a>=0 and a<4 and b<3 and b>=0 and !(a==3 and b==0) and !(a==3 and b==2);
   }

   Solution(){
      for(int i = 0; i < 4; i++)
      for(int j = 0; j < 3; j++)
         dp[i][j][1] = 1;
      dp[3][0][1] = dp[3][2][1] = 0;
      ans[1] = 10;
   }

   int knightDialer(int N) {
        if(maior < N){
    for(int k = maior; k < N; k++){
        ans[k+1] = 0;
        dp[3][0][k] = dp[3][2][k] = 0;

        for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
        for(int m =0; m < 8; m++)
        if( limite(i+dx[m], j+dy[m]) ){
        ans[k+1] = (ans[k+1]+dp[i][j][k])%MOD;
        dp[i+dx[m]][j+dy[m]][k+1] = (dp[i+dx[m]][j+dy[m]][k+1] + dp[i][j][k])%MOD;
            
        }
        
    }
        maior = N;
        }
      return ans[N];
   }
     
};
