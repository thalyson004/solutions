class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> mn;

        for(int k: nums){
            bool put = false;
            for(int &i:mn){
                if(k<=i){
                    i=k;
                    put=true;
                    break;
                }
            }

            if(put==false) mn.push_back(k);
            if(mn.size()==3) return true;
        }

        return false;
    }
};
