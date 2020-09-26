class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(!n or !k)return 0;
        
        if (k >= n/2){
            int ans = 0;
            for (int i = 1; i < n; i++)
                ans += max(0, prices[i] - prices[i - 1]);
            return ans;
        }
        
        vector<int> buy(k,100000), profit(k,0);
    
        for(int &p: prices){
            buy[0] = min(buy[0], p);
            profit[0] = max(profit[0], p - buy[0]);
            for(int b = 1; b < k; b++){
                buy[b] = min(buy[b], p-profit[b-1]);
                profit[b] = max(profit[b], p-buy[b]);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < k; i++)
            ans = max(ans, profit[i]);
        
        return ans;
    }
};
