class Solution {
public:


    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        vector<int> quant(1005);
        for(int n: nums) quant[n]++;

        vector<int> uniques;
        for(int n:quant){
            if(n){
                uniques.push_back(n);
            }
        }

        int n = uniques.size();
        int m = quantity.size();

        vector<int> sum(1<<m);
        for(int i = 0; i < (1<<m);i++){
            for(int j = 0; j < m; j++){
                sum[i] += !!(i&(1<<j))*quantity[j];
            }
        }

        vector<vector<bool>> dp(n+1, vector<bool>(1<<m));
        dp[0][0] = true;
        for(int i = 0; i < n; i++){
            for(int here = 0; here < (1<<m); here++){
                if(dp[i][here]==false) continue;

                for(int complete = 0; complete < (1<<m); complete++){
                    if( (complete&here) != here) continue;
                    if( sum[complete^here]>uniques[i] ) continue;
                    dp[i+1][complete] = dp[i+1][complete] or dp[i][here];
                }
            }
        }

        return dp[n][ (1<<m)-1 ];
    }
};
