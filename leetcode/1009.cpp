class Solution {
public:
    int bitwiseComplement(int N) {
        if(!N) return 1;
        int ans = 0;
        for(int i = 0; N>0; i++){
            ans |= ( (!(1&N)) <<i);
            N /= 2;
        }
        return ans;
    }
};
