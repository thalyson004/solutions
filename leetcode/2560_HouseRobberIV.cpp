class Solution {
public:
    int minCapability(vector<int>& nums, int k) {

        auto check = [&](int mx){
            int i = 0, ctn = 0;
            while(i < nums.size()){
                if(nums[i] <= mx){
                    i++;
                    ctn++;
                }
                i++;
            }
            return ctn >= k;
        };

        int l = 0, r = 1<<30;
        while(l < r){
            int m = (l+r)/2;

            if(check(m)){
                r = m;
            }else{
                l = m+1;
            }
        }
        return l;
    }
};
