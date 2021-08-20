class Solution {
public:
    bool check(int rs, int re, int cs, int ce, vector<vector<char>>& board){
        set<char> nums;
        for(int i = rs; i <= re; i++){
            for(int j = cs; j <= ce; j++){
                if(board[i][j]!='.'){ 
                    if(nums.count(board[i][j])) 
                        return false;
                    nums.insert(board[i][j]);
                
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            if( !check(0, 8, i, i, board) ) return false;
            if( !check(i, i, 0, 8, board) ) return false;
        }
        
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                if( !check(i, i+2, j, j+2, board) )
                    return false;
            }
        }
        
        return true;
    }
    
};
