class Solution {
public:
    int row, col, stats;
    vector<vector<int>> G;
    vector< vector< vector<int> > > dp;
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};
        
    int inside(int r,int c){
        return r<row and r>=0 and c<col and c>=0 and G[r][c]!=-1;
    }
    
    int getid(int r, int c){
        return r*col + c;
    }
    
    int getmask(int r, int c){
        return 1<<getid(r,c);
    }
    
    int solve(int r, int c, int mask){
        if(dp[r][c][mask]!=-1) return dp[r][c][mask];
        dp[r][c][mask]=0;
        
        for(int d=0; d < 4; d++){
            int nr = r+dr[d];
            int nc = c+dc[d];
            if( inside(nr,nc) and (mask&getmask(nr,nc)) ){
                dp[r][c][mask] += solve(nr, nc, mask^getmask(r,c));
            }
        }
        
        return dp[r][c][mask];
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        stats = (1<<(row*col));
        G = grid;
        dp = vector<vector<vector<int>>>(row, vector<vector<int>>(col, vector<int>(stats, -1)));
        
        int startr, startc, endr, endc, initialMask=0;
        for(int r=0; r < row; r++){
            for(int c=0; c < col; c++){
                if( grid[r][c]==1 ){
                    startr = r;
                    startc = c;
                }else if( grid[r][c]==2 ){
                    endr = r;
                    endc = c;
                }
                
                if( grid[r][c]!=-1 ){
                    initialMask |= getmask(r,c);
                }
            }
        }
        dp[startr][startc][ getmask(startr, startc) ] = 1;
        return solve(endr, endc, initialMask);
    }
};
