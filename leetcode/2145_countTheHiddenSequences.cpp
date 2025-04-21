class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mn = 0;
        long long mx = 0;
        long long sm = 0;

        for(int i = 0; i < differences.size(); i++){
            sm += differences[i];
            mn = min(mn, sm);
            mx = max(mx, sm);
        }

        return max( (upper-lower)-(mx-mn)+1, 0LL);
    }
};
