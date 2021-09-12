class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        
        vector<vector<pair<int,int>>> G(n);
        for(auto edge: edges){
            G[edge[0]].push_back( {edge[1], edge[2]+1} );
            G[edge[1]].push_back( {edge[0], edge[2]+1} );
        }
        
        vector<int> dist(n, INT_MAX);
        priority_queue< pair<int,int> > dj;
        dj.push( {0,0} );
        dist[0] = 0;
        int ans = 0;
        while(dj.size()){
            int u = dj.top().second;       
            int total = -dj.top().first;
            
            dj.pop();
            if(total != dist[u]) continue;
            ans++;
            
            for(auto edge: G[u]){
                int v = edge.first;
                int cost = edge.second;
                
                if(total+cost<dist[v] and total+cost<=maxMoves){
                    dist[v] = total+cost;
                    dj.push( {-dist[v], v} );
                }
            }
        }
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int between = edge[2];
            
            if(dist[u]==INT_MAX and dist[v]==INT_MAX) continue;
            else if(dist[u]==INT_MAX) ans += maxMoves-dist[v];
            else if(dist[v]==INT_MAX) ans += maxMoves-dist[u];
            else{
                ans += min(2*maxMoves-dist[v]-dist[u], between);
            }
        }
        
        return ans;
    }
};
