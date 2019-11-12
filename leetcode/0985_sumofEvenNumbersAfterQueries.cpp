class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for(int c:A){
            sum += (c%2==0)*c;
        }
        
        for(int i = 0; i < queries.size(); i++){
            sum -= A[ queries[i][1] ]*( A[ queries[i][1] ]%2==0 );
            A[ queries[i][1] ] += queries[i][0];
            sum += A[ queries[i][1] ]*( A[ queries[i][1] ]%2==0 );
            ans.push_back( sum );
        }
        return ans;
    }
};
