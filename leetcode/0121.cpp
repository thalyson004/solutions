class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        
        int ans = 0;
        int small = prices[0];
        for(int i = 1; i < prices.size(); i++){
            ans = max(ans, prices[i]-small );
            small = min(small, prices[i]);
        }
        return ans;
    }
};
