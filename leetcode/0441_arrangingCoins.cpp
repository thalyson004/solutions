class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 1;
        
        int left = 0;
        int right = n;
        while(left < right){
            long long mid = (1LL+left+right)/2;
            
            if(n>=(1LL + mid + mid*mid)/2){
                left = mid;
            }else{
                right = mid-1;
            }
        }
        
        return left;
    }
};
