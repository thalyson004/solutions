class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1LL << 60;

        auto check = [&](long long mn){
            long long total = 0;

            for(int rank: ranks){
                total += sqrt((mn/rank) + 0.5);
            }

            return total >= cars;
        };
        
        while(l < r){
            long long m = (l+r)/2LL;

            if(check(m)){
                r = m;
            }else{
                l = m+1;
            }
        }

        return l;
    }
};
