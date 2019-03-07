class Solution {
    int sum(int n){
        int ans = 0;
        while(n){
            ans += (n%10)*(n%10);
            n /= 10;
        }
        return ans;
    }
public:    
    bool isHappy(int n) {
        unordered_map <int,bool> count;
        while( !count.count(n) ){
            count[n]=1;
            n = sum(n);
        }
        return n==1;
    }
};
