static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(!nums.size())return 0;
        int ans = 1;
        int cur = 1;
        for(int i = 1; i < nums.size(); i++){
            if( nums[i]>nums[i-1] ) cur++;
            else cur = 1;
            if(ans<cur)ans=cur;
        }
        return ans;
    }
};