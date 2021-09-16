class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        vector<int> ans;
        int i=0, j = 0;
        int d = 0;
        int flag = true;
        
        while(flag){
            ans.push_back( matrix[i][j] );
            flag = false;
            int block = 0;
            while(block < 4){
                if( i+dr[d]<matrix.size() and i+dr[d]>=0 and 
                    j+dc[d]<matrix[0].size() and j+dc[d]>=0 and
                    matrix[i+dr[d]][j+dc[d]]!=INT_MAX){
                    matrix[i][j]= INT_MAX;
                    i+=dr[d];
                    j+=dc[d];
                    flag = true;
                    break;
                }
                d = (d+1)%4;
                block++;
            }
        }
        return ans;
    }
};
