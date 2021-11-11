class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        
        vector<vector<char>> matrix(numRows);
        
        int d = 1;
        int i = 0;
        for(char &letter: s){
            matrix[i].push_back(letter);
            if(i+d<0 or i+d>=numRows) d = -d;
            i += d;
        }
        
        string ans = "";
        for(vector<char> &row: matrix){
            for(char &letter: row){
                ans += letter;
            }
        }
        
        return ans;
    }
};
