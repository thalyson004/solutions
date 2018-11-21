class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<short,short> mapa;
        for(int i=0; i < nums.size(); i++){
            int n = nums[i];
            if( mapa.count(target-n) ){
                return {mapa[target-n], i};
            }
            mapa[ n ] = i;
        }
        
    }
};