class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int dx[4] = {0,-1,1,0};
        int dy[4] = {-1,0,0,1};
        int dp[4][n+1][n+1];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int d=0;d<4;d++){
                    dp[d][i][j] = 1;
                }
            }
        }
        for(auto mine:mines){
            int i = mine[0];
            int j = mine[1];
            for(int d = 0; d < 4; d++){
                dp[d][i][j] = 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int d=0;d<2;d++){
                    if(dp[d][i][j] and i+dx[d]>=0 and i+dx[d]<n and j+dy[d]>=0 and j+dy[d]<n){
                        dp[d][i][j] += dp[d][i+dx[d]][j+dy[d]];
                    }
                }
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                for(int d=2;d<4;d++){
                    if(dp[d][i][j] and i+dx[d]>=0 and i+dx[d]<n and j+dy[d]>=0 and j+dy[d]<n){
                        dp[d][i][j] += dp[d][i+dx[d]][j+dy[d]];
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cur = INT_MAX;
                for(int d=0;d<4;d++){
                    cur = min(cur, dp[d][i][j]);
                }
                ans = max(cur, ans);
            }
        }
        
        return ans;
    }
};
