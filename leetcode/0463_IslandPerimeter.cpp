class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    ans += (i-1<0 or !grid[i-1][j]);
                    ans += (j-1<0 or !grid[i][j-1]);
                    ans += (i+1>=grid.size() or !grid[i+1][j]);
                    ans += (j+1>= grid[0].size() or !grid[i][j+1]);
                }
            }
        }
        return ans;
    }
};
