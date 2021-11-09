class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> count;
        
        for(string &word: words){
            int mask = 0;
            int up = 0;
            for(char letter: word){
                int value = letter-'a';
                if( !(mask&(1<<value)) ){
                    mask |= (1<<value);
                    up++;
                }
                
            }
            
            if(up<=7){
                count[mask] += 1;    
            }
        }
        
        vector<int> ans;
        for(string &puzzle: puzzles){
            int sum = 0;
            
            for(int i = 0; i < (1<<6); i++){
                int mask = (1 << (puzzle[0]-'a'));
                for(int j = 1; j < 7; j++){
                    if(i&(1<<(j-1))){
                        mask |= (1<<(puzzle[j]-'a'));
                    }
                }
                sum += count[mask];
            }
            ans.push_back(sum);
            
        }
        
        return ans;
    }
};
