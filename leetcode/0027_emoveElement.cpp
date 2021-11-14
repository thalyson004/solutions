class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int next = 0;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==val){
                next = max(next, i+1);
                while(next < nums.size() and nums[next]==val){
                    next++;
                }
                if(next < nums.size()){
                    swap(nums[i], nums[next++]);
                    ans = i;
                }
            }else{
                ans = i;
            }
        }
        
        return ans+1;
    }
};
