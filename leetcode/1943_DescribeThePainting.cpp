class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> change(100005);
        
        for(auto paint: segments){
            change[paint[0]].push_back(paint[2]);
            
            change[paint[1]].push_back(-paint[2]);
        }
        
        long long start = -1;
        long long sum = 0;
        vector<vector<long long>> ans;
        for(int i = 1; i <=100000; i++){
            long long c = 0;
            long long cur = 0;
            map<long long,long long> count;
            
            for(long long value: change[i]){
                sum+=value;
                cur += value;
                if(value>0) count[value]++;
                else count[-value]--;
            }
            for(auto el:count)
                if(el.second)
                    c = 1;
            
            if(c){
                if(start<0) start = i;
                else {
                    ans.push_back( {start, i, sum-cur} );
                    start = i;
                    if(sum==0) start = -1;
                }
            }
        }
        return ans;
        // [[1,4,12],[4,7,12]]
    }
};
