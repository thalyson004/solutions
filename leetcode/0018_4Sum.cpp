class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i+3 < nums.size(); i++){
            for(int j = i+1; j+2 < nums.size(); j++){
                for(int k = j+1; k+1 < nums.size(); k++){
                    int t = target-nums[i]-nums[j]-nums[k];
                    
                    if( binary_search(nums.begin()+k+1, nums.end(), t) ){
                        ans.push_back( {nums[i], nums[j], nums[k], t} );
                        sort(ans.back().begin(), ans.back().end());
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase( unique(ans.begin(), ans.end()), ans.end() );
        
        return ans;
    }
};
