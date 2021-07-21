class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> toRight(n, n), toLeft(n, n);
        
        for(int i = n-2; i >= 0; i--) 
            if(dominoes[i]=='.')
                toLeft[i] = (dominoes[i+1]=='L' ? 1 : (toLeft[i+1]<n?toLeft[i+1]+1:n) );
        
        for(int i = 1; i < n; i++) 
            if(dominoes[i]=='.')
                toRight[i] = (dominoes[i-1]=='R' ? 1 : (toRight[i-1]<n?toRight[i-1]+1:n) );
        
        for(int i = 0; i < n; i++){
            if( toLeft[i]<toRight[i] ) dominoes[i] = 'L';
            if( toLeft[i]>toRight[i] ) dominoes[i] = 'R';
        }
        
        return dominoes;
    }
};
