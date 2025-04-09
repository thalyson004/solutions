class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> temp = nums;

        sort(temp.rbegin(), temp.rend());

        if(k > temp.back()) return -1;

        int ans = 0, cur = temp[0];

        for(int value: temp){
            if(value != cur){
                cur = value;
                ans++;
            }
        }

        if(k < temp.back()) ans++;
        return ans;
    }
};
