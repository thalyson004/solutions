class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        
        for(int number: nums) x ^= number;
        
        int bitDif;
        for(int i = 0; i < 32; i++){
            if(x&(1<<i)){
                bitDif = i;
                break;
            }
        }
        
        int first = 0;
        for(int number: nums){
            if(number&(1<<bitDif)){
                first ^= number;
            }
        }
        int second = x^first;
        
        return vector<int>({first, second});
    }
};
