class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> mono;
        
        for(int i = 0; i < n; i++){
            while(mono.size() and temperatures[mono.top()] < temperatures[i]){
                ans[mono.top()] = i-mono.top();
                mono.pop();
            }
            mono.push(i);
        }
        
        return ans;
    }
};
