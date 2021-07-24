class Solution {
public:
    void dfs(string word, vector<string> &cur, map<string, vector<string>> &prev, vector<vector<string>> &ans){
        if(prev.count(word)==0){
            reverse(cur.begin(), cur.end());
            ans.push_back(cur);
            reverse(cur.begin(), cur.end());
            return;
        }    
        
        for(string nextWord:prev[word]){
            cur.push_back(nextWord);
            dfs(nextWord, cur, prev, ans);
            cur.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return {{beginWord}};
        
        map<string, int> dist;
        map<string, vector<string>> prev;
        
        for(string word: wordList) dist[word] = -1;
        dist[beginWord] = 0;
        
        if(dist.count(endWord)==0) return {};
        
        
        queue<string> bfs;
        bfs.push( beginWord );
        
        while(bfs.size()){
            string word = bfs.front();
            string curWord = word;
            bfs.pop();
            
            for(int pos = 0; pos < word.size(); pos++){
                char prevLetter = word[pos];
                for(char letter = 'a'; letter <= 'z'; letter++){
                    word[pos] = letter;
                    
                    if(dist.count(word)){
                        if(dist[word]==-1){
                            dist[word]=dist[curWord]+1;
                            prev[word]=vector<string>({curWord});
                            bfs.push(word);
                        }else if(dist[word]==dist[curWord]+1){
                            prev[word].push_back(curWord);
                        }
                    }
                }
                word[pos] = prevLetter;
            }
        }
        
        
        if( dist[endWord]==-1 ) return {};
        vector<vector<string>> ans;
        vector<string> cur = {endWord};
        dfs(endWord, cur, prev, ans);
            
        return ans;
    }
};
