class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> inside(nums.size(), false);
        for(int num: nums) {
            if(num>=1 and num <= nums.size()){
                inside[num-1]=true;
            }
        }
        
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            if(!inside[i]){
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};
