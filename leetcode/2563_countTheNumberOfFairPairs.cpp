class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        //compress
        int id = 1;
        unordered_map<int,int> mapa;
        vector<int> temp = nums;
        for(int i = temp.size()-1; i >= 0; i--){
            int value = temp[i];
            temp.push_back(lower-value);
            temp.push_back(upper-value+1);
        }
        sort(temp.begin(), temp.end());

        for(int &value: temp){
            if(mapa.count(value) == 0){
                mapa[value] = id++;
            }
        }

        //feenwick
        vector<int> feen(mapa.size() +5);
        auto add = [&feen](int i){
            while(i){
                feen[i]++;
                i -= (i & -i);
            }
        };
        auto get = [&feen](int i){
            long long ans = 0;
            while(i < feen.size()){
                ans += feen[i];
                i += (i & -i);
            }
            return ans;
        };

        for(int value: nums) add(mapa[value]);

        // Calc
        long long ans = 0;
        for(int value:nums){
            long long a = lower-value;
            long long b = upper-value+1;
            long long cc = get(mapa[a]) - get(mapa[b]);

            if(lower-value <= value and !(upper-value < value )) cc--;
            ans += cc;
        }

        return ans/2LL;

    }
};
