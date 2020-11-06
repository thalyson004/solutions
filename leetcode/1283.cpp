class Solution {
public:
    int getSum(vector<int>&nums, int div){
        int sum = 0;
        for(int value:nums) sum += (value+div-1)/div;
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1000000;
        while(left<right){
            int mid = (left+right)/2;
            int sum = getSum(nums, mid);
            if(sum<=threshold){
                right = mid;
            }else{
                left = mid+1;    
            }
        }
        return left;
    }
};
