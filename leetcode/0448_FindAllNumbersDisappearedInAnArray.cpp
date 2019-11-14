class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int M=1;
        vector<int> color(nums.size()+1);
        for(int e: nums) color[e]=1;
        vector<int> ans;
        for(int i = 1; i<=nums.size(); i++) 
            if(!color[i])
                ans.push_back( i );
        return ans;
    }
};
