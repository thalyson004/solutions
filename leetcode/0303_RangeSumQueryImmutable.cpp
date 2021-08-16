class NumArray {
public:
    vector<int> sum;
    
    NumArray(vector<int>& nums) {
        sum = nums;
        for(int i = 1; i < sum.size(); i++) 
            sum[i] += sum[i-1];
    }
    
    int sumRange(int left, int right) {
        return sum[right] - ( left>0 ? sum[left-1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
