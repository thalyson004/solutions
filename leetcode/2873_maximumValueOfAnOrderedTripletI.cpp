class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), pos(n);

        for(int i = 0; i < n; i++) pre[i] = max(i?pre[i-1]:0, nums[i]);
        for(int i = n-1; i >= 0; i--) pos[i] = max(i+1<n?pos[i+1]:0, nums[i]);

        long long ans = 0;
        for(int i = 1; i+1 < n; i++) ans = max(ans, 1LL*(pre[i-1]-nums[i])*pos[i+1]);

        return ans;
    }
};
