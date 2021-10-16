class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][3][2];
        
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = dp[0][1][1] = INT_MIN;
        dp[0][2][0] = INT_MIN;
        int ans = 0;
        
        for(int i = 1; i < n; i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0]-prices[i]);
            
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][1]+prices[i]);
            
            dp[i][1][1] = dp[i-1][1][1];
            if(dp[i-1][1][0]!= INT_MIN) 
                dp[i][1][1] = max(dp[i][1][1], dp[i-1][1][0]-prices[i]);
            
            dp[i][2][0] = dp[i-1][2][0];
            if(dp[i-1][1][1]!=INT_MIN)
                dp[i][2][0] = max(dp[i][2][0], dp[i-1][1][1]+prices[i]);
            
            ans = max(ans, dp[i][1][0]);
            ans = max(ans, dp[i][2][0]);
        }
         
        
        return ans;
    }
};
