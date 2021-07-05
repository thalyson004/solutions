class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> presum = matrix;
        
        for(int i=0; i <m; i++){
            for(int j = 0; j < n; j++){
                presum[i][j] += (i?presum[i-1][j]:0);
                presum[i][j] += (j?presum[i][j-1]:0);
                presum[i][j] -= (j and i?presum[i-1][j-1]:0);
            }
        }
        
        set<int> sums[n][n];
        
        int ans = -1000000;
        for(int j = 0; j < n; j++){
            
            for(int i = 0; i < m; i++){
                int sum = presum[i][j] - k;
                
                for(int ii = 0; ii<=i; ii++){
                    sum -= (ii?presum[ii-1][j]:0);
                    
                    int cost = -(j?presum[i][j-1]:0)+(ii and j?presum[ii-1][j-1]:0);
                    sums[i][ii].insert( -cost );
                    
                    auto it = sums[i][ii].lower_bound(sum);
                    
                    if(it != sums[i][ii].end()){
                        if( (sum-*it+k) >ans ) ans = (sum-*it+k);
                    }
                    
                    sum += (ii?presum[ii-1][j]:0);
                }
            }
        }
        return ans;
    }
};
