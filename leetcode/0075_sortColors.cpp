class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for(int color: nums) count[color]++;
        int i = 0;
        for(int color=0; color<3; color++){
            for(int j = 0; j < count[color]; j++){
                nums[i++] = color;
            }
        }
    }
};
