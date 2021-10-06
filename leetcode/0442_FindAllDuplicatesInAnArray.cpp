class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            while(nums[i]!=i+1 and nums[i]>0){
                if(nums[i] == nums[nums[i]-1]){
                    ans.push_back(nums[i]);
                    nums[i]=-nums[i];
                    break;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        return ans;
    }
};
