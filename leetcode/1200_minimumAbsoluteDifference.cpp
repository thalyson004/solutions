class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector< vector<int > > resposta;
        vector< int > par(2);
        
        sort( arr.begin(), arr.end() );
        
        int menor=1000005;
        
        for(int i = 1; i < arr.size(); i++){
            menor = min(menor, arr[i]-arr[i-1] );
        }
        
        for(int i = 1; i < arr.size(); i++){
            if( arr[i]-arr[i-1] == menor ){
                par[0] = arr[i-1];
                par[1] = arr[i];
                resposta.push_back( par ); 
            }
        }
        return resposta;
        
    }
};
