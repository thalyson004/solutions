class Solution {
public:
    int reverse(int x) {
        int minus = x<0?-1:1;
        long long int X = x;
        X = X<0?-X:X;
        long long int ans = 0;
        while(X){
            ans= ans*10 + X%10;
            X/=10;
        }
        x = ans;
        return x==ans?(minus*ans):0;
    }
};
