class Solution {
public:
    char shift(char letter, int times){
        return ((letter-'a')+times)%26 + 'a';
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum = 0;
        for(int i = s.size()-1; i >= 0; i--){
            sum = (sum+shifts[i])%26;
            s[i] = shift(s[i], sum);
        }
        return s;
    }
};
