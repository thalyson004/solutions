class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 and __builtin_popcount(n)==1;
    }
};
