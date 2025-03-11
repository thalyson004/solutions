class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> count;
        int ans = 0;
        int last = 0;
        for(int i = 0; i < s.size(); i++){
            while(last < s.size() and 
                (!!count['a'] + !!count['b'] +  !!count['c']) < 3){
                    count[s[last++]]+= 1;
                }

            if((!!count['a'] + !!count['b'] +  !!count['c']) == 3){
                ans += (s.size()-last+1);
            }
            count[s[i]] -= 1;
        }
        return ans;
    }
};
