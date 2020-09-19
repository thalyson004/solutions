class Solution {
public:
    
    vector<int> sequentials(int low, int high){
        vector<int> ans;
        for(int i = 2; i <= 9; i++){
            for(int j = 1; j <= 9-i+1; j++){
                int n = j;
                for(int w = 1; w<i; w++ ){
                    n = n*10 + (j+w);
                }
                if(n >= low and n <= high)
                    ans.push_back(n);
            }
        }
        return ans;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> seqs = sequentials(low, high); 
        return seqs;
    }
};
