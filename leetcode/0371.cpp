class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0, in=0;
        for(int i = 0; i < 32; i++){
            int ba = !!(a & (1<<i));
            int bb = !!(b & (1<<i));
            ans |= ((ba^bb^in) << i);
            if(ba+bb+in>1){
                in = 1;
            }else{
                in = 0;
            }
        }
        return ans;
    }
};
