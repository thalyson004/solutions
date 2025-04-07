class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        sum /= 2;
        vector<bool> check(sum+1);

        check[0] = true;
        for(int value: nums){
            for(int i = sum; i-value >= 0; i--)
                if( check[i-value] )
                    check[i] = true;        

                if(check[sum])
                    return true;
            }    

        return check[sum];
    }
};
