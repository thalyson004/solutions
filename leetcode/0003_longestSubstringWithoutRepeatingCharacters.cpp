class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        vector<int> v = vector<int>(252);
        int repeat = 0;
        int i=0, j = 0;
        while(i < s.size() ){
            while(i<s.size() and !repeat){
                v[ s[i] ]++;
                repeat += (v[s[i]]>1);
                i++;
            }
            ans = max(ans, i-j-repeat);
            while(j<i and repeat){
                v[ s[j] ]--;
                repeat -= (v[s[j]]==1);
                j++;
            }
        }
        return ans;
    }
};
