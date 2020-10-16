class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 or matrix[0].size()==0) return false;
        if(matrix[0][0]>target) return false;
        int len = matrix[0].size();
        
        int l = 0, r = -1+matrix.size()*matrix[0].size();
        while(l<r){
            int m = (l+r)/2;
            if( matrix[m/len][m%len]<target ) l=m+1;
            else if(matrix[m/len][m%len]>target) r = m;
            else return true;
        }

        return matrix[l/len][l%len]==target;
    }
};
