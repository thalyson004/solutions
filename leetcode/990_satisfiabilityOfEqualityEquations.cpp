class Solution {
public:
    
    void dfs(int id, vector<vector<int> > &G, vector<int> &color, int c){
        if(color[id]) return;
        color[id] = c;
        for( int u : G[id] )
            dfs(u, G, color, c);
        
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector< vector<int> > G(30);
        vector< int > color( 30, 0 );
        
        for(string eq : equations){
            if( eq[1]=='='){
                G[ eq[0]-'a' ].push_back( eq[3]-'a' );
                G[ eq[3]-'a' ].push_back( eq[0]-'a' );
            }
        }
        
        for(int i = 0; i < 30; i++){
            if(!color[i]){
                dfs( i, G, color, i+1 );
            }
        }
        
        for(string eq : equations){
            if( eq[1]=='!'){
                if(color[eq[0]-'a' ] == color[eq[3]-'a'] )
                    return false;    
            }
        }
        return true;
    }
};
