class Solution {
public:

    int maximumCount(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int neg=0, pos=0;

        while(l<r){
            int m = (l+r+1)/2;

            if(nums[m] <0){
                l = m;
            }else{
                r = m-1;
            }
        }
        if(l==r and nums[l]<0){
            neg = l+1;
        }
        l = 0, r = nums.size()-1;
        while(l<r){
            int m = (l+r)/2;

            if(nums[m] >0){
                r = m;
            }else{
                l = m+1;
            }
        }

        if(l==r and nums[l]>0){
            pos= nums.size()-l;
        }

        return std::max(neg, pos);
    }
};
