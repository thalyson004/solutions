class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int number = x^y;
        
        for(int i = 0; i < 32; i++){
            ans += !!(number & (1<<i));
        }
        
        return ans;
    }
};
