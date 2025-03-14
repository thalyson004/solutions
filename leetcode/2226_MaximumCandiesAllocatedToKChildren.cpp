class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 0, r = (1LL << 50);

        auto check = [&](int value){
            if(!value) return true;
            long long ok = 0;

            for(int quantity : candies){
                ok += quantity/value;
                if(ok >= k)
                    return true;
            }
            return false;
        };

        while(l < r){
            long long m = (l+r+1)/2;

            if(check(m)){
                l = m;
            }else{
                r = m-1;
            }
        }

        return l;
    }
};
