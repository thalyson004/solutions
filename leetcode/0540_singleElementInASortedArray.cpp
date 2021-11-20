class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left<right){
            int mid = (left+right)/2;
            
            
            int plus = (nums[mid]==nums[mid+1]);
            
            if((mid+plus)%2==0){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        
        return nums[left];
    }
};
