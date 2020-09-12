class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> cur;
    
    void solve(int least, int greater, int sum){
        if( least==0 and sum ==0 ){
            ans.push_back(cur);
        }if( sum*2 < (greater+1 + greater+min(least,9-greater))*min(least,9-greater) ){
            return;
        }else{
            for(int i = greater+1; i <= 9; i++){
                cur.push_back(i);
                solve(least-1, i, sum-i);
                cur.pop_back();
            }    
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        ans = vector<vector<int>>();
        cur = vector<int>();
        solve(k, 0, n);
        return ans;
    }
};
