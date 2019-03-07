class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return (p<nums.size() and nums[p]==target)?p:-1;
    }
};
