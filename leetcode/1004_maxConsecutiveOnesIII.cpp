class Solution {
public:
    bool can(int q, int m, int n){
        if(n) return true;
        return q<m;
    }
    
    int longestOnes(vector<int>& A, int K) {
        int i=0, j = 0, ans = 0, zero=0;
        
        while(i < A.size()){
            while(j<A.size() and can(zero,K,A[j]) ){
                zero += !A[j];
                j++;
                ans = max(ans, j-i);
            }
            zero -= !A[i];
            i++;
        }
        
        return ans;
    }   
};
