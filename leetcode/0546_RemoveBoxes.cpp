class Solution {
public:
    int dp[100][100][100];
    
    int solve(int left, int right, int get, vector<int> &boxes){
        if(left>right) return 0;
        if(dp[left][right][get]!=-1) return dp[left][right][get];
        
        int &ans = dp[left][right][get];
        ans = (get+1)*(get+1) + solve(left+1, right, 0, boxes);
        
        for(int i = left+1; i <=right; i++){
            if(boxes[left]==boxes[i]){
                ans = max(ans, solve(left+1,i-1, 0, boxes)+solve(i, right, get+1, boxes) );
            }
        }
        
        return ans;
    }
    
    int removeBoxes(vector<int>& boxes) {
        
        memset(dp,-1, sizeof dp);
        int n = boxes.size();
        return solve(0, n-1, 0, boxes);
        
    }
};
