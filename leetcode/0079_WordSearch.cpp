class Solution {
public:
    int n;
    int m;
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    bool dfs(int i, int j, int id, string &word, vector<vector<char>>& board){
        if( i<0 or j<0 or i>=n or j>=m ) return false;
        if(board[i][j]!=word[id]) return false;
        id++;
        if(id==word.size()) return true;
        
        board[i][j] = -board[i][j];
        for(int d=0; d<4; d++){
            int ii = i+dx[d];
            int jj = j+dy[d];
            
            if( dfs(ii,jj,id,word,board) ) return true;
        }
        board[i][j] = -board[i][j];
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                if( dfs(i, j, 0, word, board) )
                    return true;
            }
        }
        
        return false;
    }
};
