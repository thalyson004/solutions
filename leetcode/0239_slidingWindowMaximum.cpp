class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set< pair<int,int> > on;
        for(int i = 0; i < k-1; i++){
            on.insert( {-nums[i], i} );
        }
        vector<int> ans;
        for(int i = k-1; i<nums.size(); i++){
            on.insert( {-nums[i], i} );
            ans.push_back( -(on.begin()->first) );
            on.erase( {-nums[i-k+1], i-k+1} );
        }
        return ans;
    }
};
