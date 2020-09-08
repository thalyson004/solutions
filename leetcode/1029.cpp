class Solution {
public:
    
    vector<vector<int>> dp;
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = ((int)costs.size())/2;
        const int oo = 1000*1000;
        dp = vector<vector<int>>(n*2, vector<int>(n+1,oo));
        
        dp[0][0] = costs[0][1];
        dp[0][1] = costs[0][0];
        
        for(int i = 1; i < costs.size(); i++){
            for(int j = 0; j <= n; j++){
                if(dp[i-1][j]!=oo){
                    dp[i][j] = dp[i-1][j]+costs[i][1];
                }
            }
            for(int j = 1; j <= n; j++){
                if(dp[i-1][j-1]!=oo){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+costs[i][0]);
                }
            }
        }
        
        return dp[-1+costs.size()][n];
    }
};
