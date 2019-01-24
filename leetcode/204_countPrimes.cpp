class Solution {
public:
    int countPrimes(int n) {
        if(n<=0)return 0;
        bool is[n];
        fill(is, is+n, true);
        int ans = 0;
        for(int i = 2; i < n; i++){
            if( is[i] ){
                ans++;
                for(int j = i+i; j < n; j+=i)
                    is[j] = 0;
            }
        }
        return ans;
    }
};
