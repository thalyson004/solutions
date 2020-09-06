class Solution {
public:
    
    int overlap(vector<vector<int>>& A, vector<vector<int>>& B, int l, int c){
        int sum = 0;
        for(int i = l; i < A.size(); i++){
            for(int j = c; j < A[0].size(); j++){
                sum += A[i][j]*B[i-l][j-c];
            }
        }
        return sum;
    } 
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ans = 0;
        
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[0].size(); j++){
                ans = max(ans, overlap(A, B, i,j));
                ans = max(ans, overlap(B, A, i,j));
            }
        }
        
        return ans;
    }
    
};
