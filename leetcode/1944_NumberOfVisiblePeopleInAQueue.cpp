class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        vector<int> h;
        
        for(int i = n-1; i >= 0; i--){
            while(h.size() and heights[i]>h.back()){
                ans[i]++;
                h.pop_back();
            }
            if(h.size()) ans[i]++;
            h.push_back(heights[i]);
        }
        
        return ans;
    }
};
