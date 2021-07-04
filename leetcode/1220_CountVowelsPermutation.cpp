class Solution {
public:

    int countVowelPermutation(int n) {
        vector<int> dp(5, 1);
        int mod = 1e9+7;
        
        for(int len = 1; len < n; len++){
            dp = {  ((dp[1]+dp[2])%mod+dp[4])%mod,
                    (dp[0]+dp[2])%mod,
                    (dp[1]+dp[3])%mod,
                    (dp[2]),
                    (dp[2]+dp[3])%mod};
        }
        
        int ans = 0;
        for(int i =0; i < 5; i++) ans = (ans+dp[i])%mod;
        return ans;
    }
};
