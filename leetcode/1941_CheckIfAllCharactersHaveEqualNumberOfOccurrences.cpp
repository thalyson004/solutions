class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> count;
        for(char c: s) count[c]++;
        int c = count[s[0]];
        for(char letter: s) if(c!=count[letter])return false;
        return true;
    }
};
