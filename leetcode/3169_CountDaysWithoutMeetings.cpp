class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int,int> count;
        int ans = 0;



        for( vector<int> meet : meetings){
            int start = meet[0];
            int end = meet[1];
            count[start]++;
            count[end+1]--;
        }

        int last = 1;
        int total = 0;
        for(auto [day, value] : count){
            if(!total) ans += day-last;

            total += value;
            last = day;
        }
        if(last <= days) ans += days - last + 1;

        return ans;
        
    }
};
