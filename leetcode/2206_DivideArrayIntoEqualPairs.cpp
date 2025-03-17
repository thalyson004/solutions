class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int odd = 0;
        unordered_set<int> present;

        for(int num : nums){
            if(present.find(num) != present.end()){
                odd++;
                present.erase(num);
            }else{
                odd--;
                present.insert(num);
            }
        }
        return odd == 0;
    }
};
