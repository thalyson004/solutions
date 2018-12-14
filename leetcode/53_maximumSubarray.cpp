class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int cur = max(0, nums[0]);
        for(int i = 1; i < nums.size(); i++){
            cur += nums[i];
            ans = max(ans, cur);
            cur = max(cur, 0);
        }
        return ans;
    }
};
