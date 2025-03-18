class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;

        int right = 0, mask = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(right==i){
                mask |= nums[right++];
                cnt++;
            }

            while(right < nums.size() and (nums[right]&mask)==0){
                mask |= nums[right++];
                cnt++;
            }

            ans = max(ans, cnt);
            mask ^= nums[i];
            cnt--;
        }
        
        return ans;
    }
};
