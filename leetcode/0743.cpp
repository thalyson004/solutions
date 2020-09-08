class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        K--;
        vector< vector< pair<int,int> > > G(N);
        for(auto edge:times){
            int v = edge[0]-1;
            int u = edge[1]-1;
            int w = edge[2];
            
            G[ v ].push_back( {u,w} );
        }
        
        priority_queue< pair<int,int> > f;
        
        const int oo = 100*100*5;
        vector<int> dist(N, oo);
        dist[K] = 0;
        
        int taget = 0;
        int ans = -1;
        
        f.push( {0,K} );
        while( f.size() ){
            int v = f.top().second;
            int d = -f.top().first;
            f.pop();
            
            if( d>dist[v] ) continue;
            taget++;
            if(taget==N){
                ans = d;
                break;
            }
            
            for(pair<int,int> edge:G[v]){
                int u = edge.first;
                int nw = edge.second;
                
                if( dist[u] > dist[v]+nw ){
                    dist[u] = dist[v]+nw;
                    f.push( {-dist[u], u} );
                }
            }
        }
        return ans;
        
    }
};
