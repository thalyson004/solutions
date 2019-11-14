class Solution {
public:
    vector<int> getMax(vector<int>& v){
        int sum = v[0];
        vector<int> ans;
        ans.push_back( sum );
        
        for(int i = 1; i < v.size(); i++){
            if(sum<0) sum = 0;
            sum+=v[i];
            ans.push_back( sum );
        }
        return ans;
    }
    
    int maximumSum(vector<int>& arr) {
        vector<int> pre,pos;
        
        pre = getMax( arr );
        reverse( arr.begin(), arr.end() );
        pos = getMax( arr );
        reverse( pos.begin(), pos.end() );
        
        int ans = -10004;
        for(int c: pos) ans = max(ans, c);
        for(int i = 1; i+1 < pre.size(); i++){
            ans = max(ans, pre[i-1]+pos[i+1]);
        }
        return ans;
    }
};
