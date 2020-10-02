class Solution {
public:
    
    void solve(int id, int target, vector<int> &cur, vector<int> &candidates, vector<vector<int>> &ans){
        if(id==candidates.size()) return;
        if(target==0){
            ans.push_back( cur );
            return;
        }
        if(target>=candidates[id]) {
            cur.push_back( candidates[id] );
            solve(id, target-candidates[id], cur, candidates, ans);
            cur.pop_back();
            
            solve(id+1, target, cur, candidates, ans);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end() );
        vector< vector<int> > ans;
        vector< int > cur;
        solve(0, target, cur, candidates, ans);
        return ans;
        
    }
};
