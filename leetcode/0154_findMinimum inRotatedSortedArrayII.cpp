class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int first_less = 0;
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right){
            int mid = (left + right)/2;
            
            if(nums[mid] < nums[right]){
                right = mid;
            }else if(nums[mid] > nums[right]){
                left = mid+1;
            }else{
                right--;
            }
        }
        
        return nums[left];
    }
};
