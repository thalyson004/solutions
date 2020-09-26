class Solution {
public:
    int maxProfit(vector<int>& prices) {
  
        vector<int> buy(2,100000), profit(2,0);
    
        for(int p: prices){
            buy[0] = min(buy[0], p);
            profit[0] = max(profit[0], p - buy[0]);
           
            buy[1] = min(buy[1], p-profit[0]);
            profit[1] = max(profit[1], p-buy[1]);
            
        }
        
        return max(profit[0], profit[1]);
        
    }
};
