class Solution {
public:
    int n;
    vector<vector<int>> G;
    
    vector<int> distance(int v){
        vector<int> dist(n, n);
        dist[v]=0;
        queue<int> bfs;
        bfs.push(v);
        while(bfs.size()){
            v = bfs.front();
            bfs.pop();
            
            for(int u:G[v]){
                if(dist[u]==n){
                    dist[u]=dist[v]+1;
                    bfs.push(u);
                    
                }
            }
        }
        return dist;
    }
    int findLongest(int v){
        vector<int> dist = distance(v);
        for(int i = 0; i <n; i++){
            if(dist[v] < dist[i])
                v = i;
        }
        return v;
    }
    vector<int> getPath(int first, int last){
        vector<int> father(n, -1);
        queue<int> bfs;
        bfs.push(first);
        while(bfs.size()){
            int v = bfs.front();
            bfs.pop();
            for(int u:G[v]){
                if(u!=first and father[u]==-1){
                    father[u]=v;
                    bfs.push(u); 
                }
            }
        }
        vector<int> path;
        while(last!=-1){
            path.push_back(last);
            last = father[last];
        }
        return path;
    }
    vector<int> getCenter(){
        int v = findLongest(0);
        int u = findLongest(v);

        vector<int> path = getPath(v,u);
        for(int v:path){
        }
        vector<int> ans;
        ans.push_back(path[ path.size()/2 ]);
        if(path.size()%2==0){
           ans.push_back( path[ (path.size()/2) - 1 ] );
        }
        return ans;
        
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) return vector<int>();
        this->n = n;
        G.clear();
        G.resize(n);
        for(vector<int> &ed:edges){
            int v = ed[0];
            int u = ed[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        return getCenter();
    }
};
