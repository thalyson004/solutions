class Solution {
public:
    string morse(string word){
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string ans = "";
        for(char letter:word){
            ans = ans + morse[letter-'a'];
        }
        return ans;
        
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> uniques;
        for(string word:words) uniques.insert( morse(word) );
        return uniques.size();
    }
};
