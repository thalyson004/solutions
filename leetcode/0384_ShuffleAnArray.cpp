class Solution {
public:
    vector<int> solution;
    vector<int> actual;
    
    Solution(vector<int>& nums) {
        actual = solution = nums;    
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return actual = solution;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int &value:actual){
            int pos = rand()%actual.size();
            swap(value, actual[pos]);
        }
        return actual;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
