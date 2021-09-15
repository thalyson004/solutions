class Solution {
public:

    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        int n = arr.size();
        
        //Less
        int start = 0;
        for(int end = 1; end < n; end++){
            if( ((end-start)%2==1 and !(arr[end-1]>arr[end])) or
                ((end-start)%2==0 and !(arr[end-1]<arr[end]))) {
                    start = end - (arr[end-1]>arr[end]);
            }
            ans = max(ans, end-start+1);
        }
        
        // Greater
        start = 0;
        for(int end = 1; end < n; end++){
            if( ((end-start)%2==1 and !(arr[end-1]<arr[end])) or
                ((end-start)%2==0 and !(arr[end-1]>arr[end]))) {
                    start = end - (arr[end-1]<arr[end]);
            }
            ans = max(ans, end-start+1);
        }
        
        return ans;
    }
};
