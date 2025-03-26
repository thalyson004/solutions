class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int n = grid.size();
        int m = grid[0].size();
        int l = n*m;
        vector<int> v;
        set<int> remains;

        for(vector<int> line: grid){
            for(int el: line){
                v.push_back(el/x);
                remains.insert(el%x);

                if(remains.size() == 2) 
                    return -1;
            }
        }
        sort(v.begin(), v.end());
        vector<int> pre(l), pos(l);
        for(int i = 0; i < l; i++) pre[i] = v[i] + (i?pre[i-1]:0);
        for(int i = l-1; i >= 0; i--) pos[i] = v[i] + (i<l-1?pos[i+1]:0);
        int ans = INT_MAX;

        for(int i = 0; i < l; i++){
            int total = pos[i]-pre[i]+v[i]*(2*i+1-l);
           
            ans = min(ans, total);
        }

        return ans;
    }
};
