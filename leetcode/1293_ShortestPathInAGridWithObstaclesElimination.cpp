class Solution {
public:
    struct position{
      int r,c,k;  
    };
    
    int shortestPath(vector<vector<int>>& grid, int K) {
        int N = grid.size();
        int M = grid[0].size();
        
        int dist[N][M][K+1];
        int dc[4] = {0,0,1,-1};
        int dr[4] = {1,-1,0,0};
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k <= K; k++)
                    dist[i][j][k]=-1;
        
        queue< position > bfs;
        bfs.push( {0,0,0} );
        dist[0][0][0] = 0;
        
        while(bfs.size()){
            int r = bfs.front().r;
            int c = bfs.front().c;
            int k = bfs.front().k;
            int cost = dist[r][c][k];
            bfs.pop();
            
            
            
            for(int d = 0; d < 4; d++){
                int nr = r+dr[d];
                int nc = c+dc[d];
                
                if( nr<N and nc<M and nr>=0 and nc>=0){
                    if( dist[nr][nc][k]==-1 and grid[nr][nc]==0 ){
                        dist[nr][nc][k] = cost+1;
                        bfs.push({nr,nc,k});
                    }
                    if( k+1<=K and dist[nr][nc][k+1]==-1 and grid[nr][nc]==1 ){
                        dist[nr][nc][k+1] = cost+1;
                        bfs.push({nr,nc,k+1});
                    }
                }
            }
        }
        
        int ans = N*M*K;
        for(int i = 0; i <= K; i++){
            if(dist[N-1][M-1][i]!= -1){
                ans = min(ans, dist[N-1][M-1][i]);
            }
        }
        if(ans == N*M*K) return -1;
        else return ans;
    }
};
