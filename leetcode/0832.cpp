class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(vector<int> &row:A){
            int left = 0;
            int right = row.size()-1;
            while(left<right){
                if(row[left]==row[right]){
                    row[left] = row[right] = !row[left];
                }
                left++;
                right--;
            }
            if(left==right){
                row[left] ^= 1;
            }
            
        }   
        return A;
    }
};
