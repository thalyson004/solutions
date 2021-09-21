class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        for(int value: nums){
            if(value) cur++;
            else{
                ans = max(ans, cur);
                cur = 0;
            }
        }
        return max(ans, cur);
    }  
};
