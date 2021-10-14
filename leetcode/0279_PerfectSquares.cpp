class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n+5);
        dp[n] = 0;
        
        for(int i = n; i > 0; i--){
            for(int s = 1; i-s*s>=0; s++){
                dp[i-s*s] = min(dp[i-s*s], dp[i]+1);
            }    
        }
        
        return dp[0];
    }
};
