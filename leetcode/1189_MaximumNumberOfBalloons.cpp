class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<pair<char, int>> in_target = {{'b', 1},{'a', 1},{'l', 2},{'o', 2},{'n', 1}};
        map<char, int> count;
        for(char letter: text)count[letter]++;
        int ans = INT_MAX;
        for(pair<char, int> cur: in_target){
            ans = min(ans, count[cur.first]/cur.second);
        }
        return ans;
        
    }
};
