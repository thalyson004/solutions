class Solution {
public:
    
    bool check(vector<vector<char>> &grid, char op){
        for(int i = 0; i < 3; i++){
            int flag = 1;
            for(int j = 0; flag and j < 3; j++){
                flag = flag and (grid[i][j]==op);
            }
            if(flag) return true;
        }
        
        for(int i = 0; i < 3; i++){
            int flag = 1;
            for(int j = 0; flag and j < 3; j++){
                flag = flag and (grid[j][i]==op);
            }
            if(flag) return true;
        }
        //Main Diagonal
        {
            int flag = 1;
            for(int j = 0; flag and j < 3; j++){
                flag = flag and (grid[j][j]==op);
            }
            if(flag) return true;
        }
        //Cross Diagonal
        {
            int flag = 1;
            for(int j = 0; flag and j < 3; j++){
                flag = flag and (grid[j][2-j]==op);
            }
            if(flag) return true;
        }
        
        
        
        return false;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3, vector<char>(3, ' '));
        char op = 'X';
        
        for(auto pos: moves){
            grid[pos[0]][pos[1]] = op;
            op = (op=='X'?'O':'X');
        }
        
        if(check(grid, 'X')) return "A";
        if(check(grid, 'O')) return "B";
        if(moves.size()!=9) return "Pending";
        return "Draw";
    }
};
