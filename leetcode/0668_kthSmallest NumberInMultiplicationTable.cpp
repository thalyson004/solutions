class Solution {
public:
    int allLess(int base, int mx, int target){
        int ans = min(target/base, mx);
        if(ans*base==target) ans--;
        return ans;
    }
    
    int findKthNumber(int m, int n, int k) {
        if(m>n) swap(m,n);
        
        int left = 1;
        int right = m*n;
        
        while(left < right){
            int mid = (left+right+1)/2;
            
            int sum = 0;
            for(int i = 1; i <= m; i++){
                sum += allLess(i, n, mid);
            }
            
            if(sum < k) left = mid;
            else right = mid-1;
        }
        
        return left;
    }
};
