class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        auto isSymmetric = [](int number){
            vector<int> algs;
            while(number){
                algs.push_back( (number%10) );
                number /= 10;
            }
            int s = algs.size();
            if(s%2) return false;
            
            return accumulate(algs.begin(), algs.begin()+s/2, 0) ==
            accumulate(algs.begin()+s/2, algs.end(), 0);
        };

        for(int i = low; i <= high; i++)
            ans += isSymmetric(i);

        return ans;
    }
};
