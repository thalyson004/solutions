class CombinationIterator {
public:
    
    string combination;
    int len;
    int combLen;
    int mask;
    
    CombinationIterator(string characters, int combinationLength) {
        combination = characters;
        reverse(combination.begin(), combination.end());
        len = characters.size();
        combLen = combinationLength;
        
        mask = 0;
        for(int i = 0; i < combLen; i++){
            mask |= (1<<(len-1-i));
        }
    }
    
    string next() {
        string ans = "";
        for(int i = len-1; i >= 0; i--){
            if(mask & (1<<i)){
                ans.push_back(combination[i]);
            }
        }
        
        if(mask == (1<<combLen)-1){
            mask = 0;
        }else{

            if( (mask & -mask) != 1){
                int lsb = (mask & -mask);
                mask ^= lsb;
                mask |= (lsb>>1);
            }else{

                int i = 0;
                while(mask & (1<<i)){
                    mask ^= (1<<i);
                    i++;
                }
                int lsb = (mask & -mask);
                mask ^= lsb;
                while(i>=0){
                    lsb = lsb>>1;
                    mask |= lsb;
                    i--;
                }
            }
        }
        
        return ans;
    }
    
    bool hasNext() {
      return mask;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
