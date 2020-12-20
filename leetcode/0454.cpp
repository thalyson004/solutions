class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size();
        unordered_map<int,int> countAB;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                countAB[A[i]+B[j]]++;
            }
        }
        int ans=0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ans += countAB[ -(C[i]+D[j]) ];
            }
        }
        return ans;
    }
};
