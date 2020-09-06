class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.empty())return vector<int>();
        int len = S.size();

        int last[26];
        memset(last, -1, sizeof(last));
        
        for(int i = 0; i < len; ++i){
            last[S[i]-'a'] = i;
        }
        
        vector<int> ans;
        int l, r;
        l = r = 0;
    
        
        for(int i = 0; i<len; ++i ){
            r = max(r, last[ S[i]-'a' ]);
            if( i==r ){
                ans.push_back( r-l+1 );
                l = i+1;
            }   
        }
        
        return ans;
    }
};
