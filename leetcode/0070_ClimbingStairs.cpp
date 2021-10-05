class Solution {
public:
    int climbStairs(int n) {
        vector<int> fib = {0,1};
        while(fib.size()<=n+1){
            fib.push_back( fib[fib.size()-2] + fib.back() );
        }
        return fib.back();
    }
};
