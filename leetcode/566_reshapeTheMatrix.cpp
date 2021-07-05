class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n!=r*c) return mat;
        
        vector< vector<int> > ans(1);
        for(int i=0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans.back().push_back( mat[i][j] );
                if(ans.back().size()==c) ans.push_back(vector<int>());
            }
        }
        ans.pop_back();
        return ans;
    }
};
