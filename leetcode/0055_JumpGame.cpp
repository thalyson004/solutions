class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 1;
        for(int value: nums){
            if(!jump) return false;
            jump--;
            jump = max(jump, value);
        }
        return true;
    }
};
