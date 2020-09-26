class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        int ans = 0;
        int last = -duration;
        
        for(int t:timeSeries){
            if( last > t ){
                ans -= last-t;
            }
            ans += duration;
            last = t+duration;
        }
        return ans;
    }
};
