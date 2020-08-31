class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        int i = 0, j = 1;
        while(j < nums.size()){
            while(j < nums.size() and nums[i]==nums[j] )j++;
            if( j<nums.size() ) nums[++i] = nums[j++];
        }
        nums.resize(i+1);
        return i+1;
    }
};
