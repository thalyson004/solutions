class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        if(nums.size()<=2){
            for(int i = 0; i < nums.size();i++){
                ans = max(ans, nums[i]);
            }
            return ans;
        }
        
        vector<vector<int>> dp(2, vector<int>(nums.size())) ;
        dp[0][0] = 0;
        dp[0][1] = nums[1];
        
        dp[1][0] = nums[0];
        dp[1][1] = max(nums[0],nums[1]);
        
        ans = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            
            dp[0][i] = max(dp[0][i-1], dp[0][i-2]+nums[i]);
            
            if(i+1!=nums.size())
                dp[1][i] = max(dp[1][i-1], dp[1][i-2]+nums[i]);
            
            ans = max(ans, max(dp[0][i], dp[1][i]));
        }
        
        return ans;
    }
};
