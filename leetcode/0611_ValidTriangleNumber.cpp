class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j+1 < nums.size(); j++){
                
                int sum = nums[i]+nums[j];
                int k = lower_bound(nums.begin()+j+1, nums.end(), sum) - nums.begin()-1;
                
                ans += k-j;
            }
        }
        return ans;
    }
};
