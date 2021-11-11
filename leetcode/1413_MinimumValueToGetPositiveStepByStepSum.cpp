class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = 0;
        int sum = 0;
        for(int value: nums){
            sum += value;
            mn = min(mn, sum);
        }
        return max(1, 1-mn);
    }
};
