class Solution {
public:
    vector<vector<int>> dp;
    string s, t;
    
    int solve(int i, int j){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j] = solve(i+1, j);        
        if( s[i]==t[j] ) dp[i][j] += solve(i+1, j+1);

        return dp[i][j];
    }
    
    int numDistinct(string s, string t) {
        dp = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        
        this->s = s;
        this->t=t;
                               
        return solve(0,0);
    }
};
