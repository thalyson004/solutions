class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> out( N+1 ), in(N+1); 
        for(auto dupla : trust){
            out[ dupla[0] ]++;
            in[ dupla[1] ]++;
        }
        for(int i = 1; i<=N;i++){
            if( in[i]==N-1 and out[i]==0  )
                return i;
        }
        return -1;
    }
};
