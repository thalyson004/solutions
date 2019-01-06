class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num>1 && num%4==0) num/=4;
        return num==1; 
    }
};
