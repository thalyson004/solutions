class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++)
            for(int j = i+1; j < nums.size(); j++)
                ans += nums[i]==nums[j] and (i*j)%k == 0;
        
        return ans;
    }
};
