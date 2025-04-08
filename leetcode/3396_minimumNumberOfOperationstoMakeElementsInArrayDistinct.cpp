class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> have;

        for(int i = nums.size()-1; i>=0; i--){
            if(have.count(nums[i])) return (i+1)/3 + !!((i+1)%3);
            have.insert(nums[i]);
        }

        return 0;
    }
};
