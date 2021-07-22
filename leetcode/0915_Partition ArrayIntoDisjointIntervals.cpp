class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> posSmaller(n);
        for(int i = n-1; i >= 0; i--) 
            posSmaller[i] = min(nums[i], (i+1<n?posSmaller[i+1]:INT_MAX) );
        
        int preGreater = INT_MIN;
        for(int i = 0; i < n; i++){
            preGreater = max(preGreater, nums[i]);
            if(preGreater <= posSmaller[i+1])
                return i+1;
        }
        return n+1;
    }
};
