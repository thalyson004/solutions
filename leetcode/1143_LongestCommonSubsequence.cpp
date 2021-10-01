class Solution {
public:
    
    int solve(int i1, string &t1, int i2, string &t2, vector<vector<int>> &dp){
        if(i1==t1.size() or i2==t2.size()) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
            
        if(t1[i1]==t2[i2]) return dp[i1][i2] = 1 + solve(i1+1, t1, i2+1, t2, dp);
        else{
            return dp[i1][i2] = max(solve(i1+1, t1, i2, t2, dp),
                       solve(i1, t1, i2+1, t2, dp));    
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return solve(0, text1, 0, text2, dp);
    }
};
