class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cur = heights;
        sort(cur.begin(), cur.end());
        int ans = 0;
        for(int i = 0; i < cur.size(); i++){
            ans += (cur[i]!=heights[i]);
        }
        return ans;
    }
};
