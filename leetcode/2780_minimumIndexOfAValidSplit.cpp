class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        auto getMajor = [](vector<int> &v){
            int actual = v[0];
            int count = 1;

            for(int i = 0; i < v.size(); i++){
                if(actual == v[i]) count ++;
                else {
                    count--;
                    if(count<0){
                        count = 1;
                        actual = v[i];
                    }
                }
            }
            count = 0;
            for(int  value:v) count += (value == actual);

            return (count>v.size()/2) ? actual : -1;
        };

        int major = getMajor(nums);
        if(major == -1) return -1;

        vector<int> pre(nums.size()), pos(nums.size());
        for(int i = 0; i < nums.size(); i++) pre[i] = (nums[i]==major) + (i?pre[i-1]:0);
        for(int i = nums.size()-1; i >= 0; i--) 
            pos[i] = (nums[i]==major) + (i<nums.size()-1?pos[i+1]:0);

        for(int i = 0; i + 1 < nums.size(); i++){
            int left = (pre[i] > (i+1)/2);
            int right = (pos[i+1] > (nums.size()-i-1)/2 );
            if(left and right) return i;
        }
        return -1;
    }
};
