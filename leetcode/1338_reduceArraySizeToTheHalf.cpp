class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> counts;
        for(int value:arr) counts[value]++;
        vector<pair<int,int>> pairs;
        for(auto it:counts){
            pairs.push_back( {it.second, it.first} );
        }
        sort(pairs.rbegin(), pairs.rend());
        int ans = 0;
        int sum = 0;
        for(auto p:pairs){
            ans++;
            sum += p.first;
            if(sum*2>=arr.size())break;
        }
        return ans;
    }
};
