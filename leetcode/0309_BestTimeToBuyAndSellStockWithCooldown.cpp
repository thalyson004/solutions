class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, 0);
        
        for(int i = 1; i < n; i++){
            int mx = INT_MIN;
            dp[i] = dp[i-1];
            
            for(int j = i-1; j>=0; j--){
                mx = max(mx, prices[j]);
                dp[i] = max(dp[i], prices[i]-prices[j] + (j>=2?dp[j-2]:0));
            }
        }
        
        return dp[n-1];
    }
};
