class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return vector<vector<int>>();
        
        sort(intervals.begin(), intervals.end());
        
        
        vector<vector<int>> ans;
        int left = intervals[0][0];
        int right = intervals[0][1];
        
        for(auto interval: intervals){
            if(interval[0]<=right){
                right = max(right, interval[1]);
            }else{
                ans.push_back(vector<int>({left,right}));
                left = interval[0];
                right = interval[1];
            }
        }
        
        ans.push_back(vector<int>({left,right}));
        
        return ans;
    }
};
