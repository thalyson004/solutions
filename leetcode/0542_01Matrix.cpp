class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue< pair<int,int> > bfs;
        for(int row=0; row<mat.size(); row++)
            for(int col=0; col<mat[0].size(); col++){
                if(mat[row][col]==0){
                    bfs.push( {row, col});
                }else{
                    mat[row][col] = -1;
                }
            }
        
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while( bfs.size() ){
            auto [row, col] = bfs.front();
            bfs.pop();
            
            for(int d=0; d < 4; d++){
                int nrow = row+dr[d];
                int ncol = col+dc[d];
                
                if(nrow>=0 and nrow<mat.size() and ncol>=0 and ncol<mat[0].size() and mat[nrow][ncol]<0){
                    mat[nrow][ncol] = mat[row][col]+1;
                    bfs.push( {nrow, ncol} ); 
                }
            }
            
        }
        
        return mat;
    }
};
