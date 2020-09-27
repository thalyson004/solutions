class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int id=0;
        vector< vector< pair<int,double> > > G;
        map< string, int > mapId; 
        
        for(int i = 0; i < equations.size(); i++){
            vector<string> p = equations[i];
            string sv = p[0];
            int v;
            if( mapId.count( sv )!=0 ){
                v = mapId[sv];
            }else{
                v = mapId[sv] = id++;
                G.push_back( vector< pair<int,double> >() );
            }
            
            string su = p[1];
            int u;
            if( mapId.count( su )!=0 ){
                u = mapId[su];
            }else{
                u = mapId[su] = id++;
                G.push_back( vector< pair<int,double> >() );
            }
            
            G[v].push_back( {u, values[i]} );
            G[u].push_back( {v, 1.0/values[i]} );
        }
        
        vector< vector<double> > ans( id, vector<double>(id, -1) );
        for(int v = 0; v < id; v++){
            queue< int > bfs;
            bfs.push(v);
            ans[v][v] = 1;
            
            while( bfs.size() ){
                int cur = bfs.front();
                bfs.pop();
                
                for(auto edge:G[cur]){
                    int u = edge.first;
                    double cost = edge.second;
                    if( ans[v][u]==-1 ){
                        ans[v][u] = ans[v][cur]*cost;
                        bfs.push( u );
                    }
                }
            }
                
        }

        vector<double> output;
        for(int i = 0; i < queries.size(); i++){
            vector<string> p = queries[i];
            string sv = p[0];
            string su = p[1];
  
            if( mapId.count(sv) and mapId.count(su) ){
                output.push_back( ans[ mapId[sv] ][ mapId[su] ] );    
            }else{
                output.push_back( -1.0 );
            }
            
            

        }
        return output;
    }
};
